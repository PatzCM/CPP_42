/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:57:58 by palexand          #+#    #+#             */
/*   Updated: 2025/07/22 18:15:25 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
		std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "Lasagna";
}

Brain::~Brain() {
		std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
		std::cout << "Brain copy constructor called" << std::endl;
		for (int i = 0; i < 100; ++i) {
			ideas[i] = other.ideas[i];
		}
}

Brain &Brain::operator=(const Brain &other) {
		std::cout << "Brain assignment operator called" << std::endl;
		if (this != &other) {
			for (int i = 0; i < 100; ++i) {
				ideas[i] = other.ideas[i];
			}
		}
		return *this;
}

