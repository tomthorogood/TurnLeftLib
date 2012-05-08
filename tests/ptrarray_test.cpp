/*
 * ptrarray_test.cpp
 *
 *  Created on: Apr 21, 2012
 *      Author: tom
 */


#include "../test.h"
#include "../../utils/ptrarray.h"

class Foo
{
private:
	int myInt;
public:
	Foo(){};
	Foo(int anInt)
	{
		set(anInt);
	}
	void set(int anInt) { myInt = anInt;}
	int get(){return myInt;}
};


class TestArray : public TurnLeft::Utils::PtrArray <3, Foo>
{
public:
	Foo* alloc(int anInt)
	{
		int next = gap();
		allocator[next] = new Foo(anInt);
		flags.set(next);
		return allocator[next];
	}
};

int main()
{
	unittest::Test<int> inttest;
	TestArray arraytest;

	Foo *ptr, *dig = 0;
	ptr = arraytest.alloc(10);
	std::cout << ptr << std::endl;
	inttest.expect(10).test(ptr->get());
	ptr = arraytest.alloc(20);
	inttest.expect(20).test(ptr->get());
	ptr = arraytest.alloc(30);
	inttest.expect(30).test(ptr->get());
	ptr = arraytest.alloc(0);
	ptr = arraytest.alloc(0);
	ptr = arraytest.dig(0);
	inttest.expect(10).test(ptr->get());
	arraytest.rem();
	ptr = arraytest.dig(2);
	inttest.expect(0).test( ptr->get());
	return 0;
}

