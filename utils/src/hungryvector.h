/*
 * TurnLeftLib/utils/src/hungryvector.h
 * Part of the Turn Left C++ library, the Hungry Vector just
 * wants to eat! It automatically doubles in size whenever it gets full,
 * in order to avoid constant, expensive resizing.
 */

#ifndef TL_UTILS_HUNGRYVECTOR_H_
#define TL_UTILS_HUNGRYVECTOR_H_

#include "config.h"
#include <vector>

TL_UTILS_NAMESPACE

/*! \brief A less expensive implementation of the std::vector.
 * The HungryVector is a subclass of the std::vector. It has
 * two main functions:
 * 1) You can add values to it; doing so will automatically increase a sentinel
 * that will, when the time comes, double the size of the vector. This was done
 * to avoid expensive dynamic resizing on a call-by-call basis.
 * 2) If you want to free up some memory, you can trim the vector down to its
 * absolute size once you're finished adding to it.
 *
 * A third function of this class is to "fake" adding or removing
 * something to the vector by inc/decrementing its sentinel without
 * necessarily adding or subtracting a new object. This can be useful since because
 * the class inherits all operations from the std::vector class, you will still be
 * able to call standard vector operations which won't implicitly interact with the
 *
 * Because this is a template, its class type must be declared at compile time.
 */

template <class T>
class HungryVector : public std::vector<T>
{
private:
    /*! The total number of objects stored in the vector.
     */
	unsigned int usage;
public:
	/*! Default constructor works just fine, and creates a
	 * vector of size 0. This isn't recommended, as you then
	 * will have to resize it, and start the doubling operation
	 * from 1.
	 */
	HungryVector ()
    {
        usage = 0;
    }

	/*! The overloaded constructor takes a size and a default
	 * value, creating a vector of size 'size', all of whose
	 * values will be set to the default. If you're storing more
	 * complex objects in this vector, a good idea is to instantiate the
	 * vector like so: HungryVector <MyClass> vec(100, MyClass());
	 * \param size The initial number of objects in the vector.
	 * \param value The default value for those initial objects
	 */
	HungryVector(int size, T value)
    {
        usage = 0;
    }
	/*! The add() method will insert a new object into the vector.
	 * If the vector has reached its declared size, the vector will
	 * be resized to double its current size.
	 * \param value The value to be added.
	 */
	inline void add (T value)
    {
        if (usage == this->size()-1)
        {
            this->resize(this->size()*2);
        }
        this->at(usage) = value;
        usage++;
    }

	/*! Trims the vector down to the minimum size (meaning all non-default
	 * objects contained within the vector). This is done by simply resizing
	 * the vector to the size of 'usage', and is good for freeing up some
	 * memory. If for instance, your vector has just doubled from 800 to 1600
	 * objects, but you only bled into the first 10, giving your vector's true size
	 * 810, you can free up 790 blocks of memory allocated to the vector's type
	 * by calling the trim() method.
	 */
	inline void trim()
    {
        this->resize(usage);
    }

	/*! Increments the sentinel variable, so that it will approach its
	 * 'maximum' faster.
	 */
	inline void inc()
    {
        if (usage == this->size()-1)
            {
                this->resize(this->size()*2);
            }
        usage++;
    }
	/*! Decrements the sentinel variable, to slow down its approach to the
	 * 'maximum'
	 */
	inline void dec()
    {
        usage--;
    }
};

ECAPSEMAN_SLITU_LT
#endif /* HUNGRYVECTOR_H_ */
