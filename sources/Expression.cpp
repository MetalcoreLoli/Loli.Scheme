#include "../headers/Expression.h"
Expression::Expression()
{
    m_left = nullptr;
    m_right = nullptr;
    m_value = nullptr;
}

Expression::Expression(TokenType type)
{
    m_value = new Token(type);
    m_left = nullptr;
    m_right = nullptr;
}

Expression::Expression(TokenType type, const std::string& value)
{
    m_value = new Token(type, value);
    m_left = nullptr;
    m_right = nullptr;
}

Expression::Expression(TokenType type, Expression* left, Expression* right)
{
    m_value = new Token(type);
    m_left = left;
    m_right = right;
}

Expression::~Expression()
{
    delete m_left;
    delete m_right;
    delete m_value;
}

bool Expression::IsReducible()
{
    if (m_value->GetType() == TokenType::Num) return false;
    else return true;
}

Expression* Expression::Reduce() {return nullptr;}
