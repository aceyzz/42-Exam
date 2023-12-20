/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-union.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:05:34 by cedmulle          #+#    #+#             */
/*   Updated: 2023/12/20 16:05:43 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

*/

#include <unistd.h>

void	ft_union(char *str1, char *str2)
{
	int	tab[256] = {0};
	int	i = 0;

	while (str1[i])
	{
		if (tab[(int)str1[i]] == 0)
		{
			write(1, &str1[i], 1);
			tab[(int)str1[i]] = 1;
		}
		i++;
	}
	i = 0;
	while (str2[i])
	{
		if (tab[(int)str2[i]] == 0)
		{
			write(1, &str2[i], 1);
			tab[(int)str2[i]] = 1;
		}
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}