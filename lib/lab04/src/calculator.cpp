

#include <string>
#include "calculator.h"
int operator_priority(std::string operator_in);
bool is_number (std::string input_string);
bool is_operator(std::string input_string);
namespace lab4 {
    void calculator::parse_to_infix(std::string &input_expression) {
        std::string temp = "";
        int Blank = 0;
        int i = 0;
        int size = input_expression.size();
        while (i < size) {
            if (input_expression[i] == '') {
                if (Blank == 0) {
                    i++;

                }
                else{
                    infix_expression.enqueue(temp);
                    temp="";
                    i++;
                    Blank=0;
                }
            }
            else{
                temp+=input_expression[i];
                i++;
                Blank++;
            }

        }
    }

    void calculator::convert_to_postfix(lab3::fifo infix_expression) {
        lab3::lifo Stack;
        while( !infix_expression.is_empty()) {
            lab1::expressionstream steam(infix_expression.top());
            if(steam.next_token_is_int()){
                if(infix_expression.top() == "-") {
                    int a = 0;
                    if(Stack.top() == "("){
                        a = 1;
                    }
                    while(!Stack.is_empty() && operator_priority(Stack.top()) >= operator_priority(infix_expression.top()) && a != 1){
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
                int a = 0;
                if(Stack.top() == "("){
                    a = 1;
                }
                while(!Stack.is_empty() && operator_priority(Stack.top()) >= operator_priority(infix_expression.top()) && a != 1){
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


    calculator::calculator() {

    }

    calculator::calculator(std::string &input_expression) {
        parse_to_infix(input_expression);
        convert_to_postfix(infix_expression);
    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        std::string temp;
        std::string expression;
        while (stream >> temp) {
            expression.append(temp);
        }
        while (!RHS.infix_expression.is_empty()) {
            RHS.infix_expression.dequeue();
        }
        while (!RHS.postfix_expression.is_empty()) {
            RHS.postfix_expression.dequeue();
        }
        RHS.parse_to_infix(expression);
        RHS.convert_to_postfix(RHS.infix_expression);
        return stream;
    }


    int lab4::calculator::calculate() { lab3::lifo cal;
        int all = 0;
        int N1= 0;
        int N2 = 0;
        std::string aa;
        lab3::fifo copy;
        while(!postfix_expression.is_empty()){
            lab1::expressionstream temp(postfix_expression.top());
            copy.enqueue(postfix_expression.top());
            if(temp.next_token_is_int()) {
                if (postfix_expression.top() == "-") {
                    N2 = stoi(cal.top());
                    cal.pop();
                    N1 = stoi(cal.top());
                    cal.pop();
                    if (postfix_expression.top() == "-")
                        all = N1-N2;
                    aa = std::to_string(all);
                    postfix_expression.dequeue();
                    cal.push(aa);
                } else {
                    cal.push(postfix_expression.top());
                    postfix_expression.dequeue();
                }
            }
            else if(temp.next_token_is_op()){
                N2 = stoi(cal.top());
                cal.pop();
                N1 = stoi(cal.top());
                cal.pop();
                if(postfix_expression.top() == "+"){
                    all = N1+N2;
                }
                else if(postfix_expression.top() == "-"){
                    all = N1-N2;
                }
                else if(postfix_expression.top() == "*"){
                    all = N1*N2;
                }
                else if(postfix_expression.top() == "/"){
                    all = N1/N2;
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
        lab3::fifo infix_copy(RHS.infix_expression);
        stream << "Infix: ";
        while (!infix_copy.is_empty()) {
            stream << infix_copy.top() << ",";
            infix_copy.dequeue();
        }
        lab3::fifo postfix_copy(RHS.postfix_expression);
        stream << "\nPostfix: ";
        while (!postfix_copy.is_empty()) {
            stream << postfix_copy.top() << (postfix_copy.size() == 1 ? "" : ",");
            postfix_copy.dequeue();
        }
        return stream;
    }

    // AUXILIARY FUNCTIONS
    bool is_number (std::string input_string){
    if(input_string>="0"&&input_string<="9"){
        return true;
    }

}

    bool is_operator(std::string input_string){
        if (input_string=="+"||"-"||"*"||"/"||"("||")"){
            return true;
        }
    }

    int get_number(std::string input_string){
        return stoi(input_string);
    }

    std::string get_operator(std::string input_string){
        lab3::lifo pop(input_string);
    }

    int operator_priority(std::string operator_in){
        int weight;
        if(operator_in=="+"||"-"){
            weight=2;
        }
        else if (operator_in=="*"||"/") {
            weight = 3;

        }
        return weight;
    }
}