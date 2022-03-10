/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:33:15 by pcunha            #+#    #+#             */
/*   Updated: 2022/03/11 00:14:18 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "node.hpp"

namespace ft
{
	template <class C>
	class map_iterator
	{
		public:
		// Types ok
		typedef value_type*									pointer;
		typedef value_type&									reference;
		typedef typename C::size_type						size_type;
		typedef typename C::difference_type					difference_type;
		typedef typename std;:bidirectional_iterator_tag	iterator_category;
		typedef typename C::value_type						value_type;
		typedef typename C::key_compare						key_compare;

		// Methods ok
		map_iterator () : _comp(key_compare()), _node(NULL), _prev(NULL), _content(NULL) {}; 
		map_iterator (rbt_node<value_type>* const node): _comp(key_compare()), _node(node)
		{
			if (node) _content = node.content;
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
		reference operator*()	const	{ return *node->content;  };
		pointer operator->()	const	{ return  &(operator*()); };

		// Increments / decrements
		map_iterator & operator++ ()
		{
			this->_ptr++;
			return *this;
		}
		map_iterator & operator-- ()
		{
			_ptr--;
			return *this;
		}
		map_iterator operator++(int)
		{
			map_iterator tmp;

			tmp = *this;
			this->_ptr++;
			return (tmp);
		}
		map_iterator operator--(int)
		{
			map_iterator tmp;

			tmp = *this;
			this->_ptr--;
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
			

		// TODO fazer curr() e update() ??


		// Atributes
		protected:
			key_compare				_comp;
			rbt_node<value_type>*	_node;
			rbt_node<value_type>*	_prev;
			value_type*				_content;
	};
}
#endif
