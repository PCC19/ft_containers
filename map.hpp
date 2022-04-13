#ifndef MAP_HPP
#define MAP_HPP

#include <cmath>
#include <vector>
#include "map_iterator.hpp"
#include "reverse_map_iterator.hpp"

namespace ft{

template <class Key, class T, class Compare = std::less<Key>,
		  class Allocator = std::allocator<pair<const Key, T> > >
	class map
	{
	public:
		// TYPES
		typedef	Key				key_type;
		typedef T				mapped_type;
		typedef	Compare			key_compare;
		typedef	Allocator		allocator_type;
		typedef std::size_t		size_type;
		typedef std::ptrdiff_t	difference_type;
		typedef ft::pair<const key_type, mapped_type>	value_type;
		typedef	typename Allocator::reference			reference;
		typedef typename Allocator::const_reference		const_reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		typedef ft::map_iterator< ft::map<key_type, mapped_type> >			iterator;
		typedef ft::map_iterator< ft::map<key_type, mapped_type> >			const_iterator;
		typedef ft::reverse_map_iterator< ft::map<key_type, mapped_type> >	reverse_iterator;
		typedef ft::reverse_map_iterator< ft::map<key_type, mapped_type> >	const_reverse_iterator;
		typedef rbt_node<value_type>					node_ptr;

		class value_compare
		{
			protected:
				Compare	comp;
				value_compare(Compare c): comp(c) {};
			public:
				typedef bool		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;
				bool operator () (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				};
		};

		// CONSTRUCTORS
		// empty constructor
		explicit map (const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()) :
			_root(NULL), _size(0), _comp(comp), _Alloc(alloc)
		{
			create_nil_node();
		};

		void create_nil_node()
		{
		    std::allocator<rbt_node<value_type> > node_allocator;
			_nil = node_allocator.allocate(1);
			node_allocator.construct(_nil, NULL);
			//_nil  =  new node_ptr(NULL);
			_nil->parent = _root;
			_nil->content = NULL;
			_nil->left = NULL;
			_nil->right = NULL;
			_nil->color = BLACK;
		};

		// range constructor
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): _root(NULL), _size(0), _comp(comp), _Alloc(alloc)
		{ 
			create_nil_node();
			insert(first, last);
		};

		// copy constructor
		map (const map & src) : _root(NULL), _size(0)
		{
			*this = src;
		};

		// assign operator
		map& operator = (const map &src)
		{
			if (this == &src)
				return (*this);
			_comp = src._comp;
			_Alloc = src._Alloc;
			clear();
			create_nil_node();
			insert(src.begin(), src.end());;
			return (*this);
		};

		// DESTRUCTOR
		~map() { clear(); };

		// CAPACITY
		bool empty()					{ return (_size == 0); };
		size_type size()				{ return (_size); };
		size_type max_size() const		{ return _Alloc.max_size(); };

		// MODIFIERS
		// Insert single
		pair<iterator, bool> insert(const value_type& val)
		{
			iterator it;
			node_ptr *node = create_new_node_with_val(val);

			if (_root == NULL)	// no nodes
			{
				insert_at_root(node);
				return (ft::make_pair(iterator(_root, _nil), true));
			}
			else				// already have nodes
			{
				node_ptr	*i, *p;
				i = _root;
				while(i != _nil) 
				{
					p = i;
					if ((node->content->first) == (i->content->first))
					{
						destroy_node(node);
						return (ft::make_pair(it, false));
					};
					i = increment_pointer(i, node);
				};
				insert_node_at_position(p, node);
				fix_insert_node(node);
				update_nil_node();
				return (ft::make_pair(iterator(node, _nil), true));
			};
		};

		// insert hint
		iterator insert (iterator position, const value_type& val)
		{
			node_ptr	*i = position._node;
			node_ptr	*start_node;
			key_type	max_from_hint, min_from_hint;
			
			max_from_hint = max_subtree(i)->content->first;
			min_from_hint = min_subtree(i)->content->first;
			if (_comp(val.first, min_from_hint) && _comp(max_from_hint, val.first))
				start_node = position._node;
			else
				start_node = _root;

			iterator it;
			node_ptr *node = create_new_node_with_val(val);
			if (_root == NULL)
			{
				insert_at_root(node);
				return (iterator(_root, _nil));
			}
			else
			{
				node_ptr	*p;
				i = start_node;
				while(i != _nil) 
				{
					p = i;
					if (*(node->content) == *(i->content)) 
					{
						destroy_node(node);
						return (it);
					};
					i = increment_pointer(i, node);
				};
				insert_node_at_position(p, node);
				fix_insert_node(node);
				update_nil_node();
				return (iterator(node, _nil));
			};
		};

