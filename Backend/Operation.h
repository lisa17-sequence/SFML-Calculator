#pragma once

#include <functional>
#include <map>
#include <iostream>
#include <vector>
#include <string>


class Operation
{
private:
    std::string expression;

public:
    std::string answer_to_expression(std::string str); // here is calculating our expression

    Operation(std::string expression_) {
        expression = expression_;
        const auto result = answer_to_expression(expression_);
        std::cout << result << '\n';
    }
};

