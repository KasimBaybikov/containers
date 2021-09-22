#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "RandomAccessIterator.hpp"
#include "ConstRandomAccessIterator.hpp"
#include "ReverseRandomAccessIterator.hpp"
#include "ConstReverseRandomAccessIterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "remove_const.hpp"


namespace ft
{

template <class T, class Allocator = std::allocator<T> >
class vector
{
	public:
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef value_type&										reference;
		typedef const value_type&								const_reference;
		typedef typename Allocator::pointer						pointer;
		typedef typename Allocator::const_pointer				const_pointer;

		typedef RandomAccessIterator<value_type>				iterator;
		typedef ConstRandomAccessIterator<value_type>			const_iterator;
		typedef ReverseRandomAccessIterator<value_type>			reverse_iterator;
		typedef ConstReverseRandomAccessIterator<value_type>	const_reverse_iterator;

	private:
		value_type* first;
		value_type* last;
		size_type capacity;
		size_type length;
		Allocator allocator;

	public: //Construcors
		vector(); //1
		explicit vector(const Allocator& alloc); //2
		explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator()); //3
		template<class InputIt>
		vector(InputIt first, typename ft::enable_if<!is_integral_const<InputIt>::value, InputIt>::type last, const Allocator& alloc = Allocator());//4
		vector(const vector& other);//5


	public: //member functions
		const_iterator begin() const;
		iterator begin();
		const_iterator end() const;
		iterator end();
};

template <class T, class Allocator>
ft::vector<T, Allocator>::vector() : first(0), last(0), capacity(0), length(0), allocator(allocator_type()) {}

template <class T, class Allocator>
ft::vector<T, Allocator>::vector(const Allocator& alloc) : first(0), last(0), capacity(0), length(0), allocator(alloc) {}


template <class T, class Allocator>
ft::vector<T, Allocator>::vector(ft::vector<T, Allocator>::size_type count, const T& value, const Allocator& alloc) : allocator(alloc)
{
	first = allocator.allocate(count);
	this->capacity = count;
	this->length = count;
	for (size_type i = 0; i < count; i++)
		allocator.construct(first + i, value);
	this->last = this->first + this->length;
}

template <class T, class Allocator>
template <class InputIt>
ft::vector<T, Allocator>::vector(InputIt first, typename ft::enable_if<!is_integral_const<InputIt>::value, InputIt>::type last, const Allocator& alloc) : allocator(alloc)
{
	this->length = std::distance(first, last);
	this->capacity = std::distance(first, last);
	this->first = allocator.allocate(this->capacity);
	for (size_type i = 0; i < this->length; i++)
		allocator.construct(this->first + i, *(first + i));
	this->last = this->first + this->length;
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_iterator ft::vector<T, Allocator>::begin() const
{
	return const_iterator(this->first);
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::begin()
{
	return iterator(this->first);
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::const_iterator ft::vector<T, Allocator>::end() const
{
	return const_iterator(this->last);
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::end()
{
	return iterator(this->last);
}

}
#endif
