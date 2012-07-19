/*
 * Part of the Turn Left C++ Lib.
 * This file contains two datatypes.
 *
 * 1) The WordFrequency struct, which is simply a way to map a string
 * to the number of times it is used in a block of text.
 * 2) The WordAggregator class, which parses a string, first splitting it into
 * an array, then filtering out the commonwords, and finally counting the number
 * of times each other word appears in the text.
 *
 * It should be noted that this class is not to be used lightly: it's very expensive.
 * Suggestions are welcome on how to optimize this code for better performance!
 */

#ifndef TL_UTILS_WORDAGGREGATOR_H_
#define TL_UTILS_WORDAGGREGATOR_H_

#define WORDSET_ARRAY_SIZE 300
#define FREQUENCY_INIT_SIZE 100

#include <TurnLeftLib/TurnLeft.h>
#include <map>
namespace TurnLeft
{
namespace Utils
{

typedef std::map <std::string, int> FrequencyMap;
typedef FrequencyMap::iterator FrequencyIterator;
typedef HungryVector <std::string> FrequencyVector;

/*! The WordAggregator class parses a string, separating words into an array, 
 * filtering out common words, and finally counting the number of times each
 * word appears in the array. This class relies on other tools in this library:
 * HungryVector, Explosion, and CommonWords
 */
class WordAggregator
{
private:
    /*! The library of words that will be filtered out of the input text.
     * \sa TurnLeft::Utils::CommonWords */
	CommonWords* library;

    void parse(std::string&, FrequencyMap& _map);

public:
    /*! Default constructor also calls default constructor of library. Not
     * very useful, but offered for completeness. */
	WordAggregator();

    /*! The standard constructor takes in a vector of strings, and may optionally
     * contain a filename to be passed into the CommonWords library constructor.
     * This constructor is useful when aggregating multiple blocks of text.
     * \param words A vector containing chunks of text.
     * \param _map A frequency map to be filled with the results
     * \param libFilename (Optional) The filename of the common words library
     * (default is NULL, which will invoke the preprocessed setting).
     */
	WordAggregator(std::vector<std::string>& words, FrequencyMap& _map, 
            const char* libFilename);

    /*! The overloaded constructor takes in a HungryVector of strings, and may
     * optionally contain a filename to be passed into the CommonWords library
     * constructor.
     * \param words A HungryVector containing chunks of text.
     * \param _map A frequency map to be filled with the results
     * \param libFilename (Optional) The filename of the common words library
     * (default is NULL, which will invoke the preprocessed setting).
     */
    WordAggregator(FrequencyVector& words, FrequencyMap& _map,
            const char* libFilename);

    /*! This overloaded constrcutor takes in a single string, and may optioanlly
     * contain a filename to be passed into the CommonWords library constructor.
     * This constructor is useful when only parsing one block of text.
     */
    WordAggregator(std::string& words, FrequencyMap& _map, 
            const char* libFilename);
    ~WordAggregator();

};

}//namespace Utils
}//namespace TurnLeft

#endif /* WORDAGGREGATOR_H_ */
