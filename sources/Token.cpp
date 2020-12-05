#include "../headers/Token.h"

void Token::SetType(TokenType value)
{  
    switch (value)
    {
        case TokenType::Add: m_value = "+"; break;
        case TokenType::Sub: m_value = "-"; break;
        case TokenType::Mul: m_value = "*"; break;
        case TokenType::Div: m_value = "/"; break;
        case TokenType::Lp: m_value = "("; break;
        case TokenType::Rp: m_value = ")"; break;
    }
    m_type = value;
}

Token::Token(TokenType type)
{
    SetType(type);
}

Token::Token(TokenType type, const std::string& value)
{
    SetType(type);
    m_value = value;
}

