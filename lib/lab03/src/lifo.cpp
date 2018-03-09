#include "lifo.h"
namespace lab3{
    lifo::lifo() {
        lifo_storage.reserve(100);
        index=0;
    }
    lifo::lifo(std::string input_string) {
        lifo_storage.reserve(100);
        lifo_storage.append(input_string);
        index=1;
    }
    lifo::lifo(const lifo &original) {
        index = original.index;
        for(int i=0; i<index;i++){
            lifo_storage[i]=original.lifo_storage[i];
        }
    }
    lifo::~lifo() {
        lifo_storage.set_size(0);
        index=0;
    }
    lifo &lifo::operator=(const lifo &right) {
        lifo_storage.reserve(right.lifo_storage.capacity());
        index= right.index;
        for(int i=0; i<= index; i++){
            lifo_storage[i]=right.lifo_storage[i];
        }
        //return <#initializer#>;
    }
    bool lifo::is_empty() const {
        if(index>=1){
            return false;
        }
        else{
            return true;
        }
    }
    unsigned lifo::size() const {
        if(is_empty()==false){
            return index;
        }
        else {
            int nothing=0;
            return nothing;
        }
    }
    std::string lifo::top() const {
        return lifo_storage[index];
    }
    void lifo::push(std::string input) {
        ++index;
        lifo_storage[index]= input;
    }
    void lifo::pop() {
        if(index == -1){
            throw"ERROR, empty";
        }
        else{
            --index;
        }
    }
}