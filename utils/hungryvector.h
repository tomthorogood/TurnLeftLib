/*
 * hungryvector.h
 *
 *  Created on: May 3, 2012
 *      Author: tom
 */

#ifndef HUNGRYVECTOR_H_
#define HUNGRYVECTOR_H_
#include <vector>

namespace TurnLeft {
namespace Utils {

template <class T>
class HungryVector : public std::vector<T>
{
private:
	int usage;
public:
	HungryVector();
	HungryVector(size_t size, T value);
	void add(T value);
	void trim();
	void inc();
};

template <class T>
HungryVector<T>::HungryVector()
:	std::vector<T>()
{
	usage = 0;
}

template <class T>
HungryVector<T>::HungryVector(size_t size, T value)
:	std::vector<T>(size,value)
{
	usage = 0;
}

template <class T>
void
HungryVector<T>::add(T value)
{
	if (usage == this->size()-1)
	{
		this->resize(this->size()*2);
	}
	this->at(usage) = value;
	usage++;
}

template <class T>
void
HungryVector<T>::trim()
{
	this->resize(usage);
}

template <class T>
void
HungryVector<T>::inc()
{
	if (usage == this->size()-1)
		{
			this->resize(this->size()*2);
		}
	usage++;
}

}
}



#endif /* HUNGRYVECTOR_H_ */
