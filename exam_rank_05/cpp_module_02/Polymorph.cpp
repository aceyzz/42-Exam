/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:57:47 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/13 09:29:35 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph()
: ASpell("Polymorph", "turned into a critter")
{
}

Polymorph::~Polymorph()
{
}

Polymorph* Polymorph::clone() const
{
	return (new Polymorph());
}
