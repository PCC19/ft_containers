#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <memory>

namespace ft {
	template<typename T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			/*
			 * MEMBER TYPES
			 */
			 typedef T										value_type;
			 typedef Allocator								allocator_type;
			 typedef std::size_t							size_type;
			 typedef typename Allocator::const_reference	const_reference;

			/*
			 * METHODS
			 */
			explicit vector(const allocator_type & alloc = allocator_type()) :
				_Data(nullptr), _Alloc(alloc), _size(0), _capacity(0)
			{
				std::cout << "Constructor: Vector" << std::endl;
			}
			size_type size() const { return this->_size; };
			size_type capacity() const { return this->_capacity; };
			// temp
			//void push_back (int n) const { std::cout << "pushback:" << n << std::endl;};
			void push_back (const value_type &val)
			{
				this->_Data = new T[10];
				std::cout << "pushback:" << val << std::endl;
				this->_size++;
			}
			const_reference operator[](size_type n) const
			{	
				std::cout << n << std::endl;
				return this->_Data[n];
			};


		protected:
			value_type*		_Data;
			allocator_type	_Alloc;
			size_type		_size;
			size_type		_capacity;
	};
}
#endif

