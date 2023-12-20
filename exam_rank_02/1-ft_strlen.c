/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-ft_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:16:22 by cedmulle          #+#    #+#             */
/*   Updated: 2023/12/20 16:05:00 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);

*/

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}