/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:01:21 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/13 09:14:43 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class	SpellBook
{
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *Spell);
		void forgetSpell(const std::string &spellname);
		ASpell* createSpell(const std::string &spellname);

		const std::map<std::string, ASpell*>& getBook() const;
	
	private:
		std::map<std::string, ASpell*> _Book;
	
		SpellBook(const SpellBook &src);
		SpellBook& operator=(const SpellBook &src);
};
