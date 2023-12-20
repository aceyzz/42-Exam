/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-ft_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:38:35 by cedmulle          #+#    #+#             */
/*   Updated: 2023/12/20 16:06:33 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);

*/

#include <stdlib.h>
#include <limits.h>

char *ft_itoa(int nbr) 
{
	if(nbr == INT_MIN)
		return("-2147483648\0");
	int n = nbr;
	int len = 0;

	if (nbr <= 0)
		len++;
	while (n) 
	{
		n /= 10;
		len++;
	}
	char *result = malloc(sizeof(char) * (len + 1));
	if (!result) 
		return (NULL);
	result[len] = '\0';
	if (!nbr)
	{
		result[0] = '0';
		return(result);
	}
	if (nbr < 0) 
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr) 
	{
		result[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);
}