		// insert range
		void insert (iterator first, iterator last)
		{
			while (first != last)
			{
				insert(*first);
				first++;
			};
		};

		// erase key
		size_type erase(const key_type &k)
		{
			node_ptr *n;

			n = find_node(k);
			if (n != _nil)
			{
				remove_node(n);
				return (1);
			}
			else
				return (0);
		};

		// erase position
		void erase(iterator position)
		{
			node_ptr *n;

			n = find_node(position->first);
			if (n) remove_node(n);
		};

		//erase range
		void erase(iterator first, iterator last)
		{

			key_type key_first, key_last, next_key, curr_key;
			iterator i;

			key_first = first->first;
			key_last = last->first;
			curr_key = key_first;
			while (curr_key != key_last)
			{
				i = find(curr_key);
				next_key = (find((++i)->first))->first;
				erase(curr_key);
				curr_key = next_key;
			};
		};

		void clear()
		{
			if (_root == NULL)
				return;
			destroy_tree_temp(_root);
			destroy_node(_nil);
			_root = NULL;
			_size = 0;
		};

		void destroy_tree_temp(node_ptr *r)
		{
			if (r == NULL)
				return;
			if (r == _nil)
				return;
			destroy_tree_temp(r->left);
			destroy_tree_temp(r->right);
			destroy_node(r);
			r = NULL;
		};

		void destroy_node(node_ptr *node_to_destroy)
		{
			if (node_to_destroy)
			{
				if (node_to_destroy != _nil)
				{
					_Alloc.destroy(node_to_destroy->content);
					_Alloc.deallocate(node_to_destroy->content, 1);
				};
				if (is_left_child(node_to_destroy))
					node_to_destroy->left = _nil;
				else
					node_to_destroy->right = _nil;
				delete (node_to_destroy);
			};
		};

		void swap(map& other)
		{
			node_ptr				*_root_tmp;
			node_ptr				*_nil_tmp;
			size_type				_size_tmp;
			key_compare				_comp_tmp;
			allocator_type			_Alloc_tmp;

			_root_tmp = _root;
			_nil_tmp = _nil;
			_size_tmp = _size;
			_comp_tmp = _comp;
			_Alloc_tmp = _Alloc;

			_root = other._root;
			_nil = other._nil;
			_size = other._size;
			_comp = other._comp;
			_Alloc = other._Alloc;

			other._root = _root_tmp;
			other._nil = _nil_tmp;
			other._size = _size_tmp;
			other._comp = _comp_tmp;
			other._Alloc = _Alloc_tmp;
		};

		// ITERATORS
		iterator begin()
		{
			return iterator(min_subtree(_root), _nil);
		};

		const_iterator begin() const
		{
			return const_iterator(min_subtree(_root), _nil);
		};

		iterator end()
		{
			node_ptr* n;
			n = max_subtree(_root);
			return ++iterator(n, _nil);
		};

		const_iterator end() const
		{
			node_ptr* n;
			n = max_subtree(_root);
			return ++const_iterator(n, _nil);
		};

		reverse_iterator rbegin()
		{
			node_ptr* n;
			n = max_subtree(_root);
			return reverse_iterator(n, _nil);
		};

		const_reverse_iterator rbegin() const
		{
			node_ptr* n;
			n = max_subtree(_root);
			return const_reverse_iterator(n, _nil);
		};

		reverse_iterator rend()
		{
			return ++reverse_iterator(min_subtree(_root), _nil);
		};

		const_reverse_iterator rend() const
		{
			return ++const_reverse_iterator(min_subtree(_root));
		};
		
		// OBSERVERS
		key_compare		key_comp() const		{ return _comp; };
		value_compare	value_comp() const		{ return value_compare(_comp); };

		// OPERATIONS
		iterator find(const key_type &k) const
		{
			node_ptr* p;
			p = find_node(k);
			if (p != _nil)
				return (iterator(p, _nil));
			else
				return (end());
		};

		size_type count (const key_type& k) const{
			return !(find(k) == end());
		};

		iterator lower_bound (const key_type &k)
		{
			for (iterator it = begin(); it != end(); ++it)
				if (!_comp(it->first, k)) return it;
			return end();
		};

