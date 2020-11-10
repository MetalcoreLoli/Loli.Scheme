#pragma once
#include <iostream>
#include <stdexcept>
#include <exception>
#include <functional>

namespace unit_test
{
    typedef std::function<void()> TestFunc_t;
    void assert_that(bool func, const char * message);
    void run_test(TestFunc_t func, const char* nameOfTest); 
 
    struct Test 
    {
        unit_test::TestFunc_t unit_test;
        const char * name;
   
        void Run();
        Test(unit_test::TestFunc_t test, const char* name);
    };

}
