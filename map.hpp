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
		{};


		// range constructor
			// depende de iterators e insert
		// copy constructor

		// destructor
			// depende do clear, que depende do erase + begin + end, que depende do iterator(e do seu incremento)
		~map() // destrutor temporario.
		{
			destroy_tree_temp(_root);
		};


		// Insert
		pair<iterator, bool> insert(const value_type& val)
		{
			(void) val;
			// Cria um iterator apontando para o node
			iterator it;
			rbt_node<value_type> *node = create_new_node_with_val(val);
			if (_root == NULL)
			{
				_root = node;
				_size++;
				it = node; // ???? Checar se esta correto isso !
				std::cout << "inserido  root: \n"; print_node(*node);
				return (ft::make_pair(it, true));
			}
			else
			{
				// SE ARVORE JA TEM NODES
				rbt_node<value_type>	*i, *p;
				i = _root;
				while(i != NULL) // avanca i para um apos local de insercao (p)
				{
					p = i;
					if (*(*node).content == *(*i).content) // se encontra node nao insere
					{
						destroy_node(node);
						return (ft::make_pair(it, false));
					};
					if (*(*node).content > *(*i).content)
						i = (*i).right;
					else
						i = (*i).left;
				};
				// Faz a insercao
				if (*(*node).content > *(*p).content)
				{
					connect(p, RIGHT, node);
					std::cout << "inserido right: \n"; print_node(*node);
				}
				else
				{
					connect(p, LEFT, node);
					std::cout << "inserido  left: \n"; print_node(*node);
				}
				_size++;
				it = node;
				return (ft::make_pair(it, true));
			}

			// ajusta arvore
				// rotacao
				// recolor
		};

		// CAPACITY
		bool empty()					{ return (_size == 0); };
		size_type size()				{ return (_size); };
		size_type max_size() const		{ return _Alloc.max_size(); };

		// ITERATORS
		iterator begin()
		{
			return iterator(min_subtree(_root));
		};

		const_iterator begin() const
		{
			return const_iterator(min_subtree(_root));
		};

		iterator end()
		{
			rbt_node<value_type>* n;
			n = max_subtree(_root);
			return ++iterator(n);
		};

		const_iterator end() const
		{
			rbt_node<value_type>* n;
			n = max_subtree(_root);
			return ++const_iterator(n);
		};

		reverse_iterator rbegin()
		{
			rbt_node<value_type>* n;
			n = max_subtree(_root);
			return reverse_iterator(n);
		};

		const_reverse_iterator rbegin() const
		{
			rbt_node<value_type>* n;
			n = max_subtree(_root);
			return const_reverse_iterator(n);
		};

		reverse_iterator rend()
		{
			return ++reverse_iterator(min_subtree(_root));
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
			rbt_node<value_type>* p;
			p = find_node(k);
			if (p)
				return (iterator(p));
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

		void print_tree_level()
		{
			print_tree_by_level(_root);
		};

		void print_tree_by_level(rbt_node<value_type> *n)
		{
			std::cout << "Print Tree Level: \n";

			ft::vector<rbt_node<value_type> >	q;
			rbt_node<value_type>				*nn;
			ft::vector<int>						lvl;
			size_type							i;
			
			i = 0;
			q.push_back(*n);
			lvl.push_back(1);
			while (i < q.size())
			{
				nn = (q[i].left);
				if (nn != NULL)
				{
					q.push_back(*nn);
					lvl.push_back(lvl[i] + 1);
				};
				nn = (q[i].right);
				if (nn != NULL)
				{
					q.push_back(*nn);
					lvl.push_back(lvl[i] + 1);
				};
				i++;
			};
			i = 0;
			std::cout << (q[i]).content->first << " ";
			i++;
			while (i < q.size())
			{
				if (lvl[i] != lvl[i-1]) std::cout << std::endl;
				std::cout << (q[i]).content->first << " ";
				i++;
			};
			std::cout << "\n-----------------\n";
		};

		void teste_delete_node(const key_type &k)
		{
			rbt_node<value_type> *p;
			p = find_node(k);
			delete_node(p);
		};

		void erase(iterator position)
		{
			rbt_node<value_type> *n;

			n = find_node(position->first);
			delete_node(n);
			_size--;
		};

		size_type erase(const key_type &k)
		{
			rbt_node<value_type> *n;

			n = find_node(k);
			if (delete_node(n))
			{
				_size--;
				return (1);
			};
			return (0);
		};

		void erase(iterator first, iterator last)
		{
			while(first != last)
			{
				erase(first++);
				_size--;
			};
		};


	protected:
		// ATRIBUTES
		rbt_node<value_type>*	_root;
		size_type				_size;
		key_compare				_comp;
		allocator_type			_Alloc;

	private:
		typedef enum {LEFT, RIGHT} direction;

		rbt_node<value_type> *create_new_node_with_val(const value_type& val)
		{
			value_type *aux = _Alloc.allocate(1);
			_Alloc.construct(aux, val);
			rbt_node<value_type> *node =  new rbt_node<value_type>(aux);
			return (node);
		};

		void destroy_node(rbt_node<value_type> *node_to_destroy)
		{
			if (node_to_destroy)
			{
				delete (*node_to_destroy).content;
				delete (node_to_destroy);
			};
		};
		void destroy_tree_temp(rbt_node<value_type> *r)
		{
			if (r == NULL) return;
			destroy_tree_temp((*r).left);
			destroy_tree_temp((*r).right);
			destroy_node(r);
		};

		void print_tree_infix_recursive(rbt_node<value_type> *r)
		{
			if (r == NULL) return;
			print_tree_infix_recursive((*r).left);
			print_node(*r);								// long print
//			std::cout << (*r).content->first << " ";	// short print
			print_tree_infix_recursive((*r).right);
		};

		rbt_node<value_type> * min_subtree(rbt_node<value_type> *i) const
		{
			if (i != NULL)
			{
				while ((*i).left != NULL)
					i = (*i).left;
			};
			return i;
		};

		rbt_node<value_type> * max_subtree(rbt_node<value_type> *i) const
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

		bool is_root(rbt_node<value_type> *n)
		{
			return ((*n).parent == NULL);
		};

		void connect(rbt_node<value_type> *p, direction d, rbt_node<value_type> *c)
		{
			if (p)
			{
				if (d == LEFT)
					(*p).left = c;
				else
					(*p).right = c;
			};
			(*c).parent = p;
		};

		rbt_node<value_type> * disconnect(rbt_node<value_type> *p, rbt_node<value_type> *c)
		{
			rbt_node<value_type> *temp;

			if (is_left_child(c))
			{
				temp = (*p).left;
				(*p).left = NULL;
			};
			if (is_right_child(c))
			{
				temp = (*p).right;
				(*p).right = NULL;
			};
			(*c).parent = NULL;
			return (temp);
		};

		rbt_node<value_type> *next_node(rbt_node<value_type> *n)
		{
			rbt_node<value_type> *p;

			if (n->right != NULL)	// go down
				p = min_subtree(n->right);
			else						// or go up
			{
				p = n;
				while (p != NULL && is_right_child(p))
					p = p->parent;
				p = p->parent;
			};
			return (p);
		};

		rbt_node<value_type> *prev_node(rbt_node<value_type> *n)
		{
			rbt_node<value_type> *p;

			if (n->left != NULL)	// go down
				p = max_subtree(n->left);
			else						// or go up
			{
				p = n;
				while (p != NULL && is_left_child(p))
					p = p->parent;
				p = p->parent;
			};
			return (p);
		};

		rbt_node<value_type> *find_node(const key_type &k) const
		{
			rbt_node<value_type>* p;
			p = _root;
			while (p)
			{
				if (k == p->content->first)
					return (p);
				if (_comp(k, p->content->first))
					p = p->left;
				else
					p = p->right;
			};
			return (NULL);
		};

		size_type	delete_node(rbt_node<value_type> *n)
		{
			// sem filhos
			if ((*n).left == NULL && (*n).right == NULL)
			{
				disconnect((*n).parent, n);
				destroy_node(n);
				return (1);
			};

			// um filho
			if (((*n).left && !(*n).right) || (!(*n).left && (*n).right) )
			{
				rbt_node <value_type> *p, *c;

				p = (*n).parent;
				// desconecta n de seu filho
				if ((*n).left)
					c = disconnect(n, (*n).left);
				else
					c = disconnect(n, (*n).right);
				// desconecta n de seu pai
				if (is_left_child(n))
				{
					disconnect((*n).parent, n);
					connect(p, LEFT, c);
				}
				else
				{
					disconnect((*n).parent, n);
					connect(p, RIGHT, c);
				};
				// destroi n
				destroy_node(n);
				return (1);
			};
			// dois filhos
			if ((*n).left && (*n).right)
			{
				rbt_node <value_type> *p, *lc, *rc, *s, *temp;
				direction dir;

				// decobre se n eh left or right child
				p = (*n).parent;
				if (is_left_child(n))
					dir = LEFT;
				else
					dir = RIGHT;
				// desconecta sucessor
				s = next_node(n);
				temp = disconnect((*s).parent, s);
				// desconecta n
				lc = disconnect(n, (*n).left);
				rc = disconnect(n, (*n).right);
				disconnect((*n).parent, n);
				// reconecta temp no lugar de n
				connect(temp, LEFT,  lc);
				connect(temp, RIGHT, rc);
				if (p == NULL)
				{
					(*temp).parent = NULL;
					_root = temp;
				}
				else
					connect(p, dir, temp);
				// destroi n
				destroy_node(n);
				return (1);
			};
			return(0);
		};

		

	}; // class map
}; // namespace
#endif
