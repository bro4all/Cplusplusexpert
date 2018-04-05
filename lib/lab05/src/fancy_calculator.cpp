#include "fancy_calculator.h"
#include "stack.h"
#include "queue.h"


namespace lab5{
    bool is_number(std::string input_string);
    bool is_operator(std::string input_string);
    int operator_priority(std::string operator_in);

    void calculator::parse_to_infix(std::string &input_expression) {
        int counter = 0;
        std::string temp_string;
        for (counter; counter < input_expression.length(); counter++) {
            if(input_expression[counter] == ' ')
                counter++;
            if(is_number(input_expression)) {
                while (is_number(input_expression.substr(counter,1))) {
                    temp_string.append(input_expression);
                    counter++;
                }
                infix_expression.enqueue(temp_string);
                temp_string = "";
            }
            if(is_operator(input_expression.substr(counter,1))) {
                temp_string.append(input_expression);
                counter++;
                infix_expression.enqueue(temp_string);
                temp_string = "";
            }
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
            if (is_operator(temp_string)) {
                while (!temp_stack.isEmpty() && operator_priority(temp_string) <= operator_priority(temp_stack.top())) {
                    postfix_expression.enqueue(temp_stack.top());
                    temp_stack.pop();
                }
            }
            temp_stack.push(temp_string);
        }
        if (temp_string == "(") {
            temp_stack.push(temp_string);
        }
        if (temp_string == ")") {
            while (temp_stack.top() != "(") {
                postfix_expression.enqueue(temp_stack.top());
                temp_stack.pop();
            }
            temp_stack.pop();
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
        std::string temp_string;
        stream >> temp_string;
        RHS.infix_expression.enqueue(temp_string);
        return stream;
    }

    int calculator::calculate() {
        lab5::stack cal;
        int num1 = 0;
        int num2 = 0;
        int result = 0;
        std::string aa;
        std::string token = postfix_expression.top();
        while (!postfix_expression.isEmpty()){
            cal.push(token);
            num1 = std::stoi(cal.top());
            postfix_expression.dequeue();
            if(is_number(token)){
                cal.push(token);
                num2 = std::stoi(cal.top());
                postfix_expression.dequeue();
            }
            else {
                postfix_expression.dequeue();
                if(token == "+"){
                    result = num1+num2;
                }
                if (token == "-"){
                    result = num1-num2;
                }
                if (token == "*"){
                    result = num1*num2;
                }
                if(token == "/"){
                    result = num1/num2;
                }
                aa = std::to_string(result);
                postfix_expression.enqueue(aa);
            }
        }
        return std::stoi(postfix_expression.top());
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
        for (int i =0; i < input_string.length();i++) {
            if (isdigit(input_string[i])) {
                return true;
            }
            else
                return false;
        }
    }

    bool is_operator(std::string input_string){
        for (int i=0; i<input_string.length();i++){
            if (input_string[i] == '+' || input_string[i] == '-' || input_string[i] == '*' || input_string[i] == '/')
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
