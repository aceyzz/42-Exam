/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:16:09 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/13 08:47:03 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class	Warlock
{
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;
		void setTitle(const std::string &title);
		void introduce() const;

		void learnSpell(ASpell *Spell);
		void forgetSpell(std::string spellname);
		void launchSpell(std::string spellname, const ATarget &target);
	
	private:
		std::string _name;
		std::string _title;
		std::map<std::string, ASpell*>	_SpellBook;

		Warlock();
		Warlock(const Warlock &src);
		Warlock& operator=(const Warlock &src);
};
