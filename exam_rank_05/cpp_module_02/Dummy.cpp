/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:43:46 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/13 08:44:33 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy()
: ATarget("Target Practice Dummy")
{
}

Dummy::~Dummy()
{
}

Dummy* Dummy::clone() const
{
	return (new Dummy());
}
