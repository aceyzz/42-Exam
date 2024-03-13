/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:25:11 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/13 08:36:26 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class	ATarget;

class	ASpell
{
	public:
		ASpell();
		ASpell(const std::string &name, const std::string &effects);
		ASpell(const ASpell &src);
		ASpell& operator=(const ASpell &src);
		virtual ~ASpell();

		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell* clone() const = 0;

		void launch(const ATarget &target) const;

	protected:
		std::string _name;
		std::string _effects;
};
