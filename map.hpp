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


		// Insert
		pair<iterator, bool> insert (const value_type& val)
		{
			// Cria um novo node com o pair passado nos args (val)
			rbt_node<value_type>* node(val);
			print_node(node);
			// Cria um iterator apontando para o node
			iterator it;
			// Se o map estava vazio (root = NULL ou size == 0)
				// update root para apontar para o node
			if (_root == NULL)
			{
				_root = &node;
				std::cout << "inserido node na raiz\n";
			}
			else
			{
				std::cout << "ja tem um no na arvore\n";
			}
				// insere no no lugar certo da arvore
			// Retorna um pair contendo o iterator para o node
			return (ft::make_pair(it, false));


			// acha posicao certa para inserir
			// se ja existe faz retorno do pair com iterator e false
			// na nao existe insere
			// ajusta arvore
				// rotacao
				// recolor
		};


		bool empty()					{ return (_size == 0); };
		size_type size()				{ return (_size); };
		size_type max_size() const	{ return _Alloc.max_size(); };


		// ATRIBUTES
		rbt_node<value_type>*	_root;
		size_type				_size;
		key_compare				_comp;
		allocator_type			_Alloc;




	}; // class map
}; // namespace
#endif
