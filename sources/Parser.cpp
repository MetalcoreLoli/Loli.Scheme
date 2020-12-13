#include "../headers/Parser.h"
#include <bits/c++config.h>
#include <ostream>
#include <iostream>
#include <stdexcept>

///
/// Function generating expression tree from 'args' with operation 'operation'
/// /return Expression
///
static Expression* GenerateExpressionTree (TokenType operation, const std::vector<Token>& args)
{
   
    if (args.size() > 1) 
    {
        Expression* left = new Expression(args[0].GetType(), args[0].GetValue());
        std::vector<Token> new_args;
        for (std::size_t i = 1; i < args.size(); i++)
            new_args.push_back(args[i]);
        return new Expression(operation, left, GenerateExpressionTree(operation, new_args));
    }
    else 
    {
        return new Expression(args[0].GetType(), args[0].GetValue());        
    }
}

static Expression* ParseHelper(const std::vector<Token>& expression)
{
    std::vector<Token> args; /*arguments of current expression*/
    TokenType op; /*current operation of expression*/
    ExpressionTree* tree = new ExpressionTree();

    for (std::size_t i = 0; i < expression.size(); i++)
    {
       if (expression[i].GetType() == TokenType::Rp) continue;
       else if (expression[i].GetType() == TokenType::Lp)
       {
           std::vector<Token> innerExpression;
           int j = i + 1;
           while (expression[j].GetType() != TokenType::Rp)
           {
               log_info ("%s", expression[j].GetValue().c_str());
               innerExpression.push_back(expression[j]);
               j++;
           }
           i = j - 1;
           Expression* inner = ParseHelper(innerExpression);
           if (inner->IsReducible())
           {
               tree->Insert(inner->Reduce()); 
           }
           else 
               tree->Insert(inner); 
       } 
       else if (expression[i].IsOperation())
       {
           op = expression[i].GetType(); 
       }
       else 
       {
            args.push_back(expression[i]);
       }
    }

    tree->Insert(GenerateExpressionTree(op, args));
    return tree->Eval();
}

/// 
/// Parsing string expression into ExpressionTree object
///
ExpressionTree* Parser::Parse(const std::string& expression)
{
    /* (+ 1 (+ 2 3) 4) */
    Lexer lexer;
    ExpressionTree* tree = new ExpressionTree();
    std::vector<Token> tokenizedExpression = lexer.TokenizeExpression(expression);    
    tree->Insert(ParseHelper(tokenizedExpression));
    return tree;
}
