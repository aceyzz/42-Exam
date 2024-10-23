#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_client
{
	int		id;
	char	msg[1000000];
}	t_client;

t_client	clients[2048];
fd_set		write_set, read_set, current;
int			maxfd = 0, gid = 0;
char		send_buffer[1000000], recv_buffer[1000000];

void	err(char *msg)
{
	if (msg)
		write(2, msg, strlen(msg));
	else
		write(2, "Fatal error", 11);
	write(2, "\n", 1);
	exit(1);
}

void	send_to_all(int except_fd)
{
	for (int fd = 0; fd <= maxfd; fd++)
	{
		if (FD_ISSET(fd, &write_set) && fd != except_fd)
			if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
				err(NULL);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		err("Wrong number of arguments");

	struct sockaddr_in	serveraddr;
	socklen_t			len;

	int	serverfd = socket(AF_INET, SOCK_STREAM, 0);
	if (serverfd == -1) err(NULL);
	maxfd = serverfd;

	FD_ZERO(&current);
	FD_SET(serverfd, &current);
	bzero(clients, sizeof(clients));
	bzero(&serveraddr, sizeof(serveraddr));

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(atoi(argv[1]));

	if (bind(serverfd, (const struct sockaddr *)&serveraddr, sizeof(serveraddr)) != 0
		|| listen(serverfd, 100) != 0)
		err(NULL);

	while (1)
	{
		read_set = write_set = current;
		if (select(maxfd + 1, &read_set, &write_set, 0, 0) < 0)
			err(NULL);

		for (int fd = 0; fd <= maxfd; fd++)
		{
			if (FD_ISSET(fd, &read_set))
			{
				if (fd == serverfd)
				{
					int clientfd = accept(serverfd, (struct sockaddr *)&serveraddr, &len);
					if (clientfd == -1) err(NULL);
					if (clientfd > maxfd) maxfd = clientfd;
					FD_SET(clientfd, &current);
					clients[clientfd].id = gid++;
					sprintf(send_buffer, "server: client %d just arrived\n", clients[clientfd].id);
					send_to_all(clientfd);
					bzero(send_buffer, sizeof(send_buffer));
				}
				else
				{
					int ret = recv(fd, recv_buffer, sizeof(recv_buffer), 0);
					if (ret <= 0)
					{
						sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
						send_to_all(fd);
						bzero(send_buffer, sizeof(send_buffer));
						FD_CLR(fd, &current);
						bzero(clients[fd].msg, sizeof(clients[fd].msg));
						close(fd);
					}
					else
					{
						for (int i = 0, j = strlen(clients[fd].msg); i < ret; i++, j++)
						{
							clients[fd].msg[j] = recv_buffer[i];
							if (clients[fd].msg[j] == '\n')
							{
								clients[fd].msg[j] = '\0';
								sprintf(send_buffer, "client %d: %s\n", clients[fd].id, clients[fd].msg);
								send_to_all(fd);
								bzero(send_buffer, sizeof(send_buffer));
								bzero(clients[fd].msg, sizeof(clients[fd].msg));
                                j = -1;
							}
						}
					}
				}
				break ;
			}
		}
	}
	return (0);
}
