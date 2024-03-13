/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:27:21 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/13 08:53:05 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell()
{
}

ASpell::ASpell(const std::string &name, const std::string &effects)
: _name(name), _effects(effects)
{
}

ASpell::ASpell(const ASpell &src)
{
	_name = src._name;
	_effects = src._effects;
}

ASpell& ASpell::operator=(const ASpell &src)
{
	if (this != &src)
	{
		_name = src._name;
		_effects = src._effects;
	}
	return (*this);
}

ASpell::~ASpell()
{
}

std::string ASpell::getName() const
{
	return (_name);
}

std::string ASpell::getEffects() const
{
	return (_effects);
}

void ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
}
