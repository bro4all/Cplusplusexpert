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
        fifo_storage[0]=input_string;
        fifo_storage.reserve(100);
       front_index=0;
        back_index=0;
    }

    fifo::fifo(const fifo &original) {

        fifo_storage.reserve(100);
        this->fifo_storage=original.fifo_storage;
        this->front_index=original.front_index;
        this->back_index=original.back_index;
        }


    fifo::~fifo() {
        front_index=-1;
        back_index=-1;

    }

    fifo &fifo::operator=(const fifo &right) {
        if (&right == this){
            return (*this);
        }
        fifo_storage.reserve(100);
       this->front_index = right.front_index;
        this->back_index = right.back_index;

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

    std::string fifo::top() const  {
        //return std::__cxx11::string();
        return fifo_storage[front_index];
    }

    void fifo::enqueue(std::string input) {
        back_index++;
        fifo_storage[back_index]=input;
        if(fifo_storage.capacity()<=back_index){
            fifo_storage.reserve(fifo_storage.capacity()+20);

        }
    }

    void fifo::dequeue() {
        if(!is_empty()) {// In queue you would always take from the front, so you need to make sure that the fifo storage isnt empty
            ++front_index;
        }
        else{
            throw"ERROR, out of bounds";
        }
    }
}
