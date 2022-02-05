#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include "random_access_iterator.hpp"
#include <memory>
#include <stdexcept>

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
			 typedef typename Allocator::reference			reference;
			 typedef typename Allocator::pointer			pointer;
			 typedef typename Allocator::const_pointer		const_pointer;
			 typedef ft::random_access_iterator<vector>		iterator;
			 typedef ft::random_access_iterator<vector>		const_interator;



			/*
			 * METHODS
			 */
			 // Default constructor
			explicit vector(const allocator_type & alloc = allocator_type()) :
				_Data(nullptr), _Alloc(alloc), _size(0), _capacity(0) {};

			// Assignment constructor
			vector & operator=(const vector & x)
			{
				if (this != &x){
					if(this->capacity() < x.size()){
						this->_Alloc.deallocate(this->_Data, this->capacity());
						this->_Data = this->_Alloc.allocate(x.size());
						this->_capacity = x.size();
					}
					for (size_type i = 0; i < x.size(); i++){
						this->_Alloc.construct(&_Data[i], x[i]);
					}
					this->_size = x.size();
				}
				return *this;
			};

			// Copy constructor
			vector (const vector & x):_Data(nullptr), _Alloc(allocator_type()), _capacity(0)
			{ *this = x; }

			// Destructor
			~vector() { 
				_Alloc.deallocate(_Data, _capacity);
				};

			size_type size() const { return this->_size; };

			size_type capacity() const { return this->_capacity; };

			allocator_type get_allocator() const { return _Alloc; };

			reference operator[](size_type n) {	return _Data[n]; };

			const_reference operator[](size_type n) const {	return _Data[n]; };

			reference at (size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("vector");
				else
					return _Data[n];
			}

			const_reference at (size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("vector");
				else
					return _Data[n];
			}

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
						_Alloc.construct(&tmp[i], _Data[i]);
						_Alloc.destroy(_Data + i);
						i++;
					}
					_Alloc.deallocate(_Data, _size);
					_Data = tmp;
					_capacity = new_capacity;
				}
			}

			void resize(size_type n, value_type val = value_type())
			{
				// Versao Mac
				// while (n < _size) pop_back(); while (n > _size) push_back(val);

				// Versao Linux
				while (n < _size) pop_back();
				if (n > _capacity)
					reserve(n);
				while (n > _size) push_back(val);
			}

			void swap (vector& x)
			{
				value_type	*data_tmp;
				size_type	size_tmp;
				size_type	capacity_tmp;
				
				data_tmp = _Data;
				_Data = x._Data;
				x._Data = data_tmp;

				size_tmp = _size;
				_size = x._size;
				x._size = size_tmp;

				capacity_tmp = _capacity;
				_capacity = x._capacity;
				x._capacity = capacity_tmp;
			}

			/*
			 * ITERATORS
			 */

			iterator begin()		{ return iterator(_Data); };
			iterator end()			{ return iterator(_Data + _size); };
			iterator begin() const	{ return const_iterator(_Data); };
			iterator end() const	{ return const_iterator(_Data + _size); };



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
						_Alloc.construct(&tmp[i], _Data[i]);
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
