#include "expressionstream.h"
#include <string>
#include "calculator.h"
#include <sstream>

namespace lab4
{
    int operator_priority(std::string input_string)
    {
        int result = 0;

        if (input_string == "+" || input_string == "-")
            result = 1;
        else if (input_string == "*" || input_string == "/")
            result = 2;
        else
            throw 4;
        return result;
    }

    void calculator::parse_to_infix(std::string &input_expression)
    {
        lab1::expressionstream temp(input_expression);
        std::string check = temp.get_current_token();
        while(check != "\0")
        {
            infix_expression.enqueue(check);
            check = temp.get_next_token();
        }
    }

    void calculator::convert_to_postfix(lab3::fifo infix_expression)
    {
        lab3::lifo stack;
        std::string enqueuevalue;
        lab3::fifo tempinfix = infix_expression;

        while (!tempinfix.is_empty())
        {
            enqueuevalue = tempinfix.top();
            lab1::expressionstream temp (enqueuevalue);

            if (temp.next_token_is_int())
            {
                if (enqueuevalue == "-")
                {
                    if (stack.size() != 0)
                    {
                        unsigned size = stack.size();
                        for (int i = 0; i < size; i++)
                        {
                            if (stack.top() == "(")
                            {}
                            else if (operator_priority(stack.top()) > operator_priority(enqueuevalue) ||
                                     operator_priority(stack.top()) == operator_priority(enqueuevalue))
                            {
                                postfix_expression.enqueue(stack.top());
                                stack.pop();
                            }
                            else
                                continue;
                        }
                    }

                    stack.push(enqueuevalue);
                }
                else
                    postfix_expression.enqueue(enqueuevalue);
                // enqueue int value to postfix;
            }
            else if (temp.next_token_is_op())
            {
                if (stack.size() != 0)
                {
                    unsigned size = stack.size();
                    for (int i = 0; i < size; i++)
                    {
                        if (stack.top() == "(")
                        {}
                        else if (operator_priority(stack.top()) > operator_priority(enqueuevalue) ||
                                 operator_priority(stack.top()) == operator_priority(enqueuevalue))
                        {
                            postfix_expression.enqueue(stack.top());
                            stack.pop();
                        }
                        else
                            continue;
                    }
                }
                stack.push(enqueuevalue);
            }
            else if (temp.next_token_is_paren_open())
            {
                stack.push(enqueuevalue);
            }
            else if (temp.next_token_is_paren_close())
            {
                if (stack.size() == 0)
                    throw 4;
                while (stack.top() != "(")
                {
                    postfix_expression.enqueue(stack.top());
                    stack.pop();
                }
                stack.pop();
            }
            else
                throw 4;
            tempinfix.dequeue();
        }
        //^Finish all the value inside the infix;

        if (stack.size() != 0)
        {
            int remain = stack.size();
            for (int i = 0; i<remain; i++)
            {
                if (stack.top() ==")" || stack.top() =="(")
                    throw 4;
                else
                    postfix_expression.enqueue(stack.top());
                stack.pop();
            }
        }
    }

    calculator::calculator() {};

    calculator::calculator(std::string &input_expression)
    {
        parse_to_infix(input_expression);
        convert_to_postfix(infix_expression);
    }

    //aa = std::to_string(all);
    int lab4::calculator::calculate()
    {
        int answer = 0;
        int cal1 = 0;
        int cal2 = 0;
        std::string pushback;

        lab3::lifo stack;
        lab3::fifo temppost = postfix_expression;
        unsigned size = postfix_expression.size();
        std::string value;

        for (int i=0; i<size; i++)
        {
            value = temppost.top();
            lab1::expressionstream temp (value);
            if (temp.next_token_is_int())
            {
                if (value == "-")
                {
                    cal1 = std::stoi(stack.top());
                    stack.pop();
                    cal2 = std::stoi(stack.top());
                    stack.pop();

                    answer = cal2 - cal1;
                    pushback = std::to_string(answer);
                    stack.push(pushback);
                }
                else
                    stack.push(value);
            }
            else if (temp.next_token_is_op())
            {
                cal1 = std::stoi(stack.top());
                stack.pop();
                cal2 = std::stoi(stack.top());
                stack.pop();
                if (value == "+")
                {
                    answer = cal2 + cal1;
                }
                else if (value == "-")
                {
                    answer = cal2 - cal1;
                }
                else if (value == "*")
                {
                    answer = cal2 * cal1;
                }
                else if (value == "/")
                {
                    answer = cal2 / cal1;
                }
                else
                    throw 4;
                pushback = std::to_string(answer);
                stack.push(pushback);
            }
            temppost.dequeue();
        }
        return answer;
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS)
    {
        unsigned size1 = RHS.infix_expression.size();
        unsigned size2 = RHS.postfix_expression.size();

        stream << std::string("Infix: ");
        for (int i=0; i<size1-1; i++)
        {
            stream << RHS.infix_expression.top();
            stream << std::string(",");
            RHS.infix_expression.dequeue();
        }
        stream << RHS.infix_expression.top();
        stream<<std::string("\n");
        stream << std::string("Postfix: ");
        for (int i=0; i<size2-1; i++)
        {
            stream << RHS.postfix_expression.top();
            stream << std::string(",");
            RHS.postfix_expression.dequeue();
        }
        stream << RHS.postfix_expression.top();
        return stream;
    } // Output

    std::istream &operator>>(std::istream& stream, calculator &RHS)
    {
        std::istreambuf_iterator<char> eos;
        std::string input (std::istreambuf_iterator<char>(stream),eos);

        while(RHS.infix_expression.is_empty() != true)
            RHS.infix_expression.dequeue();
        while(RHS.postfix_expression.is_empty() != true)
            RHS.postfix_expression.dequeue();

        RHS.parse_to_infix(input);
        RHS.convert_to_postfix(RHS.infix_expression);

        return stream;
    }// Input

}