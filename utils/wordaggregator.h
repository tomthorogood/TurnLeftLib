/*
 * wordaggregator.h
 *
 *  Created on: May 2, 2012
 *      Author: tom
 */

#ifndef WORDAGGREGATOR_H_
#define WORDAGGREGATOR_H_

#ifndef COMMONWORDS_TXT_
#define COMMONWORDS_TXT_ "commonwords.txt"
#endif //COMMONWORDS_TXT_

#define WORDSET_ARRAY_SIZE 300
#define FREQUENCY_INIT_SIZE 100

#include <vector>
#include "../utils.hpp"

namespace TurnLeft {
namespace Utils {

struct WordFrequency {
	std::string word;
	int frequency;
	WordFrequency(){word="";frequency=0;}
};

class WordAggregator
{
private:
	CommonWords library;
	HungryVector <WordFrequency> frequencies;
public:
	WordAggregator(){};
	WordAggregator(std::vector<std::string>& words);
	WordFrequency init;
	HungryVector <WordFrequency> * getVector();
};

WordAggregator::WordAggregator (std::vector <std::string> &words)
:	library(COMMONWORDS_TXT_),
 	frequencies(FREQUENCY_INIT_SIZE, WordFrequency())
{
	int size = frequencies.size();
	for (int i = 0; i < words.size(); i++)
	{
		/* Create an array of the default size. */
		std::string wordset[WORDSET_ARRAY_SIZE];

		/* Create an explosion using the currently iterated string,
		 * and split the string into an array using ' ' as the delimiter.
		 */
		Explosion explosion(words[i]);
		explosion.explode(' ');
		explosion.getArray(wordset);

		/* To speed up parsing, insert the values into a hungry vector which
		 * can be resized dynamically.
		 */
		TurnLeft::Utils::HungryVector <std::string> wordvec(WORDSET_ARRAY_SIZE/2,"");
		for (int y = 0; y < WORDSET_ARRAY_SIZE; y++)
		{
			if (wordset[y] == "") break;
			wordvec.add(wordset[y]);
		}
		wordvec.trim();

		/** Iterate through the vector of words in the currently selected string
		 * and determine whether each word is already in the frequency list.
		 */
		for (int w=0; w < wordvec.size(); w++)
		{
			bool found = false;
			int s = 0;
			while (s < frequencies.size() && !found)
			{
				if (frequencies[s].word == "") break;
				if (frequencies[s].word == wordvec[w])
				{
					found = true;
				}
				else
				{
					s++;
				}
			}

			if (found)
			{
				frequencies[s].frequency++;
			}

			else if (!library.find(wordvec[w]))
			{
				frequencies.inc();
				frequencies[s].word = wordvec[w];
				frequencies[s].frequency++;
			}
			frequencies.trim();
		}
	}
}

HungryVector<WordFrequency>*
WordAggregator::getVector()
{
	return &frequencies;
}

}}


#endif /* WORDAGGREGATOR_H_ */
