/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 02:41:36 by pcunha            #+#    #+#             */
/*   Updated: 2022/03/11 02:41:39 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

template <typename T>
struct rbt_node
{
	rbt_node(T* val = NULL): parent(NULL), left(NULL), right(NULL), color(RED), content(val) {};
	
	rbt_node<T> operator=(rbt_node<T> const & rhs)
	{
		if (*this != rhs)
		{
			parent = rhs.parent;
			left = rhs.left;
			right = rhs.right;
			color = rhs.color;
			content = rhs.content;
		};
		return (*this);
	};

	typedef enum {RED, BLACK}	COLORS;
	rbt_node<T>	*parent;
	rbt_node<T>	*left;
	rbt_node<T>	*right;
	COLORS		color;
	T*			content;

};
#endif
