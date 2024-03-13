/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:59:56 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/13 09:00:59 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall()
: ATarget("Inconspicuous Red-brick Wall")
{
}

BrickWall::~BrickWall()
{
}

BrickWall* BrickWall::clone() const
{
	return (new BrickWall());
}
