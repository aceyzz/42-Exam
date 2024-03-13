/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:29:53 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/13 08:34:50 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"

class	ASpell;

class	ATarget
{
	public:
		ATarget();
		ATarget(const std::string &type);
		ATarget(const ATarget &src);
		ATarget& operator=(const ATarget &src);
		virtual ~ATarget();

		const std::string &getType() const;
		virtual ATarget* clone() const = 0;
	
		void getHitBySpell(const ASpell &spell) const;

	protected:
		std::string _type;
};
