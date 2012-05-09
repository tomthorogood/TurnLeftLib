/*!
 * \file TurnLeftLib/utils/src/commonwords.h
 *
 * This is a library of the 100 most common words. It's basic usage is to
 * determine whether a certain word is among them, for the sake of analyzing
 * text. For instance, if you're counting the frequencies of certain words
 * fro user input, it's generally undesireable to count things like "and"
 * and "the".
 *
 * commonwords.txt is included in this library, and the list was taken
 * from: http://en.wikipedia.org/wiki/Most_common_words_in_English
 *
 * \example ../../doc/examples/utils/commonwords_example.cpp
 *
 */

#ifndef TL_UTILS_COMMONWORDS_H_
#define TL_UTILS_COMMONWORDS_H_
#include <iostream>     // for std::cout
#include <fstream>      // for std::ifstream
#include <sstream>      // for std::stringstream

#include <TurnLeftLib/Exceptions>

namespace TurnLeft{
namespace Utils{


/*! If no custom declaration of the following two constants is found,
 * use the defaults.
 */
#ifndef TL_UTILS_COMMONWORDS_LIB
#define TL_UTILS_COMMONWORDS_LIB "commonwords.txt"
#define TL_UTILS_COMMONWORDS_MAX_SIZE 101;
#endif //TL_UTILS_COMMONWORDS_LIB

class CommonWords
{
private:
    /*! The number of lines expected in the txtfile containing
     * the library of commonwords. This defaults to 101, but can be
     * defined in an external config if desired in order to increase
     * the size of the library.
     */
	const static int MAX_LIBRARY_SIZE = TL_UTILS_COMMONWORDS_MAX_SIZE;
	int numInput;   //Tracks the number of lines read from the file.

	/*! The array of words read in from the textfile.
	 * These words have all already been converted to lowercase!
	 */
	std::string library[MAX_LIBRARY_SIZE];


	/*! The name of the file containing the common words library. */
	const char* filename;

	/*! Attempts to open a file for reading; if the file does not exist
	 * or otherwise cannot be opened, a FileNotFoundException will be thrown.
	 * Otherwise, the CommonWords object will assume responsibility of a pointer
	 * to an input stream buffer.
	 * \throw FileNotFoundException
	 * \return a pointer to an input stream buffer.
	 * \sa filename
	 */
	std::ifstream* fopen();

	/*! A pointer to an input stream buffer. This belongs to to the object,
	 * and will be deleted once the object goes out of scope.
	 */
	std::ifstream* txtfile;

	/*! Factored construction code */
	inline void init();
public:
	/*! Default constructor uses the standard filename, "commonwords.txt" which
	 * must be lcoated in the local directory. This can be altered at compile-time
	 * by defining TL_UTILS_COMMONWORDS_LIB, or at run-time by passing in the
	 * name of the file to be used as is the case in the overloaded constructor
	 * method.
	 */
	CommonWords(){};

	/*! Overloaded constructor takes the filename of the common words library as
	 * its default.
	 * \param The filename which will serve as the library of commonwords.
	 */
	CommonWords(const char* filename);

	/*! Deletes the txtfile pointer.
	 * \sa txtfile
	 */
	~CommonWords();

	/*! Searches the commonwords library to determine if the paramterized
	 * string is present.
	 * \return True if it was found, False otherwise.
	 */
	bool find(std::string);
};


