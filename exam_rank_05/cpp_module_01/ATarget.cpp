/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:31:41 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/13 08:47:10 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget()
{
}

ATarget::ATarget(const std::string &type)
: _type(type)
{
}

ATarget::ATarget(const ATarget &src)
{
	_type = src._type;
}

ATarget& ATarget::operator=(const ATarget &src)
{
	if (this != &src)
		_type = src._type;
	return (*this);
}

ATarget::~ATarget()
{
}

const std::string& ATarget::getType() const
{
	return (_type);
}

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}
