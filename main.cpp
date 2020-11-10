#include <vector>
#include <iostream>
#include <functional>
#include "headers/Token.h"
#include "headers/Lexer.h"
#include "headers/UnitTests.h"

void runTests(const std::vector<unit_test::Test>& tests);

void LexerTokenizedExpression()
{
    Lexer lexer;
    std::vector<Token> expr = lexer.TokenizeExpression("(+ 1 21)");
    
    unit_test::assert_that(
            expr[0].GetType() == TokenType::Lp && expr[0].GetValue() == "(", ":C"); 
    
    unit_test::assert_that(
            expr[1].GetType() == TokenType::Add && expr[1].GetValue() == "+", ":C"); 
    
    unit_test::assert_that(
            expr[2].GetType() == TokenType::Num && expr[2].GetValue() == "1", ":c"); 
    
    unit_test::assert_that(
            expr[3].GetType() == TokenType::Num && expr[3].GetValue() == "21", ":C"); 
    
    unit_test::assert_that(
            expr[4].GetType() == TokenType::Rp && expr[4].GetValue() == ")", ":c"); 
}

void LexerTokenizedExpressionToString()
{
    Lexer lexer;

    std::vector<Token> expr = lexer.TokenizeExpression("(+ 1 2)");
    std::string result = lexer.TokenizedExpressionToString(expr);
    unit_test::assert_that(result == "( + 1 2 ) ", "");
}


int main()
{
    std::vector<unit_test::Test> tests = {
        unit_test::Test(LexerTokenizedExpression, "LexerTokenizedExpression"),
        unit_test::Test(LexerTokenizedExpressionToString, "LexerTokenizedExpressionToString"),
    };
    runTests(tests);
	return 0;
}


void runTests(const std::vector<unit_test::Test>& tests)
{
    for (auto test : tests)
        test.Run();
}
