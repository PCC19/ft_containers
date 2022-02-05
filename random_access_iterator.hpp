#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP


namespace ft
{

	template <class C>
	class random_access_iterator
	{
		public:
		typedef typename C::pointer				pointer;


		// Methods
		random_access_iterator () {};
		random_access_iterator (pointer p): _ptr(p) {};
		random_access_iterator (random_access_iterator & src) {*this = src;};

		~random_access_iterator () {};

		random_access_iterator & operator=(random_access_iterator const & rhs)
		{
			if (this != &rhs)
				*_ptr = rhs._ptr;
			return *this;
		};




	
		private:
		pointer _ptr;

	};



}
#endif
