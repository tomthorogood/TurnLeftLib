#include <iostream>
#include <string>
#ifndef TLLLC_TEST_H
#define TLLLC_TEST_H

namespace unittest
{
    static std::string status[2] = {"FAIL" , "PASS"};

    template <class ExpectedResult>
    class Test
    {
        ExpectedResult  expected;
        ExpectedResult  actual;
        std::string     testName;

    public:
        Test();
        Test expect (ExpectedResult value);
        Test name   (std::string);
        void test   (ExpectedResult value);
    };

    template <class ExpectedResult>
        Test<ExpectedResult>::Test()
        { }

    template <class ExpectedResult>
        Test <ExpectedResult>
        Test<ExpectedResult>::expect(ExpectedResult value)
        {
            expected = value;
            return *this;
        }

    template <class ExpectedResult>
        Test <ExpectedResult>
        Test<ExpectedResult>::name(std::string aName)
        {
            testName = aName;
            return *this;
        }

    template <class ExpectedResult>
        void 
        Test<ExpectedResult>::test(ExpectedResult value)
        {
            actual = value;
            std::cout << testName << ": ";
            std::cout << "Expecting: " << expected << " | ";
            std::cout << "Actual: " << actual;
            std::cout << " => " << status[actual==expected] << std::endl;
        }
}

#endif
