#include <string>
#include "calculator.h"
#include <stdexcept>
#include <iostream>
namespace lab4 {
    int precedent(std::string input_string)
    {
        lab1::expressionstream steam1(input_string);
        int priority;
        if (steam1.next_token_is_op())
        {
            if (input_string == "*" ||input_string == "/") {
                priority = 3;
            }
            else if (input_string == "+" || input_string == "-") {
                priority = 0;
            }
            else {
                throw std::invalid_argument("operater out of scope");
            }
        }
        return priority;
    }
    void calculator::parse_to_infix(std::string &input_expression) {
        lab1::expressionstream temp(input_expression);
        std::string check = temp.get_current_token();
        while(check != "\0")
        {
            infix_expression.enqueue(check);
            check = temp.get_next_token();
        }
    }
    void calculator::convert_to_postfix(lab3::fifo infix_expression) {
        lab3::lifo Stack;
        while( !infix_expression.is_empty()) {
            lab1::expressionstream steam(infix_expression.top());
            if(steam.next_token_is_int()){
                if(infix_expression.top() == "-") {
                    if(Stack.top() == "("){
                    }
                    while(!Stack.is_empty() && precedent(Stack.top()) >= precedent(infix_expression.top())){
                        postfix_expression.enqueue(Stack.top());
                        Stack.pop();
                    }
                    Stack.push(infix_expression.top());
                    infix_expression.dequeue();
                }
                postfix_expression.enqueue(infix_expression.top());
                infix_expression.dequeue();
            }
            else if(steam.next_token_is_op()) {
                if(Stack.top() == "("){
                }
                while(!Stack.is_empty() && precedent(Stack.top()) >= precedent(infix_expression.top())){
                    postfix_expression.enqueue(Stack.top());
                    Stack.pop();
                }
                Stack.push(infix_expression.top());
                infix_expression.dequeue();
            }
            else if(steam.next_token_is_paren_open()){
                Stack.push(infix_expression.top());
                infix_expression.dequeue();
            }
            else if (steam.next_token_is_paren_close()){
                if(Stack.top() != "("){
                    postfix_expression.enqueue(Stack.top());
                    Stack.pop();
                }
                else if(Stack.top() == "("){
                    infix_expression.dequeue();
                    Stack.pop();
                }
            }
        }
        if(infix_expression.is_empty()) {
            while (!Stack.is_empty()) {
                postfix_expression.enqueue(Stack.top());
                Stack.pop();
            }
        }
    }
    calculator::calculator() = default;
    calculator::calculator(std::string &input_expression) {
        parse_to_infix(input_expression);
        convert_to_postfix(infix_expression);
    }
    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        std::string input;
        stream >> input;
        RHS.parse_to_infix(input);
        RHS.convert_to_postfix(RHS.infix_expression);
        return stream;
    }
    int lab4::calculator::calculate() {
        lab3::lifo cal;
        int all = 0;
        int numb1 = 0;
        int numb2 = 0;
        std::string aa;
        lab3::fifo copy;
        while(!postfix_expression.is_empty()){
            lab1::expressionstream temp(postfix_expression.top());
            copy.enqueue(postfix_expression.top());
            if(temp.next_token_is_int()) {
                if (postfix_expression.top() == "-") {
                    numb2 = stoi(cal.top());
                    cal.pop();
                    numb1 = stoi(cal.top());
                    cal.pop();
                    if (postfix_expression.top() == "-")
                        all = numb1 - numb2;
                    aa = std::to_string(all);
                    postfix_expression.dequeue();
                    cal.push(aa);
                } else {
                    cal.push(postfix_expression.top());
                    postfix_expression.dequeue();
                }
            }
            else if(temp.next_token_is_op()){
                numb2 = stoi(cal.top());
                cal.pop();
                numb1 = stoi(cal.top());
                cal.pop();
                if(postfix_expression.top() == "+"){
                    all = numb1 + numb2;
                }
                else if(postfix_expression.top() == "-"){
                    all = numb1 - numb2;
                }
                else if(postfix_expression.top() == "*"){
                    all = numb1 * numb2;
                }
                else if(postfix_expression.top() == "/"){
                    all = numb1 / numb2;
                }
                aa = std::to_string(all);
                postfix_expression.dequeue();
                cal.push(aa);
            }
        }
        postfix_expression = copy;
        return all;
    }
    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
        stream<<std::endl<<"infix_expression : "<<std::endl;
        while(!RHS.infix_expression.is_empty())
        {
            stream << RHS.infix_expression.top();
            RHS.infix_expression.dequeue();
            stream << " ";
        }
        stream <<std::endl<<"postfix string : "<<std::endl;
        while(!RHS.postfix_expression.is_empty()) {
            stream << RHS.postfix_expression.top();
            RHS.postfix_expression.dequeue();
            stream << " ";
        }
        stream<<std::endl<<std::endl<<std::endl;
        return stream;
    }