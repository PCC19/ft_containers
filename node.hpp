/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 02:41:36 by pcunha            #+#    #+#             */
/*   Updated: 2022/04/10 21:01:12 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP
#define RED 0
#define BLACK 1

template <typename T, class Allocator = std::allocator<T> >
struct rbt_node
{
	typedef	Allocator		allocator_type;

	rbt_node(T* val = NULL): parent(NULL), left(NULL), right(NULL), color(0), content(val) ,_Alloc(allocator_type())
	{
		
	};
	
	rbt_node<T> operator=(rbt_node<T> const & rhs)
	{
		if (*this != rhs)
		{
			parent = rhs.parent;
			left = rhs.left;
			right = rhs.right;
			color = rhs.color;
			content = rhs.content;
			_Alloc = rhs._Alloc;
		};
		return (*this);
	};

	public:
	rbt_node<T>				*parent;
	rbt_node<T>				*left;
	rbt_node<T>				*right;
	int						color;
	T*						content;
	allocator_type			_Alloc;

};
#endif
