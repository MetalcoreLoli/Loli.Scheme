#include "../headers/Parser.h"

ExpressionTree* Parser::Parse(const std::string& expression)
{
    Lexer lexer;
    std::vector<Token> tokenizedExpression = lexer.TokenizeExpression(expression);    

    ExpressionTree* tree = new ExpressionTree();

    for (int i = 1; i < tokenizedExpression.size()-1;i++)
    {
        tree->Insert(tokenizedExpression[i]); 
    }
    
    throw std::runtime_error{"TODO: Parse Method"};
    return tree;
}
