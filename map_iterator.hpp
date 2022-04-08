/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:33:15 by pcunha            #+#    #+#             */
/*   Updated: 2022/04/08 23:38:06 by pcunha           ###   ########.fr       */
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
		typedef typename C::node_ptr						node_ptr;

		// Methods
		map_iterator () : _comp(key_compare()), _node(NULL), _leaf(NULL), _content(NULL) {}; 
		map_iterator (rbt_node<value_type>* const node,
						rbt_node<value_type>* leaf): _comp(key_compare()), _node(node)
		{
			if (node)
			{
				_leaf = leaf;
				_content = node->content;
			}
			else
			{
				_leaf = NULL;
				_content = NULL;
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
			
			p = next_node(_node);
			this->_node = p;
			this->_content = p->content;
			return (*this);
		};

		map_iterator & operator-- ()
		{
			rbt_node<value_type> *p;

			if (_node == NULL) return (*this);

			if (_node == _leaf)
			{
				this->_node = _leaf->right; // leaf->right points to max tree element
				this->_content = _leaf->right->content;
				return (*this);
			}
			else
			{
				p = prev_node(_node);
				this->_node = p;
				this->_content = p->content;
				return (*this);
			};
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
			if (_node == _leaf && x._node == _leaf)
				return (true);
			if (_node == _leaf || x._node == _leaf)
				return (false);
			return ( *(_node->content) == *(x._node->content));
		};
		bool operator!=(map_iterator const & x) const
		{
			return (!(*this == x));;
		};
			
		// Atributes
		public:
			key_compare				_comp;
			rbt_node<value_type>*	_node;
			rbt_node<value_type>*	_leaf;
			value_type*				_content;

// =================================================================================
//						AUXILIARY FUNCTIONS
// =================================================================================

		private:
		node_ptr * min_subtree(node_ptr *i) const
		{
			if (i != _leaf)
			{
				while (i->left != _leaf)
					i = i->left;
			};
			return i;
		};

		node_ptr * max_subtree(node_ptr *i) const
		{
			if (i != _leaf)
			{
				while (i->right != _leaf)
					i = i->right;
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

		rbt_node<value_type> *next_node(rbt_node<value_type> *n)
		{
			rbt_node<value_type> *p;

			if (n->right != _leaf)			// go down
				p = min_subtree(n->right);
			else							// or go up
			{
				p = n;
				while (p != NULL && is_right_child(p))
					p = p->parent;
				p = p->parent;
			};
			if (p == NULL)
				return (_leaf);
			return (p);
		};

		rbt_node<value_type> *prev_node(rbt_node<value_type> *n)
		{
			rbt_node<value_type> *p;

			if (n->left != _leaf)			// go down
				p = max_subtree(n->left);
			else							// or go up
			{
				p = n;
				while (p != NULL && is_left_child(p))
					p = p->parent;
				p = p->parent;
			};
			if (p == NULL)
				return (_leaf);
			return (p);
		};

	public:
		void print_iterator()
		{
			std::cout << "\n=================================================";
			std::cout << "\niterator _node: ";
			if (_node) print_node(*_node); else std::cout << " NULL";
			std::cout << std::endl;
			std::cout << "=================================================\n";
		};
	};
};
#endif
