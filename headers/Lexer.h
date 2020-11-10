#pragma once
#include "Token.h"
#include <string>
#include <vector>

class Lexer
{
public:
    std::vector<Token> TokenizeExpression(const std::string& expression);
    std::string TokenizedExpressionToString(const std::vector<Token> expression);
};
