#include "fifo.h"
namespace lab3{
    fifo::fifo() {
        fifo_storage.reserve(100);
        front_index =0;
        back_index=0;
    }
    fifo::fifo(std::string input_string) {
        front_index=0;
        back_index=0;
        fifo_storage.reserve(100);
        fifo_storage.append(input_string);
    }
    fifo::fifo(const fifo &original) {
        fifo_storage.reserve(100);
        front_index = original.front_index;
        back_index= original.back_index;
        for(int i=0; i<back_index;i++){
            fifo_storage[i]=original.fifo_storage[i];
        }
    }
    fifo::~fifo() {
        fifo_storage.set_size(0);
        front_index =-1;//
    }
    fifo &fifo::operator=(const fifo &right) {
        fifo_storage.reserve(right.fifo_storage.capacity());
        front_index = right.front_index;
        back_index = right.back_index;
        for(int i=0;i<=fifo_storage.size();i++){
            fifo_storage[i]=right.fifo_storage[i];
        }
    }
    bool fifo::is_empty() const {
        if(front_index>=back_index){
            return true;
        }
        else{
            return false;
        }
    }
    unsigned fifo::size() const {
        if(front_index<back_index){
            int count;
            count = back_index-(front_index) ;
            return count;
        }
        if(front_index>=back_index){
            int temp = back_index;
            unsigned back_index=front_index;
            unsigned front_index = temp;
            return back_index-front_index;
        }
        //return 0;
    }
    std::string fifo::top() const {
        return fifo_storage[front_index];
    }
    void fifo::enqueue(std::string input) {
        ++back_index;
        fifo_storage.append(input);
        if(fifo_storage.capacity()<=back_index-front_index){
            fifo_storage.reserve(fifo_storage.capacity()+1);
        }
    }
    void fifo::dequeue()  {
        front_index++;
        if(front_index > back_index){
            front_index =-1;
            back_index = -1;
        }
    }
}
