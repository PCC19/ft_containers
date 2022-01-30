#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <memory>

namespace ft {
	template <typename T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			/*
			 * MEMBER TYPES
			 */
			 typedef T					value_type;
			 typedef Allocator			allocator_type;
			 typedef std::size_t		size_type;

		protected:
			value_type*		_Data;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_Alloc;
	};
}
#endif

