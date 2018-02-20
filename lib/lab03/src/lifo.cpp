#include "lifo.h"

namespace lab3 {
    lifo::lifo() {
        lifo_storage.reserve(100);
        index = -1;//Reserve 100 spaces in lifo_storage
    }

    lifo::lifo(std::string input_string) {
        lifo_storage.reserve(100);
        lifo_storage[0] = input_string;
        index = 0;
    }

    lifo::lifo(const lifo &original) {
        lifo_storage.reserve(original.lifo_storage.capacity());
        index = original.index;
        for (int i = 0; i <= index; i++) {
            lifo_storage[i] = original.lifo_storage[i];
        }

    }

    lifo::~lifo() {
        index = -1;

    }

    lifo &lifo::operator=(const lifo &right) {
        //return <#initializer#>;
        lifo_storage.reserve(right.lifo_storage.capacity());
        index = right.index;
        for (int i = 0; i <= index; i++) {
            lifo_storage[i] = right.lifo_storage[i];
        }

        return *this;
    }


    bool lifo::is_empty() const {
        if (index == -1 || ) {
            return true;
        } else {
            return false;
        }
        //return false;
    }

    unsigned lifo::size() const {
        int temp;
        if(index>-1) {
            for (int i = 0; i <= index; i++) {
                temp++;
            }
        }
        else{
            temp=0;
        }
        return temp;

    }




    std::string lifo::top() const {
        return lifo_storage[index]; //return std::__cxx11::string();
    }

    void lifo::push(std::string input) {if(index == lifo_storage.capacity()-1){
            lifo_storage.reserve(lifo_storage.capacity() + 20);
        }
        lifo_storage[++index] = input;

    }

    void lifo::pop() {
        if(index > -1)
            index--;
    }
    }