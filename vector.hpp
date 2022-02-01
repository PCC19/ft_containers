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
				this->_Data = new T[1000];
				std::cout << "Constructor: Vector" << std::endl;
			}
			size_type size() const { return this->_size; };
			size_type capacity() const { return this->_capacity; };
			void push_back(const value_type& val)
			{
//				std::cout << "pushback:" << val << std::endl;
				// codigo para checar tamanho e realocar
				allocate_if_needed();
				this->_Alloc.construct(_Data + this->size(), val);
				this->_size++;
			}
			const_reference operator[](size_type n) const
			{	
				return this->_Data[n];
			};

		private:
			void allocate_if_needed(size_type n = 1)
			{
				size_type new_capacity;

				if (this->_capacity == 0)
					new_capacity = 1;
				else
					new_capacity = this->_capacity;
				if (this->_size + n >= this->_capacity)
				{
					// calcula new capacity
					while (new_capacity < this->_size + n)
						new_capacity*=2;
					// cria vetor temp com new_capacity
					std::cout << "new_cap: " << new_capacity;

					// copia vetor antigo para novo
					// destroi antigo
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
