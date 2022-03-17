#ifndef MAP_HPP
#define MAP_HPP

#include "map_iterator.hpp"

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
//		typedef ft::reverse_map_iterator< ft::map<key_type, mapped_type> >	reverse_iterator;
//		typedef ft::reverse_map_iterator< ft::map<key_type, mapped_type> >	const_reverse_iterator;
	
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
//			destroy_node(_root);
		}


		// Insert
		pair<iterator, bool> insert (const value_type& val)
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
					(*p).right = node;
					(*node).parent = p;
					std::cout << "inserido right: \n"; print_node(*node);
				}
				else
				{
					(*p).left = node;
					(*node).parent = p;
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

		bool empty()					{ return (_size == 0); };
		size_type size()				{ return (_size); };
		size_type max_size() const		{ return _Alloc.max_size(); };

		iterator begin()
		{
			if (is_left_child(min_subtree(_root)))
				std::cout << "left  child \n";
			else
				std::cout << "right child \n";
			return iterator(min_subtree(_root));
		};
		const_iterator begin() const
		{
			return iterator(min_subtree(_root));
		};
		iterator end()
		{
			if (is_right_child(max_subtree(_root)))
				std::cout << "right  child \n";
			else
				std::cout << "left child \n";
			return iterator(max_subtree(_root));
		};
		const_iterator end() const
		{
			return iterator(max_subtree(_root));
		};

		void print_tree_infix()
		{
			std::cout << "TREE:\n";
			print_tree_infix_recursive(_root);
			std::cout << std::endl;
		};


	protected:
		// ATRIBUTES
		rbt_node<value_type>*	_root;
		size_type				_size;
		key_compare				_comp;
		allocator_type			_Alloc;

	private:
		rbt_node<value_type> *create_new_node_with_val(const value_type& val)
		{
			value_type *aux = _Alloc.allocate(1);
			_Alloc.construct(aux, val);
			rbt_node<value_type> *node =  new rbt_node<value_type>(aux);
			return (node);
		};

		void destroy_node(rbt_node<value_type> *node_to_destroy)
		{
			delete (*node_to_destroy).content;
			delete (node_to_destroy);
		};
		void destroy_tree_temp(rbt_node<value_type> *r)
		{
			if (r == NULL) return;
			destroy_node((*r).left);
			destroy_node((*r).right);
			destroy_node(r);
		};

		void print_tree_infix_recursive(rbt_node<value_type> *r)
		{
			if (r == NULL) return;
			print_tree_infix_recursive((*r).left);
//			print_node(*r);
			std::cout << (*r).content->first << " ";
			print_tree_infix_recursive((*r).right);
		};


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


	}; // class map
}; // namespace
#endif
