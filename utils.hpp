/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:33:28 by pcunha            #+#    #+#             */
/*   Updated: 2022/03/07 22:39:47 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

template <typename T>
void	print_vector(T& vector_to_print)
{
	int i;

	std::cout << "-----------------------------------" << std::endl;
	for (i = 0; i < (int) vector_to_print.size(); i++)
	{
		std::cout << "|" << vector_to_print[i];
	}
	std::cout << "|";
	std::cout << std::endl;
	std::cout << "size: " << vector_to_print.size();
	std::cout << "\t\t";
	std::cout << "capacity: " << vector_to_print.capacity() << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}

template <typename P>
void print_pair(P &p)
{
	std::cout << "f: " << p.first << "\t\t s: " << p.second << std::endl;
};

#endif

