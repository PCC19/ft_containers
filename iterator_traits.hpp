#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft{
	template <class I>
	struct iterator_traits
	{
		typedef I::difference_type		difference_type;
		typedef I::value_type			value_type;
		typedef I::pointer				pointer;
		typedef I::reference			reference;
		typedef I::iterator_category	iterator_category;
	};
}

#endif