		const_iterator lower_bound (const key_type &k) const
		{
			for (const_iterator it = begin(); it != end(); ++it)
				if (!_comp(it->first, k)) return it;
			return end();
		};
		
		iterator upper_bound(const key_type &k)
		{
			for (iterator it = begin(); it != end(); ++it)
				if (_comp(k,  it->first)) return it;
			return end();
		};

		const iterator upper_bound(const key_type &k) const
		{
			for (iterator it = begin(); it != end(); ++it)
				if (_comp(k,  it->first)) return it;
			return end();
		};

		pair<iterator,iterator> equal_range (const key_type& k){
			return ft::make_pair(lower_bound(k), upper_bound(k));
		};

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
			return ft::make_pair(lower_bound(k), upper_bound(k));
		};

		// ELEMENT ACCESS
		mapped_type& operator[](const key_type& k)
		{
			pair<key_type, mapped_type> par(k, mapped_type());

			insert(par);
			iterator it = find(k);
			return (it->second);
		};

		// ALLOCATOR
		allocator_type get_allocator() const{ return this->_Alloc; };


		protected:
		// ATRIBUTES
			node_ptr				*_root;
			node_ptr				*_nil;
			size_type				_size;
			key_compare				_comp;
			allocator_type			_Alloc;

// =================================================================================
//						TREE FUNCTIONS
// =================================================================================
		private:
		typedef enum {LEFT, RIGHT} direction;

		node_ptr *create_new_node_with_val(const value_type& val)
		{
		    std::allocator<rbt_node<value_type> > node_allocator;

			value_type *aux = _Alloc.allocate(1);
			_Alloc.construct(aux, val);
//			node_ptr *node =  new node_ptr(aux);
			node_ptr *node = node_allocator.allocate(1);
			node_allocator.construct(node, aux);
			node->left = _nil;
			node->right = _nil;
			node->color = RED;
			return (node);
		};

		void	update_nil_node()
		{
			if (_nil != NULL)
			{
				_nil->parent = _root;
				_nil->left = min_subtree(_root);
				_nil->right = max_subtree(_root);
			};
		};

		void remove_node(node_ptr *z)
		{ 
			node_ptr *x;
			node_ptr *y;
			y = z;
			int y_original_color = y->color;

			if (z == _root && _size == 1)
			{
				destroy_node(z);
				_root = _nil;
				_nil->left = _root;
				_nil->right = _root;
				_size--;
				return;
			};
			if (z->left == _nil)			// no children or only right
			{
				x = z->right;
				transplant(z, z->right);
			}
			else if (z->right == _nil)		// only left child
			{
				x = z->left;
				transplant(z, z->left);
			}
			else							// both children
			{
				y = min_subtree(z->right);
				y_original_color = y->color;
				x = y->right;
				if (y->parent == z)
				{
					x->parent = y;
				}
				else
				{
					transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				transplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			};
			if (y_original_color == BLACK)
				fix_remove_node(x);
			if (z != _nil)
			{
				destroy_node(z);
				_size--;
				update_nil_node();
			};
		};

		void fix_remove_node(node_ptr *z)
		{
			node_ptr *w;
			while (z != _root && z->color == BLACK)
			{
				if (z == z->parent->left)
				{
					w = z->parent->right;
					if (w->color == RED)
					{
						//std::cout << "Case 1a\n";
						w->color = BLACK;
						z->parent->color = RED;
						rotate_left(z->parent);
						w = z->parent->right;
					}
					if (w->left->color == BLACK && w->right->color == BLACK)
					{
						//std::cout << "Case 2a\n";
						w->color = RED;
						z = z->parent;
					}
					else
					{
						if (w->right->color == BLACK)
						{
							//std::cout << "Case 3a\n";
							w->left->color = BLACK;
							w->color = RED;
							rotate_right(w);
							w = z->parent->right;
						}
						//std::cout << "Case 4a\n";
						w->color = z->parent->color;
						z->parent->color = BLACK;
						w->right->color = BLACK;
						rotate_left(z->parent);
						z = _root;
					}
				}
				else
				{
					w = z->parent->left;
					if (w->color == RED)
					{
						//std::cout << "Case 1b\n";
						w->color = BLACK;
						z->parent->color = RED;
						rotate_right(z->parent);
						w = z->parent->left;
					}
					if (w->right->color == BLACK && w->left->color == BLACK)
					{
						//std::cout << "Case 2b\n";
						w->color = RED;
						z = z->parent;
					}
					else
					{
						if (w->left->color == BLACK)
						{
							//std::cout << "Case 3b\n";
							w->right->color = BLACK;
							w->color = RED;
							rotate_left(w);
							w = z->parent->left;
						}
						//std::cout << "Case 4b\n";
						w->color = z->parent->color;
						z->parent->color = BLACK;
						w->left->color = BLACK;
						rotate_right(z->parent);
						z = _root;
					}
				}
			}
			//std::cout << "Case 5 - root\n";
			z->color = BLACK;
		};

		void insert_node_at_position (node_ptr *p, node_ptr *node)
		{
			if (_comp(p->content->first, node->content->first))
			{
				connect(p, RIGHT, node);
				node->left = _nil;
			}
			else
			{
				connect(p, LEFT, node);
				node->right = _nil;
			};
			_size++;
		};

		void insert_at_root(node_ptr *node)
		{
			node->color = BLACK;
			_root = node;
			_root->left = _nil;
			_root->right = _nil;
			_size++;
		};

		void fix_insert_node(node_ptr *z)
		{
			while (z != _root && z->parent->color == RED)
			{
				if (z->parent == z->parent->parent->left)
				{
					node_ptr *y = z->parent->parent->right;
					if (y->color == RED)
					{
						//std::cout << "Case 1a\n";
						z->parent->color = BLACK;
						y->color = BLACK;
						z->parent->parent->color = RED;
						z = z->parent->parent;
					}
					else
					{
						if (z == z->parent->right)
						{
							//std::cout << "Case 2a\n";
							z = z->parent;
							rotate_left(z);
						}
						//std::cout << "Case 3a\n";
						z->parent->color = BLACK;
						z->parent->parent->color = RED;
						rotate_right(z->parent->parent);
					}
				}
				else
				{
					node_ptr *y = z->parent->parent->left;
					if (y->color == RED)
					{
						//std::cout << "Case 1b\n";
						z->parent->color = BLACK;
						y->color = BLACK;
						z->parent->parent->color = RED;
						z = z->parent->parent;
					}
					else
					{
						if (z == z->parent->left)
						{
							//std::cout << "Case 2b\n";
							z = z->parent;
							rotate_right(z);
						}
						// std::cout << "Case 3b\n";
						z->parent->color = BLACK;
						z->parent->parent->color = RED;
						rotate_left(z->parent->parent);
					};
				};		
				// std::cout << "Case 0\n";
				_root->color = BLACK;
			};
		};

		void transplant(node_ptr *u, node_ptr *v)
		{
			if (u->parent == NULL)
				_root = v;
			else if (is_left_child(u))
				u->parent->left = v;
			else
				u->parent->right = v;
			if (v)
				v->parent = u->parent;
		};

		node_ptr *rotate_left(node_ptr *n)
		{
			node_ptr *p, *rc, *lgc;
			direction d;

			if (n->right == _nil)
				return (n);
			if (is_left_child(n)) d = LEFT;
			if (is_right_child(n)) d = RIGHT;
			p = n->parent;
			rc = n->right;
			lgc = rc->left;
			disconnect(p, n);
			disconnect(n, rc);
			disconnect(rc, lgc);
			connect(n, RIGHT, lgc);
			connect(rc, LEFT, n);
			connect(p, d, rc);
			if (p == NULL) _root = rc;
			return (rc);
		};

		node_ptr *rotate_right(node_ptr *n)
		{
			node_ptr *p, *lc, *rgc;
			direction d;

			if (n->left == _nil)
				return (n);
			if (is_left_child(n)) d = LEFT;
			if (is_right_child(n)) d = RIGHT;
			p = n->parent;
			lc = n->left;
			rgc = lc->right;
			disconnect(p, n);
			disconnect(n, lc);
			disconnect(lc, rgc);
			connect(n, LEFT, rgc);
			connect(lc, RIGHT, n);
			connect(p, d, lc);
			if (p == NULL) _root = lc;
			return (lc);
		};

		node_ptr * min_subtree(node_ptr *i) const
		{
			if (i == NULL)
				return i;
			if (i != _nil)
			{
				while (i->left != _nil)
					i = i->left;
			};
			return i;
		};

		node_ptr * max_subtree(node_ptr *i) const
		{
			if (i == NULL)
				return i;
			if (i != _nil)
			{
				while (i->right != _nil)
					i = i->right;
			};
			return i;
		};

// =================================================================================
//						AUXILIARY FUNCTIONS
// =================================================================================
		bool is_left_child(node_ptr *i)
		{
			if (i == _nil || i == NULL )
				return false;
			if (i->parent != NULL && i->parent->left == i)
				return true;
			else
				return false;
		};

		bool is_right_child(node_ptr *i)
		{
			if (i == _nil || i == NULL)
				return false;
			if (i->parent != NULL && i->parent->right == i)
				return true;
			else
				return false;
		};

		bool is_root(node_ptr *n)
		{
			return (n->parent == NULL);
		};

		bool is_leaf(node_ptr *n)
		{
			if (n->left == _nil && n->right == _nil)
				return (1);
			else
				return (0);
		};

		bool is_red(node_ptr *node)
		{
			if (node == NULL)			return false;
			if (node->color == RED)		return true;
			return false;
		};

		bool is_black(node_ptr *node)
		{
			return (!is_red(node));
		};

		void connect(node_ptr *p, direction d, node_ptr *c)
		{
			if (p)
			{
				if (d == LEFT)
					p->left = c;
				else
					p->right = c;
			};
			if (c)
				c->parent = p;
		};

		node_ptr * disconnect(node_ptr *p, node_ptr *c)
		{
			node_ptr *temp;

			if (is_left_child(c) && p != _nil)
			{
				temp = p->left;
				p->left = NULL;
			};
			if (is_right_child(c) && p != _nil)
			{
				temp = p->right;
				p->right = NULL;
			};
			if (c)
				c->parent = NULL;
			return (temp);
		};

		node_ptr *next_node(node_ptr *n)
		{
			node_ptr *p;

			if (n->right != _nil)			// go down
				p = min_subtree(n->right);
			else							// or go up
			{
				p = n;
				while (p != NULL && is_right_child(p))
					p = p->parent;
				if (p->parent != NULL)
					p = p->parent;
			};
			return (p);
		};

		node_ptr *prev_node(node_ptr *n)
		{
			node_ptr *p;

			if (n->left != _nil)			// go down
				p = max_subtree(n->left);
			else							// or go up
			{
				p = n;
				while (p != NULL && is_left_child(p))
					p = p->parent;
				if (p->parent != NULL)
					p = p->parent;
			};
			return (p);
		};

		node_ptr *find_node(const key_type &k) const
		{
			node_ptr* p;
			p = _root;
			while (p != _nil)
			{
				if (k == p->content->first)
					return (p);
				if (_comp(k, p->content->first))
					p = p->left;
				else
					p = p->right;
			};
			return (_nil);
		};

		node_ptr *increment_pointer(node_ptr *i, node_ptr *node)
		{
			if (_comp(i->content->first, node->content->first))
				return (i->right);
			else
				return (i->left);
		};
		
// =================================================================================
//						DEBUG AND PRINT FUNCTIONS
// =================================================================================
		public:
		void print_tree_infix()
		{
			std::cout << "TREE infix:\n";
			print_tree_infix_recursive(_root);
			std::cout << std::endl;
		};

		void print_tree_level(int flag = 1)
		{
			std::cout << "size: " << _size << std::endl;
			if (_root == _nil)
				std::cout << "EMPTY TREE\n";
			else
			{
				if (flag == 0)
					print_tree_by_level(_root);
				else
					print_tree_by_level_color(_root, _nil);
			};
		};

		void print_tree_infix_recursive(node_ptr *r)
		{
			if (r == NULL) return;
			print_tree_infix_recursive(r->left);
			print_node(*r);								// long print
//			std::cout << (*r).content->first << " ";	// short print
			print_tree_infix_recursive(r->right);
		};
	}; // end of map class definition

	/*
	 * NON MEMBERS
	 */

	// OVERLOADS
		template <typename Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
		if(lhs.size() == rhs.size())
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		return false;
	};
	template <typename Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
		return !(lhs == rhs);
	};
	template <typename Key, class T, class Compare, class Alloc>
	bool operator< (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};
	template <typename Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
		return !(rhs < lhs);
	};
	template <typename Key, class T, class Compare, class Alloc>
	bool operator> (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
		return rhs < lhs;
	};
	template <typename Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
		return !(lhs < rhs);
	};
	template <typename Key, class T, class Compare, class Alloc>
  	void swap (const map<Key,T,Compare,Alloc>& x, const map<Key,T,Compare,Alloc>& y){ x.swap(y); };

}; // namespace
#endif
