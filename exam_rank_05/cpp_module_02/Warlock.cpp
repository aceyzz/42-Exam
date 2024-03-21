/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:18:53 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/13 09:35:24 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock()
{
}

Warlock::Warlock(const std::string &name, const std::string &title)
: _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const Warlock &src)
{
	(void)src;
}

Warlock& Warlock::operator=(const Warlock &src)
{
	(void)src;
	return (*this);
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string& Warlock::getName() const
{
	return (_name);
}

const std::string& Warlock::getTitle() const
{
	return (_title);
}

void Warlock::setTitle(const std::string &title)
{
	_title = title;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *Spell)
{
	_SpellBook.learnSpell(Spell);
}

void Warlock::forgetSpell(std::string spellname)
{
	_SpellBook.forgetSpell(spellname);
}

void Warlock::launchSpell(std::string spellname, const ATarget &target)
{
	std::map<std::string, ASpell*> copy = _SpellBook.getBook();
	std::map<std::string, ASpell*>::iterator it = copy.find(spellname);

	if (it != copy.end())
		it->second->launch(target);
}
