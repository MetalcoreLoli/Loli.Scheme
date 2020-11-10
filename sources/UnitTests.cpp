#include "../headers/UnitTests.h"

void unit_test::assert_that(bool predicate, const char* errorMessage)
{
    if (!predicate) throw std::runtime_error{errorMessage};
}

void unit_test::run_test(TestFunc_t unit_test, const char* nameOfTest)
{
    try
    {
        unit_test();
        std::cout <<"[+] Test " << nameOfTest << " was successful" << "\n";       
    }
    catch (const std::exception& ex)
    {
        std::cout <<"[-] Test failure " << nameOfTest << ex.what() << "\n";       
    }
}

unit_test::Test::Test(unit_test::TestFunc_t func, const char * name) 
{
    unit_test = func;
    this->name = name;
}

void unit_test::Test::Run()
{
    unit_test::run_test(unit_test, name);
}
