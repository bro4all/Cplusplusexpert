#include "expressionstream.h"
#include <string>
#include "calculator.h"
#include <sstream>


namespace lab4 {
    bool isNumber(std::string inputstring);

    bool isOperator(std::string inputstring);

    int operator_priority(std::string input_string);

    void calculator::parse_to_infix(std::string &input_expression) {
        lab1::expressionstream temp(input_expression);
        std::string token = temp.get_current_token();
        while (token != "\0") {
            infix_expression.enqueue(token);
            token = temp.get_next_token();
        }
    }

    void calculator::convert_to_postfix(lab3::fifo infix_expression) {
        lab3::lifo temp_stack;
        std::string temp_string;
        while (!infix_expression.is_empty()) {
            temp_string = infix_expression.top();
            infix_expression.dequeue();
            if (isNumber(temp_string)) {
                postfix_expression.enqueue(temp_string);
            } else if (isOperator(temp_string)) {
                while (!temp_stack.is_empty() &&
                       operator_priority(temp_string) <= operator_priority(temp_stack.top())) {
                    postfix_expression.enqueue(temp_stack.top());
                    temp_stack.pop();
                }
                temp_stack.push(temp_string);
            } else if (temp_string == "(") {
                temp_stack.push(temp_string);
            } else if (temp_string == ")") {
                while (temp_stack.top() != "(") {
                    postfix_expression.enqueue(temp_stack.top());
                    temp_stack.pop();
                }
                temp_stack.pop();
            }
        }
        while (!temp_stack.is_empty()) {
            postfix_expression.enqueue(temp_stack.top());
            temp_stack.pop();
        }
    }

    calculator::calculator() {};

    calculator::calculator(std::string &input_expression) {
        parse_to_infix(input_expression);
        convert_to_postfix(infix_expression);
    }
    int lab4::calculator::calculate() {
        lab3::lifo cal;
        lab3::fifo copy;
        int result = 0;
        int num1 = 0;
        int num2 = 0;
        std::string aa;
        while(!postfix_expression.is_empty()){
            lab1::expressionstream temp(postfix_expression.top());
            copy.enqueue(postfix_expression.top());
            if(temp.next_token_is_int()) {
                if (postfix_expression.top() == "-") {
                    num2 = stoi(cal.top());
                    cal.pop();
                    num1 = stoi(cal.top());
                    cal.pop();
                    result = num1 - num2;
                    aa = std::to_string(result);
                    postfix_expression.dequeue();
                    cal.push(aa);
                }
                else {
                    cal.push(postfix_expression.top());
                    postfix_expression.dequeue();
                }
            }
            else if(temp.next_token_is_op()){
                num2 = stoi(cal.top());
                cal.pop();
                num1 = stoi(cal.top());
                cal.pop();
                if(postfix_expression.top() == "+"){
                    result = num1 + num2;
                }
                else if(postfix_expression.top() == "-"){
                    result = num1 - num2;
                }
                else if(postfix_expression.top() == "*"){
                    result = num1 * num2;
                }
                else if(postfix_expression.top() == "/"){
                    result = num1 / num2;
                }
                aa = std::to_string(result);
                postfix_expression.dequeue();
                cal.push(aa);
            }
        }
        postfix_expression = copy;
        return result;
    }


    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
        unsigned size1 = RHS.infix_expression.size();
        unsigned size2 = RHS.postfix_expression.size();

        stream << std::string("Infix: ");
        for (int i = 0; i < size1 - 1; i++) {
            stream << RHS.infix_expression.top();
            stream << std::string(",");
            RHS.infix_expression.dequeue();
        }
        stream << RHS.infix_expression.top();
        stream << std::string("\n");
        stream << std::string("Postfix: ");
        for (int i = 0; i < size2 - 1; i++) {
            stream << RHS.postfix_expression.top();
            stream << std::string(",");
            RHS.postfix_expression.dequeue();
        }
        stream << RHS.postfix_expression.top();
        return stream;
    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        std::istreambuf_iterator<char> eos;
        std::string input(std::istreambuf_iterator<char>(stream), eos);

        while (RHS.infix_expression.is_empty() != true)
            RHS.infix_expression.dequeue();
        while (RHS.postfix_expression.is_empty() != true)
            RHS.postfix_expression.dequeue();

        RHS.parse_to_infix(input);
        RHS.convert_to_postfix(RHS.infix_expression);

        return stream;
    }
    int operator_priority(std::string operator_in) {
        int importance = 0;
        if (operator_in == "+" || operator_in == "-") {
            importance = 2;
        }
        if (operator_in == "*" || operator_in == "/") {
            importance = 3;
        }
        return importance;
    }
    bool isNumber(std::string inputstring){
        for(int i=0; i< inputstring.length();i++)
        {
            if((inputstring[i] >= '0' && inputstring[i] <= '9'))
                return true;
            else
                return false;
        }
    }
    bool isOperator(std::string inputstring) {
        for (int i=0; i<inputstring.length();i++){
            if (inputstring[i] == '+' || inputstring[i] == '-' || inputstring[i] == '*' || inputstring[i] == '/')
                return true;
            else
                return false;
        }
    }
}
