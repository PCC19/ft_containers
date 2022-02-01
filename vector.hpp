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
//				this->_Data = new T[1000];
//				std::cout << "Constructor: Vector" << std::endl;
			}

			size_type size() const { return this->_size; };

			size_type capacity() const { return this->_capacity; };

			bool empty () const {return (_size == 0); };

			size_type max_size() const {return _Alloc.max_size(); };

			void push_back(const value_type& val)
			{
				allocate_if_needed();
				_Alloc.construct(_Data + this->size(), val);
				_size++;
			}

			void pop_back()
			{
				_Alloc.destroy(_Data + _size--);
			}

			void clear()
			{
				while (_size > 0)
					pop_back();
				_Alloc.deallocate(_Data, _capacity);
				_Data = nullptr;
				_size = 0;	// redundante, apos while size deve ser 0
			}

			void reserve (size_type n)
			{
				size_type	new_capacity;
				size_type	i;

				if (_size + n >= _capacity)
				{
					new_capacity = n;
					value_type *tmp = _Alloc.allocate(new_capacity);
					i = 0;
					while( i < _size)
					{
						tmp[i] = _Data[i];
						_Alloc.destroy(_Data + i);
						i++;
					}
					_Alloc.deallocate(_Data, _size);
					_Data = tmp;
					_capacity = new_capacity;
				}
			}

			const_reference operator[](size_type n) const
			{	
				return _Data[n];
			};

		private:
			void allocate_if_needed(size_type n = 1)
			{
				size_type	new_capacity;
				size_type	i;

				if (_capacity == 0)
					new_capacity = 1;
				else
					new_capacity = _capacity;
				if (_size + n >= _capacity)
				{
					while (new_capacity < _size + n)
						new_capacity*=2;
					value_type *tmp = _Alloc.allocate(new_capacity);
					i = 0;
					while( i < _size)
					{
						tmp[i] = _Data[i];
						_Alloc.destroy(_Data + i);
						i++;
					}
					_Alloc.deallocate(_Data, _size);
					_Data = tmp;
					_capacity = new_capacity;
				}
			}


		protected:
			value_type*		_Data;
			allocator_type	_Alloc;
			size_type		_size;
			size_type		_capacity;
	};
}
#endif
