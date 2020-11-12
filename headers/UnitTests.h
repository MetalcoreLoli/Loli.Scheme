#pragma once
#include <iostream>
#include <stdexcept>
#include <exception>
#include <functional>
#include <string>

namespace unit_test
{
    typedef std::function<void()> TestFunc_t;

    void assert_that(bool func, const char * message);
    void run_test(TestFunc_t func, const char* nameOfTest); 

    template<typename T>
    void assert_are_equal(T excepted, T actual)
    {
        std::string errorMessage = "excepted ";
        errorMessage.append(excepted).append(" but was ").append(actual);
        if (excepted != actual) throw std::runtime_error{errorMessage};
    }
 
    struct Test 
    {
        unit_test::TestFunc_t unit_test;
        const char * name;
   
        void Run();
        Test(unit_test::TestFunc_t test, const char* name);
    };

}
