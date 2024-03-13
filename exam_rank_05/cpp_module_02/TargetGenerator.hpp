/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:18:24 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/13 09:31:14 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>
#include "ATarget.hpp"

class	TargetGenerator
{
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *target);
		void forgetTargetType(const std::string &targettype);
		ATarget* createTarget(const std::string &targettype);

	private:
		std::map<std::string, ATarget*>	_list;

		TargetGenerator(const TargetGenerator &src);
		TargetGenerator& operator=(const TargetGenerator &src);
};
