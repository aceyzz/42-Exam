/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:21:15 by cedmulle          #+#    #+#             */
/*   Updated: 2024/03/13 09:31:33 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::TargetGenerator(const TargetGenerator &src)
{
	(void)src;
}

TargetGenerator& TargetGenerator::operator=(const TargetGenerator &src)
{
	(void)src;
	return (*this);
}

TargetGenerator::~TargetGenerator()
{
	for (std::map<std::string, ATarget*>::iterator it = _list.begin(); it != _list.end(); it++)
		delete it->second;
	_list.clear();
}

void	TargetGenerator::learnTargetType(ATarget *target)
{
	if (_list.find(target->getType()) == _list.end())
		_list[target->getType()] = target->clone();
}

void	TargetGenerator::forgetTargetType(const std::string &targettype)
{
	for (std::map<std::string, ATarget*>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		if (it->first == targettype)
			delete it->second;
	}
}

ATarget*	TargetGenerator::createTarget(const std::string &targettype)
{
	if (_list.find(targettype) != _list.end())
		return (_list[targettype]->clone());
	return (NULL);
}
