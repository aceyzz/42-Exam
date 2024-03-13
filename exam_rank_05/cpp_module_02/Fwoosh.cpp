/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:41:22 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/13 08:42:27 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
: ASpell("Fwoosh", "fwooshed")
{	
}

Fwoosh::~Fwoosh()
{
}

Fwoosh* Fwoosh::clone() const
{
	return (new Fwoosh());
}
