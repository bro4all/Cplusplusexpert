#include "fifo.h"

namespace lab3{
    fifo::fifo() {
        lab2::stringVector fifo_storage;
        fifo_storage.reserve(100);
        front_index=0;
        back_index=0;
        //Reserve 100 spaces in fifo_storage
    }

    fifo::fifo(std::string input_string) {
        fifo_storage.reserve(100);
        fifo_storage[0]=input_string;
       front_index=0;
        back_index=0;
    }

    fifo::fifo(const fifo &original) {

        fifo_storage.reserve(original.fifo_storage.capacity());
        front_index=original.front_index;
        back_index=original.back_index;
        for(int i=0;i<original.fifo_storage.size();i++){
            fifo_storage[i]=original.fifo_storage[i];
        }
    }

    fifo::~fifo() {
        front_index=-1;
        back_index=-1;

    }

    fifo &fifo::operator=(const fifo &right) {
        if (&right == this){
            return (*this);
        }
        fifo_storage.reserve(right.fifo_storage.capacity());
        front_index = right.front_index;
        back_index = right.back_index;
        for(int i = 0;i<right.fifo_storage.size();i++){
            fifo_storage[i] = right.fifo_storage[i];
        } //return <#initializer#>;
    }

    bool fifo::is_empty() const {
        //return false;
        if(front_index == -1 || front_index==back_index){
            return true;
        }
        return false;

        //return false;
    }

    unsigned fifo::size() const {
            unsigned int temp;
            if(front_index<back_index){
                temp = back_index-front_index+1;
            }
            else{
                //If back index < front index then the list has wrapped around
                temp = (100-front_index)+back_index+1;
                //fifo_storave.size() - front index = how many until end.
                //Adding the back index +1 should be how many items are in that section
            }
            return (temp);
        }

    std::string fifo::top() const {
        //return std::__cxx11::string();
        return fifo_storage[front_index];
    }

    void fifo::enqueue(std::string input) {
        fifo_storage[back_index]=input;
        back_index++;
        if(fifo_storage.capacity()<=back_index){
            fifo_storage.reserve(fifo_storage.capacity()+20);

        }
    }

    void fifo::dequeue() {
        front_index++;
        if(front_index==back_index){
            front_index=-1;
            back_index=-1;
        }

    }
}