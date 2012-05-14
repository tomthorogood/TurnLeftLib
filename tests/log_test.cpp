/*
 * log_test.cpp
 *
 *  Created on: May 13, 2012
 *      Author: tom
 */

#include <TurnLeftLib/utils/Log>

namespace LogLvl = TurnLeft::Utils;

int main()
{
    TurnLeft::Utils::Log log1;

    TurnLeft::Utils::Log log2(
            LogLvl::ANNOYING,
            TurnLeft::Utils::COUT
    );

    TurnLeft::Utils::Log log3(
            LogLvl::WARN,
            TurnLeft::Utils::FILE,
            "logtest_output.txt"
    );

    log1.log("Critical Warning", LogLvl::CRITICAL);
    log1.log("Less Critical Warning", LogLvl::WARN);
    log1.log("Even less critical warning", LogLvl::VERBOSE);
    log1.log("Annoying warning", LogLvl::ANNOYING);

    log2.log("Critical Warning", LogLvl::CRITICAL);
    log2.log("Less Critical Warning", LogLvl::WARN);
    log2.log("Even less critical warning", LogLvl::VERBOSE);
    log2.log("Annoying warning", LogLvl::ANNOYING);

    log3.log("Critical Warning", LogLvl::CRITICAL);
    log3.log("Less Critical Warning", LogLvl::WARN);
    log3.log("Even less critical warning", LogLvl::VERBOSE);
    log3.log("Annoying warning", LogLvl::ANNOYING);
}
