#include "lifo.h"

namespace lab3{
    lifo::lifo() {
        lifo_storage.reserve(100);
        index = 0;
    }

    lifo::lifo(std::string input_string) {
        lifo_storage.reserve(100);
        index = 0;
        push(input_string);
    }

    lifo::lifo(const lifo &original) {
        lifo_storage.reserve(original.lifo_storage.capacity());
        index = original.index;
        lifo_storage = original.lifo_storage;
    }

    lifo::~lifo() { // not needed
    }

    lifo &lifo::operator=(const lifo &right) {
        if (&right == this)
            return *this;
        else {
            lifo_storage.reserve(right.lifo_storage.capacity());
            index = right.index;
            for(int i=0; i<lifo_storage.capacity(); i++) {
                lifo_storage[i] = right.lifo_storage[i];
            }
            return *this;
        }
    }

    bool lifo::is_empty() const {
        return (size() == 0);
    }

    int lifo::size() const {
        return index;
    }

    std::string lifo::top() const {
        if(is_empty()) {
            throw "Stack is empty";
        }
        else
            return lifo_storage[index-1];
    }

    void lifo::push(std::string input) {
        lifo_storage[index] = input;
        index++;
    }

    void lifo::pop() {
        if(is_empty()) {
            throw "Stack is empty";
        }
        else {
            index--;
        }
    }
}