/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:55:28 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/13 08:56:27 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball()
: ASpell("Fireball", "burnt to a crisp")
{
}

Fireball::~Fireball()
{
}

Fireball* Fireball::clone() const
{
	return (new Fireball());
}
