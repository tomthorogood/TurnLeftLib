/*
 * commonwords.cpp
 *
 *  Created on: May 8, 2012
 *      Author: tom
 */

#include "commonwords.h"

namespace TurnLeft{
namespace Utils{

CommonWords::CommonWords()
{
    txtfile = TL_UTILS_COMMONWORDS_LIB;
    init();
}

CommonWords::CommonWords(const char* filename)
{
    txtfile = filename;
    init();
}

CommonWords::~CommonWords()
{
    if (txtfile!=NULL)
    {
        delete txtfile;
    }
}

void
CommonWords::init()
{
    numInput = 0;

        std::string word;
        txtfile=NULL;
        std::ifstream f = *fopen();
        while (f)
        {
            //Redundancy to prevent a segfault.
            if (f.eof()) break;


            std::getline(f, word);
            for (int i = 0; i < word.length(); i++)
            {

                if (isalpha(word[i]) && isupper(word[i]))
                {
                    tolower(word[i]);
                }
            }
            library[numInput] = word;
            numInput++;
        }
}

std::ifstream*
CommonWords::fopen()
{
    txtfile = new std::ifstream();
    txtfile->open(filename);
    if (!txtfile->is_open())
    {
        throw (Exceptions::FileNotFoundException(filename));
    }
    return txtfile;
}

/*
 * Returns true if the word passed in exists in the library,
 * false otherwise.
 * \precondition The string input must be lowercase with no non-alpha chars.
 */
bool
CommonWords::find(std::string searchValue)
{

    bool found = false;
    for (int i = 0; i < MAX_LIBRARY_SIZE; i++)
    {
        if (searchValue == library[i]) return true;
    }
    return false;
}

}}

#endif /* COMMONWORDS_H_ */
