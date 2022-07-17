#include "Operation.h"

std::string Operation::answer_to_expression(std::string s)
{
    std::map<char, std::function<int(const int64_t&, const int64_t&)>> operations;
    operations['+'] = [](const int64_t& a, const int64_t& b) { return a + b; };
    operations['-'] = [](const int64_t& a, const int64_t& b) { return a - b; };
    operations['*'] = [](const int64_t& a, const int64_t& b) { return a * b; };
    operations['/'] = [](const int64_t& a, const int64_t& b) { return a / b; };

    std::vector<int64_t> stack_;
    int64_t number = 0;
    bool flag = true;
    for (auto& i : expression)
    {
        if (isdigit(i))
        {
            number *= 10;
            number += (i - '0');
            flag = true;
        }
        else
        {
            if (i != ' ')
            {
                int64_t num2 = stack_.back();
                stack_.pop_back();
                int64_t num1 = stack_.back();
                stack_.pop_back();

                stack_.push_back(operations[i](num1, num2));
                flag = false;
            }
            else if (i == ' ' && flag)
            {
                stack_.push_back(number);
                number = 0;
            }
        }
    }
    int64_t a = stack_.back();
    std::string answer = std::to_string(a);
    return answer;
}
