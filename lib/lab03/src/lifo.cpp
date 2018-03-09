#include "lifo.h"
namespace lab3{
    lifo::lifo() {
        lifo_storage.reserve(100);//You would need to reserve 100 spaces because of the readme
        index=0;//Set the index of the array = to 0
    }
    lifo::lifo(std::string input_string) {
        lifo_storage.reserve(100);
        lifo_storage.append(input_string);// same as the first constructor but you are appending an input_string
        index=1;
    }
    lifo::lifo(const lifo &original) {
        index = original.index;//Copies the information from the private to &original. had to add const to the lab2 std::string &operator[](unsigned position) in order for this to work.
        for(int i=0; i<index;i++){
            lifo_storage[i]=original.lifo_storage[i];// Have to do an array to copy each array element onto original
        }
    }
    lifo::~lifo() {
        lifo_storage.set_size(0);// same as fifo, but you just need to make index =0
        index=0;
    }
    lifo &lifo::operator=(const lifo &right) {// Same as fifo, assignment operator
        lifo_storage.reserve(right.lifo_storage.capacity());
        index= right.index;
        for(int i=0; i<= index; i++){
            lifo_storage[i]=right.lifo_storage[i];
        }
        //return <#initializer#>;
    }
    bool lifo::is_empty() const {// It should return true unless the index is greater than or equal to 1
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