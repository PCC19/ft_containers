/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:33:15 by pcunha            #+#    #+#             */
/*   Updated: 2022/03/20 19:23:06 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "node.hpp"

namespace ft
{
	template <class C>
	class map_iterator
	{
		public:
		// Types ok
		typedef typename C::value_type						value_type;
		typedef value_type*									pointer;
		typedef value_type&									reference;
		typedef typename C::size_type						size_type;
		typedef typename C::difference_type					difference_type;
		typedef typename std::bidirectional_iterator_tag	iterator_category;
		typedef typename C::key_compare						key_compare;

		// Methods ok
		map_iterator () : _comp(key_compare()), _node(NULL), _prev(NULL), _content(NULL) {}; 
		map_iterator (rbt_node<value_type>* const node): _comp(key_compare()), _node(node)
		{
			if (node)
				_content = node->content;
			else
				_content = NULL;
		};
		map_iterator (map_iterator const & src) {*this = src;};

		~map_iterator () {};

		map_iterator & operator=(map_iterator const & rhs)
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

		// Dereferences ok
		reference operator*()	const	{ return (*_node->content); };
		pointer operator->()	const	{ return  &(operator*());   };

		// Increments / decrements
		map_iterator & operator++ ()
		{
			rbt_node<value_type> *p;

			if (_node->right != NULL)
				p = min_subtree(_node->right);
			else
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
		map_iterator & operator-- ()
		{
			return *this;
		}
		map_iterator operator++(int)
		{
			map_iterator tmp;

			tmp = *this;
			this->operator++();
			return (tmp);
		}
		map_iterator operator--(int)
		{
			map_iterator tmp;

			tmp = *this;
			return (tmp);
		}

//		// Arithmetics:
//		map_iterator operator+(size_type n) const
//		{
//			map_iterator tmp;
//			tmp._ptr = _ptr + n;
//			return (tmp);
//		}
//		map_iterator operator-(size_type n) const
//		{
//			map_iterator tmp;
//			tmp._ptr = _ptr - n;
//			return (tmp);
//		}
//		map_iterator operator+=(size_type n)
//		{
//			_ptr = _ptr + n;
//			return (*this);
//		}
//		map_iterator operator-=(size_type n)
//		{
//			_ptr = _ptr - n;
//			return (*this);
//		}
//		difference_type	operator-(map_iterator const & x) const
//		{
//			return (_ptr - x._ptr);
//		}

		//Relational ok
		bool operator==(map_iterator const & x) const
		{
			if (_node == NULL && x._node == NULL)
				return (true);
			if (_node == NULL || x._node == NULL)
				return (false);
			return ( *(_node->content) == *(x._node->content));
		};
		bool operator!=(map_iterator const & x) const
		{
			return (!(*this == x));;
		};
//		bool operator>(map_iterator const & x) const
//		{
//			return (_ptr > x._ptr);
//		}
//		bool operator>=(map_iterator const & x) const
//		{
//			return (_ptr >= x._ptr);
//		}
//		bool operator<(map_iterator const & x) const
//		{
//			return (_ptr < x._ptr);
//		}
//		bool operator<=(map_iterator const & x) const
//		{
//			return (_ptr <= x._ptr);
//		}
			

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
