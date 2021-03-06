#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include "headers/Token.h"
#include "headers/Lexer.h"
#include "headers/Parser.h"
#include "headers/UnitTests.h"
#include "headers/ExpressionTree.h"

void runTests(const std::vector<unit_test::Test>& tests);

TEST_FUNC(LexerTokenizedExpression)
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

TEST_FUNC(LexerTokenizedExpressionToString)
{
    Lexer lexer;

    std::vector<Token> expr = lexer.TokenizeExpression("(+ 1 2)");
    std::string result = lexer.TokenizedExpressionToString(expr);
    std::string excepted = "( + 1 2 ) ";
    unit_test::assert_are_equal(excepted, result);
}

TEST_FUNC(ExpressionTreeInsertTest)
{
   ExpressionTree tree; 
   Token op = Token(TokenType::Add);
   Token one = Token(TokenType::Num, "1");
   Token two = Token(TokenType::Num, "2");
   tree.Insert(op)
       .Insert(one)
       .Insert(op)
       .Insert(one)
       .Insert(two)
       ;

   unit_test::assert_that(
           tree.Root()->GetValue()->GetValue() == "+", "excepted +");

   unit_test::assert_that(
           tree.Root()->GetLeft()->GetValue()->GetValue() == "1", "excepted 1");
    
   std::string actualop = "+";
   unit_test::assert_are_equal(
           actualop, tree.Root()->m_right->GetValue()->GetValue());
   
   std::string actualnum = "1";
   unit_test::assert_are_equal(
           actualnum, tree.Root()->m_right->m_left->GetValue()->GetValue());

   std::string actualnumOne = "2";
   unit_test::assert_are_equal(
           actualnumOne, tree.Root()->m_right->m_right->GetValue()->GetValue());
}

TEST_FUNC(ExpressionTreeToStringTest)
{
    ExpressionTree tree;
    Token op = Token(TokenType::Add);
    Token one = Token(TokenType::Num, "1");
    Token two = Token(TokenType::Num, "2");
    tree.Insert(op)
        .Insert(one)
        .Insert(op)
        .Insert(one)
        .Insert(two)
        ;

    std::string excepted = "(+ 1 (+ 1 2))";
    std::string actual = tree.ToString();
    unit_test::assert_are_equal(excepted, actual);
}

TEST_FUNC(ExpressionTreeEvalTest)
{ 
    ExpressionTree tree;
    Token op = Token(TokenType::Add);
    Token one = Token(TokenType::Num, "1");
    Token two = Token(TokenType::Num, "2");
    tree.Insert(op)
        .Insert(one)
        .Insert(op)
        .Insert(one)
        .Insert(two)
        ;

    std::string excepted = "4";
    std::string actual = tree.Eval()->GetValue()->GetValue();
    
    unit_test::assert_are_equal(excepted, actual);
}

TEST_FUNC(AddExpression)
{
    Expression* add = new class AddExpression(
            new NumberExpression("1"), new NumberExpression("2"));
    
    std::string excepted = "3";
    std::string actual = add->Reduce()->GetValue()->GetValue();

    unit_test::assert_are_equal(excepted, actual);
}


TEST_FUNC(ParserParseTest)
{
    Parser parser;
    ExpressionTree* tree = parser.Parse("(+ 1 (* 1 5))"); 
    ExpressionTree* treeOne = parser.Parse("(+ 1 2 3)"); 
    ExpressionTree* treeTwo = parser.Parse("(+ 1 (+ 2 3) 4)"); 


    std::string excepted = "(+ 1 5)";
    std::string exceptedOne = "(+ 1 (+ 2 3))";
    std::string exceptedTwo = "(+ 1 9)";

    std::string actual = tree->ToString(); 
    std::string actualOne = treeOne->ToString(); 
    std::string actualTwo = treeTwo->ToString(); 


    unit_test::assert_are_equal(excepted, actual);
    unit_test::assert_are_equal(exceptedOne, actualOne);
    unit_test::assert_are_equal(exceptedTwo, actualTwo);
}

int main()
{
    std::vector<unit_test::Test> tests = {
        unit_test::Test(LexerTokenizedExpression,           "LexerTokenizedExpression"),
        unit_test::Test(LexerTokenizedExpressionToString,   "LexerTokenizedExpressionToString"),
        unit_test::Test(ExpressionTreeInsertTest,           "ExpressionTreeInsertTest"),
        unit_test::Test(ExpressionTreeToStringTest,         "ExpressionTreeToStringTest"),
        unit_test::Test(ParserParseTest,                    "ParserParseTest"),
        unit_test::Test(AddExpression,                    "AddExpression"),
        unit_test::Test(ExpressionTreeEvalTest,         "ExpressionTreeEvalTest"),
    };

    Parser parser;
    ExpressionTree* tree = parser.Parse("(+ 1 (* 1 5))"); 
    runTests(tests);
	return 0;
}

void runTests(const std::vector<unit_test::Test>& tests)
{
    for (auto test : tests)
        test.Run();
}
