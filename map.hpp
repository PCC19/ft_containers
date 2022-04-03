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
		}; // class value_compare

		// METHODS
		// empty constructor
		explicit map (const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()) :
			_root(NULL), _size(0), _comp(comp), _Alloc(alloc)
		{
			create_nil_node();
		};

		void create_nil_node()
		{
			_nil  =  new node_ptr(NULL);
			_nil->parent = _root;
			_nil->content = NULL;
		};

		// range constructor
			// depende de iterators e insert
		// copy constructor

		~map() // destrutor temporario.
		{
			std::cout << "Destrutor MAP\n";
			clear();
		};

		// CAPACITY
		bool empty()					{ return (_size == 0); };
		size_type size()				{ return (_size); };
		size_type max_size() const		{ return _Alloc.max_size(); };

		// MODIFIERS
		// Insert
		pair<iterator, bool> insert(const value_type& val)
		{
			// Cria um iterator apontando vazio
			iterator it;
			node_ptr *node = create_new_node_with_val(val);

			if (_root == NULL)
			{
				insert_at_root(node);
					std::cout << "[" << node->content->first << "]  "; print_tree_level();
				return (ft::make_pair(iterator(_root, _nil), true));
			}
			else
			{
				// SE ARVORE JA TEM NODES
				node_ptr	*i, *p;
				i = _root;
				while(i != _nil) // avanca i para um apos local de insercao (p)
				{
					p = i;
					if (*(node->content) == *(i->content)) // se encontra node nao insere
					{
						destroy_node(node);
						return (ft::make_pair(it, false));
					};
					i = increment_pointer(i, node);
				};
				// Faz a insercao
				insert_node_at_position(p, node);
					std::cout << "inserting: " << node->content->first << "\n  ";
					std::cout << "antes fix:\n";
					print_tree_level();

				fix_insert1(node);
					std::cout << "depois fix;\n";
					print_tree_level();

				update_nil_node();
				return (ft::make_pair(iterator(node, _nil), true));
			};
		};

		void	update_nil_node()
		{
			if (_nil != NULL)
			{
				_nil->parent = _root;
				_nil->left = minimum(_root);
				_nil->right = maximum(_root);
			};
		};

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
			{
				return (0);
			};
		};

		void erase(iterator position)
		{
			node_ptr *n;

			n = find_node(position->first);
			if (n)
			{
				remove_node(n);
				print_tree_level();
			}
			else
				std::cout << "Nao Achou \n";
		};

		void erase(iterator first, iterator last)
		{

//			key_type key_first, key_last;
//			iterator i;
//
//			key_first = first->first;
//			key_last = last->first;
//			while(1)
//			{
//				i = begin();
//				if(i->first == key_last)
//					return;
//				while (i->first < key_first) i++;
//				erase(i);
//			};

			key_type key_first, key_last, next_key, curr_key;
			iterator i;

			key_first = first->first;
			key_last = last->first;
			curr_key = key_first;
			while (curr_key != key_last)
			{
				i = find(curr_key);
				next_key = (find((++i)->first))->first;
				std::cout << "curr key: " << curr_key << std::endl;
				erase(curr_key);
				curr_key = next_key;
			};
		};

		void clear()
		{
			destroy_tree_temp(_root);
			destroy_node(_nil);
		};

		void swap(map& other)
		{
			map<key_type, mapped_type> tmp(*this);
			*this = other;
			other = tmp;
		};

		// ITERATORS
		iterator begin()
		{
			return iterator(min_subtree(_root), _nil);
		};

		const_iterator begin() const
		{
			return const_iterator(min_subtree(_root, _nil));
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

		// ALLOCATOR
		allocator_type get_allocator() const{ return this->_Alloc; };


		// AUXILIARY FUNCTIONS
		void print_tree_infix()
		{
			std::cout << "TREE infix:\n";
			print_tree_infix_recursive(_root);
			std::cout << std::endl;
		};

		public:
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

		void teste_delete_node(const key_type &k)
		{
			node_ptr *p;
			p = find_node(k);
			remove_node(p);
		};

		void teste_rotate_left(const key_type &k)
		{
			node_ptr *p;
			p = find_node(k);
			rotate_left(p);
		};

		void teste_rotate_right(const key_type &k)
		{
			node_ptr *p;
			p = find_node(k);
			rotate_right(p);
		};

	protected:
		// ATRIBUTES
		node_ptr				*_root;
		node_ptr				*_nil;
		size_type				_size;
		key_compare				_comp;
		allocator_type			_Alloc;

	private:
		typedef enum {LEFT, RIGHT} direction;

		node_ptr *create_new_node_with_val(const value_type& val)
		{
			value_type *aux = _Alloc.allocate(1);
			_Alloc.construct(aux, val);
			node_ptr *node =  new node_ptr(aux);
			node->left = _nil;
			node->right = _nil;
			return (node);
		};

		void destroy_tree_temp(node_ptr *r)
		{
			if (r == _nil)
				return;
			destroy_tree_temp(r->left);
			destroy_tree_temp(r->right);
			destroy_node(r);
//				_root = NULL;
		};

		void destroy_node(node_ptr *node_to_destroy)
		{
			if (node_to_destroy)
			{
				_Alloc.destroy(node_to_destroy->content);
				_Alloc.deallocate(node_to_destroy->content, 1);
				delete (node_to_destroy);
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

		node_ptr * min_subtree(node_ptr *i) const
		{
			if (i != _nil)
			{
				while (i->left != _nil)
					i = i->left;
			};
			return i;
		};

		node_ptr * max_subtree(node_ptr *i) const
		{
			if (i != _nil)
			{
				while (i->right != _nil)
					i = i->right;
			};
			return i;
		};

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

		bool is_leaf(node_ptr *n)
		{
			if (n->left == _nil && n->right == _nil)
				return (1);
			else
				return (0);
		};

		void copy_node_content(const value_type& val, node_ptr *dest)
		{
			delete (dest->content);
			value_type *aux = _Alloc.allocate(1);
			_Alloc.construct(aux, val);
			dest->content = aux;
		};

// ==================== ORIGINAL ===========================================
//		
//		void remove_node(node_ptr *n)
//		{
//			node_ptr *s;
//			int	original_color;
//
//			if (n == _nil) return;
//
//			original_color = n->color;
//
//			// se for folha, deleta
//			if (is_leaf(n))
//			{
//				if (is_root(n))
//					_root = NULL;
//				else
//					disconnect(n->parent, n);
//				destroy_node(n);
//				return;
//			}
//			else	
//			// se nao for folha, chama recursivo no prox node
//			{
//				s = next_node(n);
//				if (n != s)
//					copy_node_content(*s->content, n);
//				remove_node(s);
//			};
////			if (original_color == BLACK)
////				rb_delete_fixup(n);
//		};
// ========================================================================


// ======================== LIVRO ================================================

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
			if (z->left == _nil)
			{
				x = z->right;
				transplant(z, z->right);
			}
			else if (z->right == _nil)
			{
				x = z->left;
				transplant(z, z->left);
			}
			else
			{
				y = minimum(z->right);
				y_original_color = y->color;
				x = y->right;
				if (y->parent == z && x)
				{
					x->parent = y;
				}
				else
				{
					transplant(y, y->right);
					y->right = z->right;
					if (y->right)
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

		void transplant(node_ptr *u, node_ptr *v)
		{
			if (u->parent == NULL)
			{
				_root = v;
			}
			else if (is_left_child(u))
			{
				u->parent->left = v;
			}
			else
			{
				u->parent->right = v;
			}
			if (v)
				v->parent = u->parent;
		};

		node_ptr *minimum(node_ptr *node) const
		{
			while (node->left != _nil)
			  node = node->left;
			return node;
		};

		node_ptr *maximum(node_ptr *node) const
		{
			while (node->right != _nil)
			  node = node->right;
			return node;
		};

		void fix_remove_node(node_ptr *n)
		{
			node_ptr *w;
			while (n != _root && n->color == BLACK)
			{
				if (n == n->parent->left)
				{
					std::cout << "Case 1a\n";
					w = n->parent->right;
					if (w->color == RED)
					{
						w->color = BLACK;
						n->parent->color = RED;
						rotate_left(n->parent);
						w = n->parent->right;
					}
					if (w->left->color == BLACK && w->right->color == BLACK)
					{
						std::cout << "Case 2a\n";
						w->color = RED;
						n = n->parent;
					}
					else if (w->right->color == BLACK)
					{
						std::cout << "Case 3a\n";
						w->left->color = BLACK;
						w->color = RED;
						rotate_right(w);
						w = n->parent->right;
					}
					std::cout << "Case 4a\n";
					w->color = n->parent->color;
					n->parent->color = BLACK;
					w->right->color = BLACK;
					rotate_left(n->parent);
					n = _root;
				}
				else
				{
					w = n->parent->left;
					if (w->color == RED)
					{
						std::cout << "Case 1b\n";
						w->color = BLACK;
						n->parent->color = RED;
						rotate_right(n->parent);
						w = n->parent->left;
					}
					if (w->right->color == BLACK && w->left->color == BLACK)
					{
						std::cout << "Case 2b\n";
						w->color = RED;
						n = n->parent;
					}
					else if (w->left->color == BLACK)
					{
						std::cout << "Case 3b\n";
						w->right->color = BLACK;
						w->color = RED;
						rotate_left(w);
						w = n->parent->left;
					}
					std::cout << "Case 4b\n";
					w->color = n->parent->color;
					n->parent->color = BLACK;
					w->left->color = BLACK;
					rotate_right(n->parent);
					n = _root;
				}
			}
			n->color = BLACK;
		};

		node_ptr *rotate_left(node_ptr *n)
		{
			node_ptr *p, *rc, *lgc;
			direction d;

			// so roda se tiver filho direito
			if (!n->right)
				return (n);
			if (is_left_child(n)) d = LEFT;
			if (is_right_child(n)) d = RIGHT;

			// salva ponteiros
			p = n->parent;
			rc = n->right;
			lgc = rc->left;

			// desconecta 3 nodes
			disconnect(p, n);
			disconnect(n, rc);
			disconnect(rc, lgc);

			// reconecta 3 nodes
			connect(n, RIGHT, lgc);
			connect(rc, LEFT, n);
			connect(p, d, rc);

			if (p == NULL)
				_root = rc;

			return (rc);
		};

		node_ptr *rotate_right(node_ptr *n)
		{
			node_ptr *p, *lc, *rgc;
			direction d;

			// so roda se tiver filho direito
			if (!n->left)
				return (n);
			if (is_left_child(n)) d = LEFT;
			if (is_right_child(n)) d = RIGHT;

			// salva ponteiros
			p = n->parent;
			lc = n->left;
			rgc = lc->right;

			// desconecta 3 nodes
			disconnect(p, n);
			disconnect(n, lc);
			disconnect(lc, rgc);

			// reconecta 3 nodes
			connect(n, LEFT, rgc);
			connect(lc, RIGHT, n);
			connect(p, d, lc);

			if (p == NULL)
				_root = lc;

			return (lc);
		};
// ================== END LIVRO ======================================================


		node_ptr *increment_pointer(node_ptr *i, node_ptr *node)
		{
			if (_comp(i->content->first, node->content->first))
				return (i->right);
			else
				return (i->left);
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

// ======================================== FIX LIVRO  ==========================================
	void fix_insert1(node_ptr *z)
	{
		while (z->parent->color == RED)
		{
			if (z->parent == z->parent->parent->left)
			{
				node_ptr *y = z->parent->parent->right;
				if (y->color == RED)
				{
					z->parent->color = BLACK;
					y->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				}
				else
				{
					if (z == z->parent->right)
					{
						z = z->parent;
						rotate_left(z);
					}
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
					z->parent->color = BLACK;
					y->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				}
				else
				{
					if (z == z->parent->left)
					{
						z = z->parent;
						rotate_right(z);
					}
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					rotate_left(z->parent->parent);
				}	
			};		
		}
		_root->color = BLACK;
	};



// ======================================== END FIX LIVRO  ==========================================

// ======================================== FIX SITE  ==========================================
//
//		void fix_insert1(node_ptr *n)
//		{
//			std::cout << "1\n";
//			if (is_root(n))
//				n->color = BLACK;
//			else
//				fix_insert2(n);
//		};
//
//		void fix_insert2(node_ptr *n)
//		{
//			std::cout << "2\n";
//			if (n->parent->color == BLACK)
//				return;
//			else
//				fix_insert3(n);
//		};
//
//		void fix_insert3(node_ptr *n)
//		{
//			std::cout << "3\n";
//			if (uncle(n) && (uncle(n))->color == RED)
//			{
//				n->parent->color = BLACK;
//				uncle(n)->color = BLACK;
//				grandparent(n)->color = RED;
//				fix_insert1(grandparent(n));
//			}
//			else
//				fix_insert4(n);
//		};
//	
//		void fix_insert4(node_ptr *n)
//		{
//			std::cout << "4\n";
//			if (n == n->parent->right && n->parent == grandparent(n)->left)
//			{
//				rotate_left(n->parent);
//				n = n->left;
//			}
//			else if (n == n->parent->left && n->parent == grandparent(n)->right)
//			{
//				rotate_right(n->parent);
//				n = n->right;
//			};
//			fix_insert5(n);
//		};
//
//		void fix_insert5(node_ptr *n)
//		{
//			std::cout << "5\n";
//			n->parent->color = BLACK;
//			grandparent(n)->color = RED;
//			if (n == n->parent->left && n->parent == grandparent(n)->left)
//			{
//				rotate_right(grandparent(n));
//			}
//			else
//			{
//				if (n == n->parent->right && n->parent == grandparent(n)->right)
//				rotate_left(grandparent(n));
//			};
//		};
//
//		node_ptr *grandparent(node_ptr *n)
//		{
//			if (n != _nil && n->parent != _nil && n->parent->parent != _nil)
//				return (n->parent->parent);
//			else
//				return _nil;
//		};
//
//		node_ptr *sibling(node_ptr *n)
//		{
//			if (n != NULL && n->parent != NULL)
//			{
//				if (is_left_child(n))
//					return (n->parent->right);
//				else
//					return (n->parent->left);
//			}
//			else
//				return NULL;
//		};
//
//		node_ptr *uncle(node_ptr *n)
//		{
//			if (n != NULL && n->parent != NULL && n->parent->parent != NULL)
//				return (sibling(n->parent));
//			else
//				return NULL;
//		};
// ======================================== END FIX SITE  ==========================================

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


	}; // class map

}; // namespace
#endif
