#include <iostream>
#include <string>
#ifndef TLLLC_TEST_H
#define TLLLC_TEST_H

/*! \brief The unittest namespace encompassed modules having to do with a testing
 * environment.
 */
namespace unittest
{
    static std::string status[2] = {"FAIL" , "PASS"};

    /*! \brief The Test template class is an abstracted, simple class to
     * display the results of unit tests.
     * Each test can be named, given an expected value, and then a true value:
     * test.name("MyClass::myMethod()").expect("Foo").test( myClass.myMethod() );
     * This will generate output to stderr shwoing the expected value, actual value,
     * and the pass/fail status.
     * \param ExpectedResult the type of results expected for this test.
     * It is common for a test suite to instantiate a number of Test classes
     * for different datatypes. 
     */
    template <class ExpectedResult>
    class Test
    {
        /*! The result expected in the next test.
         * \sa expect */
        ExpectedResult expected;

        /*! The actual result of the test.
         * \sa test
         */
        ExpectedResult actual;

        /*! The name of the test.
         * \sa name
         */
        std::string testName;

    public:

        /*! The constructor takes no arguments. */
        Test(){};

        /*! The expect method sets the expected value of the next test.
         * \sa expected
         * \param value The value expected from the next test.
         */
        inline Test& expect (ExpectedResult value)
        {
            expected = value;
            return *this;
        }

        /*! The name method sets the name of the next test.
         * \sa testName
         * \param name The name of the next test (typically the method name 
         * plus optional arguments)
         */
        inline Test& name (std::string)
        {
            testName = aName;
            return *this;
        }

        /*! The test method will evaluate the expression passed in, and compare
         * the result to the expected result, displaying the output.
         * \sa actual
         * \param value a value or expression which evaluates to a value of
         * the same datatype this test is expecting.
         */
        void test (ExpectedResult value)
        {
            actual = value;
            std::cout << testName << ": ";
            std::cout << "Expecting: " << expected << " | ";
            std::cout << "Actual: " << actual;
            std::cout << " => " << status[actual==expected] << std::endl;
        }
    };
}

#endif
