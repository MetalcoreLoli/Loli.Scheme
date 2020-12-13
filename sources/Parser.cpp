#include "../headers/Parser.h"
#include <ostream>
#include <iostream>
#include <stdexcept>


/// 
/// Parsing string expression into ExpressionTree object
///
ExpressionTree* Parser::Parse(const std::string& expression)
{
    /* (+ 1 (+ 2 3) 4) */
    Lexer lexer;
    std::vector<Token> tokenizedExpression = lexer.TokenizeExpression(expression);    

    ExpressionTree* tree = new ExpressionTree();
    
    Token op(TokenType::Add);

    std::vector<Token> args;

    for (size_t i = 1; i < tokenizedExpression.size();i++)
    {
        if (tokenizedExpression[i].GetType() == TokenType::Rp) continue;
        else if (tokenizedExpression[i].IsOperation())
        {
            op = tokenizedExpression[i];
            tree->Insert(op);
        }
        else if (tokenizedExpression[i].GetType() == TokenType::Lp)
        {
            std::vector<Token> innerExpression;
            std::size_t j = i + 1;

            while (tokenizedExpression[j].GetType() != TokenType::Rp)
            {
                innerExpression.push_back(tokenizedExpression[j]);
                j++;
            }

            i = j;
            log_info("inner expr: %s", lexer.TokenizedExpressionToString(innerExpression).c_str());
            ExpressionTree* subtree = Parse(lexer.TokenizedExpressionToString(innerExpression));
            log_info("subtree: %s", subtree->ToString().c_str());
            log_info("subtree eval: %s", subtree->Eval()->GetValue()->GetValue().c_str());
            args.push_back(*(subtree)->Eval()->GetValue());
        }
        else  
        {
            args.push_back(tokenizedExpression[i]);
        }
    }
    for (std::size_t i = 1; i < args.size(); i++)
    {
        if (i % 2 == 0)
        {
            tree->Insert(op);
            tree->Insert(args[i]);
        }
        else 
        {
            tree->Insert(args[i]);
        }

    }
    return tree;
}
