#include <stdio.h>
#include <vector>
#include <stdexcept>
#include <string.h>
#include <memory>

namespace my {
	template<typename T>
	class Vector {
	public:
		Vector(const std::initializer_list<T>& list)
		{
			this->data = new T[list.size()];
			this->sz = list.size();
			this->capacity = list.size();
			std::copy(list.begin(), list.end(), this->data);
		}

		Vector(int sz)
		{
			if (sz < 0) {
				throw std::length_error {"Vector()"};
			}
			this->data = new T[sz];
			this->sz = 0;
			this->capacity = sz;
		}

		Vector(const Vector<T>& other)
		{
			this->sz = other.sz;
			this->capacity = other.capacity;
			this->data = new T[this->capacity];
			memcpy(this->data, other.data, this->sz*sizeof(T));
		}
		
		Vector<T>& operator=(const Vector<T>& other)
		{
			delete [] this->data;
			this->sz = other.sz;
			this->capacity = other.capacity;
			this->data = new T[this->capacity];
			memcpy(this->data, other.data, this->sz*sizeof(T));
		}

		Vector() : data{new T[0]}, sz{0}, capacity{0} {}

		~Vector()
		{
			delete [] this->data;
		}

		void push(T elem);
		T at(int ind);
		int size();
		void set(int ind, T elem);
	private:
		T *data;
		int sz;
		int capacity;
	};
}

template<typename T>
int
my::Vector<T>::size()
{
	return this->sz;
}

template<typename T>
void
my::Vector<T>::set(int ind, T elem)
{
	this->data[ind] = elem;
}

template<typename T>
my::Vector<T>
operator+(my::Vector<T> l, my::Vector<T> r)
{
	for (int i = 0; i < l.size() && i < r.size(); ++i) {
		l.set(i, l.at(i) + r.at(i));
	}
	return l;
}

template<typename T>
void
my::Vector<T>::push(T elem)
{
	//static_assert(std::is_same<decltype(elem), decltype(this->data)>::value, "type mismatch");
	if (this->sz+1 > this->capacity) {
		this->capacity = 2*this->capacity + 1;
		T *new_data = new T[this->capacity];
		memcpy(new_data, this->data, this->sz*sizeof(T));
		delete [] this->data;
		this->data = new_data;
	}
	this->data[this->sz++] = elem;
}

template<typename T>
T
my::Vector<T>::at(int ind)
{
	//static_assert(std::is_same<decltype(elem), decltype(this->data)>::value, "type mismatch");
	if (ind >= this->sz) {
		throw std::out_of_range {"Vector::at()"};
	}
	return this->data[ind];
}

int
nest2()
{
	throw (45);
	return 1;
}

int
nest1()
{
	int i;
	try {
		i = nest2();
	}
	catch (int e) {
		printf("haha\n");
		i = 0;
		throw;
	}
	printf("we here\n");
	return i;
}

int main(int argc, char *argv[])
{
	my::Vector<int> v2;
	v2.push(2);
	v2.push(3);
	v2.push(4);
	v2.push(5);
	my::Vector<int> v = {1, 2, 3, 4};
	my::Vector<int> sum = v + v2;
	my::Vector<int> test;
	test = sum;

	try {
		int i = sum.at(3);
		printf("%d\n", i);
	}
	catch (int e) {
		printf("caught e\n");
	}
	catch (std::out_of_range) {
		printf("oops\n");
	}
	std::unique_ptr<my::Vector<int>> t(new my::Vector<int>(2));
	t->push(123);
	printf("%d\n", test.at(1));
	return 0;
}
