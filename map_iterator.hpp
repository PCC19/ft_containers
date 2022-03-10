/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:33:15 by pcunha            #+#    #+#             */
/*   Updated: 2022/03/10 23:19:28 by pcunha           ###   ########.fr       */
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
		// Types
		typedef value_type*									pointer;
		typedef value_type&									reference;
		typedef typename C::size_type						size_type;
		typedef typename C::difference_type					difference_type;
		typedef typename std;:bidirectional_iterator_tag	iterator_category;
		typedef typename C::value_type						value_type;
		typedef typename C::key_compare						key_compare;

		// Methods
		map_iterator ()									{};
		map_iterator (pointer const p): _ptr(p)			{};
		map_iterator (map_iterator const & src) {*this = src;};

		~map_iterator () {};

		map_iterator & operator=(map_iterator const & rhs)
		{
			if (this != &rhs)
				_ptr = rhs._ptr;
			return *this;
		};

		// Dereferences
		reference operator *()	const		{ return *_ptr; };
		pointer operator ->()	const		{ return  _ptr; };
//		reference operator[](size_type i)	{ return _ptr[i]; };

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

		//Relational
		bool operator==(map_iterator const & x) const
		{
			return (_ptr == x._ptr);
		}
		bool operator!=(map_iterator const & x) const
		{
			return (_ptr != x._ptr);
		}
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
			

		// TODO fazer curr() e update()


		// Atributes
		protected:
			key_compare				_comp;
			rbt_node<value_type>*	_node;
			rbt_node<value_type>*	_prev;
			value_type*				_cache;
	};
}
#endif
