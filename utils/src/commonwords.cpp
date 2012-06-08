/*
 * commonwords.cpp
 *
 *  Created on: May 8, 2012
 *      Author: tom
 */


#include <commonwords.h>

TL_UTILS_NAMESPACE

CommonWords::CommonWords()
{
    txtfile.open(TL_UTILS_COMMONWORDS_LIB);
    if (!txtfile.is_open())
    {
        throw (TurnLeft::Exceptions::FileNotFoundException(TL_UTILS_COMMONWORDS_LIB));
    }
    init();
}

CommonWords::CommonWords(const char* filename)
{
    if (!txtfile.is_open())
    {
        throw (TurnLeft::Exceptions::FileNotFoundException(filename));
    }
    txtfile.open(filename);
    init();
}

CommonWords::~CommonWords()
{ }

void
CommonWords::init()
{
    numInput = 0;
    
    std::string word;
    while (txtfile)
    {
        //Redundancy to prevent a segfault.
        if (txtfile.eof()) break;


        std::getline(txtfile, word);
        for (unsigned int i = 0; i < word.length(); i++)
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

void
CommonWords::fopen()
{
    txtfile.open(filename);
    if (!txtfile.is_open())
    {
        throw (Exceptions::FileNotFoundException(filename));
    }
}

bool
CommonWords::find(std::string searchValue)
{

    for (int i = 0; i < MAX_LIBRARY_SIZE; i++)
    {
        if (searchValue == library[i]) return true;
    }
    return false;
}

ECAPSEMAN_SLITU_LT
