#include "fancy_calculator.h"
#include "stack.h"
#include "queue.h"


namespace lab5{
    bool is_number(std::string input_string);
    bool is_operator(std::string input_string);
    int operator_priority(std::string operator_in);

    void calculator::parse_to_infix(std::string &input_expression) {
        lab1::expressionstream temp(input_expression);
        std::string token = temp.get_current_token();
        while (token != "\0"){
            infix_expression.enqueue(token);
            token = temp.get_next_token();
        }
    }

    void calculator::convert_to_postfix(lab5::queue infix_expression) {
        lab5::stack temp_stack;
        std::string temp_string;
        while (!infix_expression.isEmpty()) {
            temp_string = infix_expression.top();
            infix_expression.dequeue();
            if (is_number(temp_string)) {
                postfix_expression.enqueue(temp_string);
            }
            else if (is_operator(temp_string)) {
                while (!temp_stack.isEmpty() && operator_priority(temp_string) <= operator_priority(temp_stack.top())) {
                    postfix_expression.enqueue(temp_stack.top());
                    temp_stack.pop();
                }
                temp_stack.push(temp_string);
            }
            else if (temp_string == "(") {
                temp_stack.push(temp_string);
            }
            else if (temp_string == ")") {
                while (temp_stack.top() != "(") {
                    postfix_expression.enqueue(temp_stack.top());
                    temp_stack.pop();
                }
                temp_stack.pop();
            }
        }
        while (!temp_stack.isEmpty()) {
            postfix_expression.enqueue(temp_stack.top());
            temp_stack.pop();
        }
    }

    calculator::calculator() {

    }

    calculator::calculator(std::string &input_expression) {
        parse_to_infix(input_expression);
        convert_to_postfix(infix_expression);
    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        std::string input;
        getline(stream,input);
        RHS.parse_to_infix(input);
        RHS.convert_to_postfix(RHS.infix_expression);
        return stream;
    }

    int calculator::calculate() {
        lab5::stack cal;
        lab5::queue copy;
        int result = 0;
        int num1 = 0;
        int num2 = 0;
        std::string aa;
        while(!postfix_expression.isEmpty()){
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
        while (!RHS.postfix_expression.isEmpty()){
            stream << RHS.postfix_expression.top() << " ";
            RHS.postfix_expression.dequeue();
        }
        return stream;
    }


    // AUXILIARY FUNCTIONS
    bool is_number(std::string input_string){
        for(int i=0; i< input_string.length();i++)
        {
            if((input_string[i] >= '0' && input_string[i] <= '9'))
                return true;
            else
                return false;
        }
    }

    bool is_operator(std::string input_string){
        for (int i=0; i<input_string.length();i++){
            if (input_string[i] == '+' || input_string[i] == '-' || input_string[i] == '*' || input_string[i] == '/' || input_string[i] == '^' || input_string[i] == '%')
                return true;
            else
                return false;
        }
    }

    int get_number(std::string input_string);

    std::string get_operator(std::string input_string);

    int operator_priority(std::string operator_in){
        int precedence;
        if (operator_in == "+" || operator_in == "-") {
            precedence = 2;
        }
        if (operator_in == "*" || operator_in == "/" || operator_in == "%") {
            precedence = 3;
        }
        if (operator_in == "^") {
            precedence = 9;
        }
        return precedence;
    }

}