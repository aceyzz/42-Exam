/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:54:57 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/30 08:56:06 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>

void	ft_error(char *str, char *arg);
void	ft_execute(char **argv, int i, int tmp_fd, char **env);

#endif
