/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_map_iterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:23:32 by pcunha            #+#    #+#             */
/*   Updated: 2022/03/22 19:35:51 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_MAP_ITERATOR_HPP
# define REVERSE_MAP_ITERATOR_HPP

#include "node.hpp"

namespace ft
{
	template <class C>
	class reverse_map_iterator
	{
		public:
		// Types
		typedef typename C::value_type						value_type;
		typedef value_type*									pointer;
		typedef value_type&									reference;
		typedef typename C::size_type						size_type;
		typedef typename C::difference_type					difference_type;
		typedef typename std::bidirectional_iterator_tag	iterator_category;
		typedef typename C::key_compare						key_compare;

		// Methods
		reverse_map_iterator () : _comp(key_compare()), _node(NULL), _prev(NULL), _content(NULL) {}; 
		reverse_map_iterator (rbt_node<value_type>* const node): _comp(key_compare()), _node(node)
		{
			if (node)
				_content = node->content;
			else
				_content = NULL;
		};
		reverse_map_iterator (reverse_map_iterator const & src) {*this = src;};

		~reverse_map_iterator () {};

		reverse_map_iterator & operator=(reverse_map_iterator const & rhs)
		{
			if (this != &rhs)
			{
				_comp = rhs._comp;
				_node = rhs._node;
				_prev = rhs._prev;
				_content = rhs._content;
			};
			return *this;
		};

		// Dereferences
		reference operator*()	const	{ return (*_node->content); };
		pointer operator->()	const	{ return  &(operator*());   };

		// Increments / decrements
		reverse_map_iterator & operator-- ()
		{
			rbt_node<value_type> *p;

			if (_node->right != NULL)	// go down
				p = min_subtree(_node->right);
			else						// or go up
			{
				p = _node;
				while (p != NULL && is_right_child(p))
					p = p->parent;
				p = p->parent;
			};
			this->_node = p;
			this->_content = p->content;
			return (*this);
		};

		reverse_map_iterator & operator++ ()
		{
			rbt_node<value_type> *p;

			if (_node->left != NULL)	// go down
				p = max_subtree(_node->left);
			else						// or go up
			{
				p = _node;
				while (p != NULL && is_left_child(p))
					p = p->parent;
				p = p->parent;
			};
			this->_node = p;
			this->_content = p->content;
			return (*this);
		};

		reverse_map_iterator operator--(int)
		{
			reverse_map_iterator tmp;

			tmp = *this;
			this->operator++();
			return (tmp);
		};

		reverse_map_iterator operator++(int)
		{
			reverse_map_iterator tmp;

			tmp = *this;
			this->operator--();
			return (tmp);
		};

		//Relational
		bool operator==(reverse_map_iterator const & x) const
		{
			if (_node == NULL && x._node == NULL)
				return (true);
			if (_node == NULL || x._node == NULL)
				return (false);
			return ( *(_node->content) == *(x._node->content));
		};
		bool operator!=(reverse_map_iterator const & x) const
		{
			return (!(*this == x));;
		};
			

		// TODO  fazer curr() e update() ??


		// Atributes
		protected:
			key_compare				_comp;
			rbt_node<value_type>*	_node;
			rbt_node<value_type>*	_prev;
			value_type*				_content;

		private:
		rbt_node<value_type> * min_subtree(rbt_node<value_type> *i)
		{
			if (i != NULL)
			{
				while ((*i).left != NULL)
					i = (*i).left;
			};
			return i;
		};

		rbt_node<value_type> * max_subtree(rbt_node<value_type> *i)
		{
			if (i != NULL)
			{
				while ((*i).right != NULL)
					i = (*i).right;
			};
			return i;
		};

		bool is_left_child(rbt_node<value_type> *i)
		{
			if ((*i).parent != NULL && (*i).parent->left == i)
				return true;
			else
				return false;
		};

		bool is_right_child(rbt_node<value_type> *i)
		{
			if ((*i).parent != NULL && (*i).parent->right == i)
				return true;
			else
				return false;
		};
	};
};
#endif
