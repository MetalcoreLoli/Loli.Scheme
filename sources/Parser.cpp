#include "../headers/Parser.h"

/// 
/// Parsing string expression into ExpressionTree object
///
ExpressionTree* Parser::Parse(const std::string& expression)
{
    /* (+ 1 (+ 2 3) 4) */
    Lexer lexer;
    std::vector<Token> tokenizedExpression = lexer.TokenizeExpression(expression);    

    ExpressionTree* tree = new ExpressionTree();

    for (size_t i = 1; i < tokenizedExpression.size()-1;i++)
    {
    }
    
    return tree;
}
