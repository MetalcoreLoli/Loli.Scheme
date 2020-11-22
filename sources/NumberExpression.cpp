#include "../headers/NumberExpression.h"

NumberExpression::NumberExpression(std::string number)
{
    m_value = new Token(TokenType::Num, number);
    m_left = nullptr;
    m_right = nullptr;
}
NumberExpression::~NumberExpression()
{
    delete m_left;
    delete m_right;
    delete m_value;
}

bool NumberExpression::IsReducible() 
{
    return false;
}

Expression* NumberExpression::Reduce() {return new Expression(TokenType::Num, m_value->GetValue());}
