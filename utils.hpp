/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:33:28 by pcunha            #+#    #+#             */
/*   Updated: 2022/04/03 21:10:47 by pcunha           ###   ########.fr       */
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

template <typename N>
void print_node(N &node)
{
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
	std::cout << "parent:\t" << node.parent << std::endl;
	std::cout << "node:  \t" << &node << std::endl;
	std::cout << "Content:\t"; print_pair(*(node.content));
	std::cout << "color:\t\t" << node.color << std::endl;
	std::cout << "left:\t\t" << node.left << "\tright:\t" << node.right << std::endl;

	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
};

template<typename K,typename Val>
void print_map(ft::map<K,Val> &m)
{
	typename ft::map<K,Val>::iterator i;
	i = m.begin();
	while (i != m.end())
	{
		std::cout << "(" << i->first << "," << i->second << ")\n";
		i++;
	};
	std::cout << std::endl;
};

template<typename T>
void print_tree_by_level(rbt_node<T> *n)
{
	std::cout << "Print Tree Level: \n";

	ft::vector<rbt_node<T> >					q;
	rbt_node<T>									*nn;
	ft::vector<int>								lvl;
	size_t										i;

	i = 0;
	q.push_back(*n);
	lvl.push_back(1);
	while (i < q.size())
	{
		nn = (q[i].left);
		if (nn != NULL)
		{
			q.push_back(*nn);
			lvl.push_back(lvl[i] + 1);
		};
		nn = (q[i].right);
		if (nn != NULL)
		{
			q.push_back(*nn);
			lvl.push_back(lvl[i] + 1);
		};
		i++;
	};
	i = 0;
	std::cout << (q[i]).content->first << " ";
	i++;
	while (i < q.size())
	{
		if (lvl[i] != lvl[i-1]) std::cout << std::endl;
		std::cout << (q[i]).content->first << " ";
		i++;
	};
	std::cout << "\n-----------------\n";
};

template<typename T>
void print_tree_by_level_color(rbt_node<T> *n, rbt_node<T> *nil)
{
	std::cout << "Print Tree Level: \n";

	ft::vector<rbt_node<T> >					q;
	rbt_node<T>									*nn;
	ft::vector<int>								lvl;

	typename ft::map<int, int>::size_type						i;
//	size_t										i;
//	typename ft::vector<rbt_node<T> >::size_type					i;

	i = 0;
	q.push_back(*n);
	lvl.push_back(1);
	while (i < q.size())
	{
		nn = (q[i].left);
		if (nn != nil)
		{
			q.push_back(*nn);
			lvl.push_back(lvl[i] + 1);
		};
		nn = (q[i].right);
		if (nn != nil)
		{
			q.push_back(*nn);
			lvl.push_back(lvl[i] + 1);
		};
		i++;
	};
	i = 0;
	print_node_in_a_line(q[i], lvl[i], nil);
	i++;
	while (i < q.size())
	{
		if (lvl[i] != lvl[i-1]) std::cout << std::endl;
		print_node_in_a_line(q[i], lvl[i], nil);
		i++;
	};
	std::cout << "\n-----------------\n";
};

template <typename T>
void print_node_in_a_line(rbt_node<T> q, int lvl, rbt_node<T> *nil)
{
	if (&q == nil)
		return;

	if (q.color == 0)
		std::cout << C_RED << "[" << q.content->first << "]" << RESET;
	else
		std::cout << "[" << q.content->first << "]";
	if (q.parent)
		std::cout << "\t\t p: " << (q.parent)->content->first;
	else
		std::cout << "\t\t root";
	std::cout << "\t\tlvl: " << lvl;
	std::cout << std::endl;
};

#endif
