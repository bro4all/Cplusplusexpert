#include "fifo.h"
namespace lab3{
    fifo::fifo() {
        front_index = 0;
        back_index = 0;
        tofix = true;
        fifo_storage.newLength(101);

    }
    fifo::fifo(std::string input_string) {
        tofix = false;
        fifo_storage.newLength(101);
        fifo_storage[0] = input_string;
        front_index = 0;
        back_index = 0;

    }
    fifo::fifo(const fifo &original) {
        tofix = original.tofix;
        front_index = original.front_index;
        back_index = original.back_index;
        fifo_storage = original.fifo_storage;
    }
    fifo::~fifo(){
        tofix = true;
        front_index = 0;
        back_index = 0;

    }
    fifo &fifo::operator=(const fifo &right) {
        tofix = right.tofix;
        front_index = right.front_index;
        back_index = right.back_index;
        fifo_storage = right.fifo_storage;
        return *this;
    }
    bool fifo::is_empty()
    {
        if (tofix){
            return true;
        }
        else{
            return false;
        }
    }
    int fifo::size()
    {
        if (tofix) {
            return 0;
        }
        else if (front_index == back_index) {
            return 1;
        }
        else if (front_index < back_index) {
            return (back_index - front_index + 1);
        }
        else {
            return ((back_index + 1) + (100 - front_index + 1));
        }
    }
    std::string fifo::top() {
        if (tofix) {
            throw "no queue top";
        }
        else {
            return fifo_storage[front_index];
        }
    }
    void fifo::enqueue(std::string input)
    {
        if (tofix) {
            front_index = 0;
            back_index = 0;
            tofix = false;
        }
        else if (back_index == 100) {
            if (front_index == 0) {
                throw "front is empty";
            }
            else {
                back_index = 0;
            }
        }
        else {
            back_index++;
        }
        fifo_storage[back_index] = input;
    }
    void fifo::dequeue()
    {
        if (is_empty()) {
            throw "queue is empty   ";
        }
        else if (front_index == back_index) {
            tofix = true;
            front_index = 0;
            back_index = 0;
            fifo_storage.newLength(101);
        }
        else {
            if (front_index == 100) {
                front_index = 0;
            }
            else {
                front_index++;
            }
        }
    }
}