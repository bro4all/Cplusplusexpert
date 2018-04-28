#include "lifo.h"
namespace lab3{
    lifo::lifo() {
        index = 0;
        lifo_storage.newLength(100);
        tofix = true;
    }
    lifo::lifo(std::string input_string) {
        lifo_storage.newLength(100);
        lifo_storage[0] = input_string;
        index = 0;
        tofix = false;
    }
    lifo::lifo(const lifo &original) {
        lifo_storage.reserve(original.lifo_storage.capacity());
        lifo_storage = original.lifo_storage;
        index = original.index;
        tofix = original.tofix;
    }
    lifo::~lifo() = default;
    lifo &lifo::operator=(const lifo &right) {
        lifo_storage.reserve(right.lifo_storage.capacity());
        lifo_storage = right.lifo_storage;
        index = right.index;
        tofix = right.tofix;
        return *this;
    }
    bool lifo::is_empty() {
        return tofix;
    }
    int lifo::size(){
        if (tofix) {
            return 0;
        }
        else {
            return (index + 1);
        }
    }
   std::string lifo::top(){
        if (is_empty()){
            throw "empty";
        }
        else{
            return lifo_storage[index];
        }
    }
    void lifo::push(std::string input) {
        if (index == 100) {
            throw "full";
        }
        else if (tofix) {
            tofix = false;
            index = 0;
            lifo_storage[index] = input;

        }
        else {
            tofix = false;
            index++;
            lifo_storage[index] = input;

        }
    }
    void lifo::pop() {
        if (is_empty())
            throw "nothing to pop";
        else if (index == 0) {
            tofix = true;
            index = 0;
            lifo_storage.newLength(101);
        }
        else {
            index--;
        }
    }
}