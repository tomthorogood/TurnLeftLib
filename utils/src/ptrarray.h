/*
 * Part of the Turn Left C++ Lib, the PtrArray class is exactly that:
 * an array of pointers.
 *
 * In essence, this is a heap management tool. It is efficient because
 * it requests a large block of memory at one time, rather than requesting
 * smaller blocks, which prevents fragmentation.
 * The PtrArray class also takes care of automatically freeing all pointers
 * once the array itself falls out of scope, checking to see if they are
 * NULL before doing so in order to avoid double deletes.
 * However, double deletes are still possible, if the responsibility
 * of a pointer is transferred to another object. Therefore, the PtrArray
 * also provides a method to signal to its flags that it is transferring
 * control, which clears its memory map flag of this data, allowing a new
 * object to be allocated in memory if desired.
 *
 * Upon instantiaton, a PtrArray declares all of its pointers to be NULL.
 */

#ifndef TL_UTILS_PTRARRAY_H_
#define TL_UTILS_PTRARRAY_H_
#include <bitset>
namespace TurnLeft{
namespace Utils{

/*! \brief A class which allows for easier memory management that also prevents
 * heap fragmentation. It utilizes arrays instead of vectors to improve
 * performance.
 *
 * \param max (Template Param)The maximum possible size of the array, which
 * also will be the number of blocks of memory requested from the OS.
 * \param PointerType (Template Param)The type of object to be held in this array.
 */
template <size_t max, class PointerType>
class PtrArray {
protected:

    /*! The array of objects. */
	PointerType *allocator[max];
	/*! A bitset array of flags mapping to positions in the allocator array,
	 * which signifies whether or not that particular part of memory can be
	 * allocated or freed
	 * \sa allocator
	 */
	std::bitset<max> flags;
public:
	/*! The default construcotr initializes all members of the allocator
	 * to NULL and all flags to 0 (off).
	 */
	PtrArray(){
		for (unsigned int i = 0; i < max; i++)
		{
			allocator[i] = NULL;
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
	 * \return a pointer to a PointerType object.
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
	 * \precondition loc must be less than max.
	 * \param a location within the array
	 * \return a pointer to the newly (re)allocated location in memory storing a PointerType object.
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
	 * \return a pointer to an object of PointerType.
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
	 * 	\return an int between 0 and Max-1
	 */
	int gap()
	{
		for (unsigned int i = 0; i < max; i++)
		{
			if (!flags.test(i))
			{
				return i;
			}
		}
		return max-1;
	}

	/*! Retrieves the current stack size.
	 * \return an integer between 0 and Max-1
	 */
	int size()
	{
		return flags.count();
	}

	/*! Retrieves a specific pointer from the array. If that pointer
	 * has not yet been initialized, returns the most recently initialized pointer.
	 * \return a pointer to a PointerType object.
	 */
	PointerType* dig(int location)
	{
		return allocator[location];
	}
	
    /*! Remvoes the most 'topmost' pointer in the array, clearing its bit.
     * Works well when using the alloc() method.
     * \sa alloc()
     */
    PtrArray& rem()
	{
		delete allocator[top()];
		flags.set(top(), false);
		return *this;
	}

    /*! Removes a pointer from the array by deleting it and clearing
     * its bit. Works well when using the allocAt() method.
     * \sa allocAt()
     * \param The location in the array you wish to free.
     */
    void remAt(int loc)
    {
        if (!flags.test(loc)) return;
        flags.set(loc,false);
        delete allocator[loc];
    }

	/*! When ownsership of a pointer is transferred to another entity, we must
	 * clear the bit so it is not deleted if the array goes out of scope. However,
	 * while the array is still in scope, the pointer can still be accessed with dig(), 
     * unless the alloc() method assigns a new pointer to that location in the array..
	 */
	PtrArray& transfer(int loc)
	{
		flags.set(loc,false);
		return *this;
	}
};

}}
#endif /* TL_UTILS_PTRARRAY_H_ */
