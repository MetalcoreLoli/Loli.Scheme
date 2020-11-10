#include "../headers/Lexer.h"
#include <cstdlib>

std::vector<Token> Lexer::TokenizeExpression(const std::string& expression)
{
        
    std::vector<Token> tokenizedExpression;
    
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(')
        {
            tokenizedExpression.push_back(Token(TokenType::Lp));
        }
        else if (expression[i] == ')')
        {
            tokenizedExpression.push_back(Token(TokenType::Rp));
        }
        else if (expression[i] == '+')
        {
            tokenizedExpression.push_back(Token(TokenType::Add));
        }
        else if (expression[i] == '-')
        {
            tokenizedExpression.push_back(Token(TokenType::Sub));
        }
        else if (expression[i] == '*')
        {
            tokenizedExpression.push_back(Token(TokenType::Mul));
        }
        else if (expression[i] == '/')
        {
            tokenizedExpression.push_back(Token(TokenType::Div));
        }
        else if (isdigit(expression[i]))
        {
            int j = i + 1;
            std::string number;
            number.push_back(expression[i]);

            while (isdigit(expression[j]))
            {
                number.push_back(expression[j]);
                j++;
            }

            tokenizedExpression.push_back(Token(TokenType::Num, number));
            i = j - 1;
        }
    }
    return tokenizedExpression;
}



std::string Lexer::TokenizedExpressionToString(const std::vector<Token> expression)
{
    std::string stringExpression;
    for (Token token : expression)
        stringExpression.append(token.GetValue()).append(" ");
    return stringExpression;
}
