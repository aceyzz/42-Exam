/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-paramsum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:17:57 by cedmulle          #+#    #+#             */
/*   Updated: 2023/12/20 16:06:11 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*

Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

*/

void	ft_putnbr(int nb)
{
	char	*base = "0123456789";

	if (nb >= 10)
		ft_putnbr(nb / 10);
	write(1, &base[nb % 10], 1);
	return ;
}

int	main(int argc, char **argv)
{
	(void)argv;

	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}