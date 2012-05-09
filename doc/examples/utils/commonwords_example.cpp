/*
 * Example usage of TurnLeft::Utils::CommonWords
 */

#include <TurnLeftLib/Utils>

TurnLeft::Utils::CommonWords library("commonwords.txt");

std::string common = "the";
std::string uncommon = "widget";

bool isCommon = library.find(common); // return true
isCommon = library.find(uncommon);
