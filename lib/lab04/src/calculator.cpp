

#include <string>
#include "calculator.h"
bool is_number (std::string input_string);
bool is_operator(std::string input_string);
namespace lab4 {
    void calculator::parse_to_infix(std::string &input_expression) {
        std::string::iterator position = input_expression.begin();
        std::string::iterator end = input_expression.end();
        for (position; position != end && *position == ' '; position++) {
            if (is_number(std::string(position, position + 1))) {
                infix_expression.enqueue(std::string(position, position + 1));
            }
            if (is_operator(std::string(position, position + 1))) {
                infix_expression.enqueue(std::string(position, position + 1));
            } else {
                throw "Not a number or operator";
            }
        }
    }

    void calculator::convert_to_postfix(lab3::fifo infix_expression) {
        //std::string::iterator position=input_expression.begin()
        // tiers, maybe a while loop instead of a for loop that decremeents
        lab3::lifo op_queue;
        for(int i = 0; i<=infix_expression.size(); i++){ //Might try a counter
            std::string temp = infix_expression.top(); //if we dequeue we don't put it in anything we just take that mem out
            bool is_number(std::string); //Some way to check
            if(is_number(temp) == true) { // Need to find a way to see if the top is a number or a char
                postfix_expression.enqueue(infix_expression.top());
            }
            else{
                op_queue.push(temp); // Need a way to implement priority into this
            }
            //This will have the new postfix and we will put it in the calculate function
        }
        //use postfix expression
        for(int i=0; i<i<infix_expression.size(); i++){
            std::string get_operator(std::string input_expression);
        }

    }

    calculator::calculator() {

    }

    calculator::calculator(std::string &input_expression) {
        parse_to_infix(input_expression);
        convert_to_postfix(infix_expression);
    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        return stream;
    }

    int lab4::calculator::calculate() {
        return 0;
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
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
        lab3::fifo::dequeue();


    }

    std::string get_operator(std::string input_string){
        lab3::lifo pop(input_string);
    }

    int operator_priority(std::string operator_in){
        int weight;
        if(operator_in=="+"||"-"){
            weight=1;
        }
        else if (operator_in=="*"||"/"){
            weight=2;
        }
        else if(operator_in=="^"){
            weight=3;
        }
        else if(operator_in=="("||")"){
            weight=4;
        }
        return weight;
    }
}