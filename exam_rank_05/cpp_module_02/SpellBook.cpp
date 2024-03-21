/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:03:45 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/13 09:36:33 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::SpellBook(const SpellBook &src)
{
	(void)src;
}

SpellBook& SpellBook::operator=(const SpellBook &src)
{
	(void)src;
	return (*this);
}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell*>::iterator it = _Book.begin(); it != _Book.end(); it++)
		delete it->second;
	_Book.clear();
}

void	SpellBook::learnSpell(ASpell *Spell)
{
	if (_Book.find(Spell->getName()) == _Book.end())
		_Book[Spell->getName()] = Spell->clone();
}

void	SpellBook::forgetSpell(const std::string &spellname)
{
	for (std::map<std::string, ASpell*>::iterator it = _Book.begin(); it != _Book.end(); it++)
	{
		if (it->first == spellname)
			delete it->second;
	}
}

ASpell*	SpellBook::createSpell(const std::string &spellname)
{
	for (std::map<std::string, ASpell*>::iterator it = _Book.begin(); it != _Book.end(); it++)
	{
		if (it->first == spellname)
			return(it->second->clone());
	}
	return (NULL);
}

const std::map<std::string, ASpell*>&	SpellBook::getBook() const
{
	return (_Book);
}
