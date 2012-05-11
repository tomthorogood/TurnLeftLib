
#include "wordaggregator.h"

namespace TurnLeft{
namespace Utils{

WordAggregator::WordAggregator (std::string& words, const char* libFilename=0)
:   library(libFilename)
{
    parse(words);
}

WordAggregator::WordAggregator (std::vector <std::string> &words, const char* libFilename=0)
:   library(libFilename)
{
    for (int i = 0; i < words.size(); i++)
    {
        parse(words[i]);
    }
}

void
WordAggregator::parse (std::string& words)
{
    std::string wordset[WORDSET_ARRAY_SIZE];
    Explosion explosion(words);
    explosion.explode(' ', wordset);

    /* Iterate through all the words in the wordset. */
    for (int w=0; w < WORDSET_ARRAY_SIZE; w++)
    {
        if (wordset[w] == "") break;
        bool found = !(frequencies.find(wordset[w]) == frequencies.end());
        bool add = (!found && !library.find(wordset[w]));
        if (found || add)
        {
            frequencies[wordset[w]]++;
            if (add) wordList.push_back(wordset[w]);
        }

    }
}

FrequencyMap*
WordAggregator::getMap()
{
	return &frequencies;
}

std::vector <std::string>*
WordAggregator::getWordList()
{
    return &wordList;
}

}}

