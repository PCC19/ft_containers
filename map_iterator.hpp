/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:33:15 by pcunha            #+#    #+#             */
/*   Updated: 2022/04/02 03:24:15 by pcunha           ###   ########.fr       */
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
		// Types
		typedef typename C::value_type						value_type;
		typedef value_type*									pointer;
		typedef value_type&									reference;
		typedef typename C::size_type						size_type;
		typedef typename C::difference_type					difference_type;
		typedef typename std::bidirectional_iterator_tag	iterator_category;
		typedef typename C::key_compare						key_compare;

		// Methods
		map_iterator () : _comp(key_compare()), _node(NULL), _leaf(NULL), _prev(NULL), _content(NULL) {}; 
		map_iterator (rbt_node<value_type>* const node,
						rbt_node<value_type>* leaf): _comp(key_compare()), _node(node)
		{
			if (node)
			{
				_content = node->content;
				_prev = prev_node(_node, leaf);
				_leaf = leaf;
			}
			else
			{
				_content = NULL;
				_prev = NULL;
				_leaf = NULL;
			};


		};
		map_iterator (map_iterator const & src) {*this = src;};

		~map_iterator () {};

		map_iterator & operator=(map_iterator const & rhs)
		{
			if (this != &rhs)
			{
				_comp = rhs._comp;
				_node = rhs._node;
				_leaf = rhs._leaf;
				_prev = rhs._prev;
				_content = rhs._content;
			};
			return *this;
		};

		// Dereferences
		reference operator*()	const	{ return (*_node->content); };
		pointer operator->()	const	{ return  &(operator*());   };

		// Increments / decrements
		map_iterator & operator++ ()
		{
			rbt_node<value_type> *p;

			if (_node == NULL) return (*this);
			
			_prev = _node;
			p = next_node(_node, _leaf);
			this->_node = p;
			if(p)
				this->_content = p->content;
			else
				this->_content = NULL;
			return (*this);
		};

		map_iterator & operator-- ()
		{
			rbt_node<value_type> *p;

			if (_node == NULL)
			{
				this->_node = _prev;
				if (_prev)
					this->_content = (*_prev).content;
				return (*this);
			};

			_prev = _node;
			p = prev_node(_node, _leaf);
			this->_node = p;
			if(p)
				this->_content = p->content;
			else
				this->_content = NULL;
			return (*this);
		};

		map_iterator operator++(int)
		{
			map_iterator tmp;

			tmp = *this;
			this->operator++();
			return (tmp);
		};

		map_iterator operator--(int)
		{
			map_iterator tmp;

			tmp = *this;
			this->operator--();
			return (tmp);
		};

		//Relational
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
			

		// TODO  fazer curr() e update() ??


		// Atributes
		protected:
			key_compare				_comp;
			rbt_node<value_type>*	_node;
			rbt_node<value_type>*	_leaf;
			rbt_node<value_type>*	_prev;
			value_type*				_content;

		private:
		rbt_node<value_type> * min_subtree(rbt_node<value_type> *i, rbt_node<value_type> *leaf)
		{
			if (i != leaf)
			{
				while ((*i).left != leaf)
					i = (*i).left;
			};
			return i;
		};

		rbt_node<value_type> * max_subtree(rbt_node<value_type> *i, rbt_node<value_type> *leaf)
		{
			if (i != leaf)
			{
				while ((*i).right != leaf)
					i = (*i).right;
			};
			return i;
		};

		bool is_left_child(rbt_node<value_type> *i)
		{
			if (i->parent != NULL && i->parent->left == i)
				return true;
			else
				return false;
		};

		bool is_right_child(rbt_node<value_type> *i)
		{
			if (i->parent != NULL && i->parent->right == i)
				return true;
			else
				return false;
		};

		rbt_node<value_type> *next_node(rbt_node<value_type> *n, rbt_node<value_type> *nil)
		{
			rbt_node<value_type> *p;

			if (n->right != nil)	// go down
				p = min_subtree(n->right, _leaf);
			else						// or go up
			{
				p = n;
				while (p != nil && is_right_child(p))
					p = p->parent;
				p = p->parent;
			};
			return (p);
		};

		rbt_node<value_type> *prev_node(rbt_node<value_type> *n, rbt_node<value_type> *nil)
		{
			rbt_node<value_type> *p;

			if (n->left != nil)	// go down
				p = max_subtree(n->left, _leaf);
			else						// or go up
			{
				p = n;
				while (p != nil && is_left_child(p))
					p = p->parent;
				p = p->parent;
			};
			return (p);
		};

	public:
		void print_iterator()
		{
			std::cout << "\n=================================================";
			std::cout << "\niterator _node: ";
			if (_node) print_node(*_node); else std::cout << " NULL";
//			std::cout << "\niterator _prev: ";
//			if (_prev) print_node(*_prev); else std::cout << " NULL";
			std::cout << std::endl;
			std::cout << "=================================================\n";
		};

	};
};
#endif
