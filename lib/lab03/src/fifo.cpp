#include "fifo.h"

namespace lab3{
    fifo::fifo() {
        fifo_storage.reserve(100);
        front_index = 0;    // the queue is empty so front and back should be the same
        back_index =0;
    }

    fifo::fifo(std::string input_string) {
        fifo_storage.reserve(100);
        front_index = 0;
        back_index = 1;
        fifo_storage.append(input_string);
    }

    fifo::fifo(const fifo &original) {
        fifo_storage.reserve(original.fifo_storage.capacity());
        front_index = original.front_index;
        back_index = original.back_index;
        fifo_storage = original.fifo_storage;
    }

    fifo::~fifo() { // not needed
    }

    fifo &fifo::operator=(const fifo &right) {
        if (&right == this)
            return *this;
        fifo_storage.reserve(right.fifo_storage.capacity());
        front_index = right.front_index;
        back_index = right.back_index;
        for(int i = 0; i < right.fifo_storage.capacity(); i++) {
            fifo_storage[i] = right.fifo_storage[i];
        }
        return *this;
    }

    bool fifo::is_empty() const {
        return (size() == 0);
    }

    int fifo::size() const {
        int count = 0;
        if(front_index == back_index)
            return count;
        else if (front_index < back_index) {
            count = back_index-front_index;
        }
        else if(front_index > back_index) {
            count = (fifo_storage.capacity() - front_index) + back_index;
        }
        return count;
    }

    std::string fifo::top() const {
        if(is_empty()) {
            throw "Empty";
        }
        else
            return (fifo_storage[front_index]);
    }

    void fifo::enqueue(std::string input) {
        if (is_empty()) {
            fifo_storage.append(input);
            back_index++;
        }
        else if (front_index == back_index){
            front_index = front_index % 100;
            back_index = (back_index+1) % 100;
            fifo_storage.append(input);
        }
        else {
            fifo_storage.append(input);
            back_index++;
        }
    }

    void fifo::dequeue() {
        if(is_empty()) {
            throw "Queue is empty";
        }
        else if(front_index == back_index){
            front_index = front_index  % 100;
            back_index = back_index % 100;
        }
        else {
            front_index++;
        }
    }
}