#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "RandomAccessIterator.hpp"


namespace ft
{

template <class T, class Allocator = std::allocator<T> >
class vector
{
	public:
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::size_type				size_type;
		typedef typename allocator_type::difference_type		difference_type;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;

		typedef RandomAccessIterator<value_type>				iterator;
		typedef RandomAccessIterator<const value_type>			const_iterator;
		typedef ReverseRandomAccessIterator<value_type>			reverse_iterator;
		//typedef ConstReverseRandomAccessIterator<value_type>	const_reverse_iterator;
	private:
		pointer first;

	public:

		vector()
		{
			first = 0;
		}

		iterator begin()
		{
			return iterator(first);
		}
};

}

#endif