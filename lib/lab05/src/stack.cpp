#include "stack.h"
namespace lab5{
    stack::stack() {

    }

    stack::stack(std::string &data) {
storage_structure.insert(data.0);
    }

    stack::stack(const stack &original) {
stack temp;
        temp=original;
        for(int i=0; i<temp.queueSize();i++){
            storage_structure.append(temp.top());
            temp.pop();
        }
    }

    stack::~stack() {
        for(int i=0;i<storage_structure.listSize();i++){
            storage_structure.remove(i);
        }

    }

    stack &stack::operator=(const stack &RHS) {
        //return <#initializer#>;
    }

    bool stack::isEmpty() const {
        return false;
    }

    unsigned stack::queueSize() const {
        return 0;
    }

    std::string stack::top() const {
        //return std::__cxx11::string();
    }

    void stack::push(const std::string &data) {

    }

    void stack::pop() {

    }

    std::ostream& operator<<(std::ostream &stream, stack &RHS) {
        return stream;
    }

    std::istream& operator>>(std::istream &stream, stack &RHS) {
        return stream;
    }
}