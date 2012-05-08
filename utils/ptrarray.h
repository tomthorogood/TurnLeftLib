/*
 * ptrarray.h
 *
 *  Created on: Apr 21, 2012
 *      Author: tom
 */

#ifndef PTRARRAY_H_
#define PTRARRAY_H_
#include <bitset>
namespace TurnLeft{
namespace Utils{

template <size_t max, class PointerType>
class PtrArray {
protected:
	PointerType *allocator[max];
	std::bitset<max> flags;
public:
	/*! Default constructor initializes all members of the array to 0.
	 */
	PtrArray(){
		for (int i = 0; i < max; i++)
		{
			allocator[i] = 0;
		}
		flags.reset();
	}
	virtual ~PtrArray()
	{
		while (!flags.none())
		{
			delete allocator[top()];
			flags.set(top(), false);
		}
	}
	/*! returns a pointer to the next item in the stack after
	 * calling the new operator to initialize it. If the max
	 * stack size has already been reached, it deletes the top
	 * level and replaces it.
	 *
	 * This is a virtual method because if the PointerType requires
	 * additional arguments in its constructor, this needs to be
	 * overwritten in order to include them.
	 *
	 * @return a pointer to a PointerType object.
	 */
	virtual PointerType* alloc()
	{
		int next = gap();
		allocator[next] = new PointerType();
		flags.set(next);
		return allocator[next];
	}

	/*! Allocates a specific slot in the array
	 *
	 * @precondition loc must be less than max.
	 * @param a location within the array
	 * @return a pointer to the newly (re)allocated location in memory storing a PointerType object.
	 */
	virtual PointerType* allocAt(int loc)
	{
		if (flags.test(loc))
		{
			delete allocator[loc];
		}
		allocator[loc] = new PointerType();
		flags.set(loc);
		return allocator[loc];
	}

	/*! \brief Returns the most recently initialized pointer.
	 * Example usage:
	 * Foo* ptr = arr.top();
	 * ptr->doSomething();
	 * @return a pointer to an object of PointerType.
	 *
	 */
	int top()
	{
		for (int i = max-1; i >= 0; i--)
		{
			if (flags.test(i))
			{
				return i;
				break;
			}
		}
		return 0;
	}

	/*! \brief Returns the location of first gap in the array.
	 * Example usage:
	 * 	int next = arr.gap();
	 * 	Foo* ptr = arr.alloc(next);
	 * 	ptr->doSomething();
	 * 	@return an int between 0 and Max-1
	 */
	int gap()
	{
		for (int i = 0; i < max; i++)
		{
			if (!flags.test(i))
			{
				return i;
			}
		}
		return max-1;
	}

	/*! Retrieves the current stack size.
	 * @return an integer between 0 and Max-1
	 */
	int size()
	{
		return flags.count();
	}

	/*! Retrieves a specific pointer from the array. If that pointer
	 * has not yet been initialized, returns the most recently initialized pointer.
	 * @return a pointer to a PointerType object.
	 */
	PointerType* dig(int location)
	{
		return allocator[location];
	}
	/*! Removes a pointer from the stack by deleting it and decrementing
	 * the stack count. If the stack is already at 0, it does nothing.
	 * @return reference to this object for method chaining. (nodens.rem().alloc();)
	 */
	PtrArray& rem()
	{
		delete allocator[top()];
		flags.set(top(), false);
		return *this;
	}

	/*! When ownsership of a pointer is transferred to another entity, we must
	 * clear the bit so it is not deleted if the array goes out of scope. However,
	 * while the array is still in scope, the pointer can still be accessed with dig().
	 */
	PtrArray& transfer(int loc)
	{
		flags.set(loc,false);
		return *this;
	}

};

}}
#endif /* PTRARRAY_H_ */
