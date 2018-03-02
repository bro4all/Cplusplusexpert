#include "fifo.h"
namespace lab3{
    fifo::fifo() {
        fifo_storage.reserve(100);// Reserves 100 spaces for the Fifo_storage
        front_index =0;//Makes the front and the back index = 0 because it is currently empty.
        back_index=0;
    }
    fifo::fifo(std::string input_string) {
        front_index=0;
        back_index=0;
        fifo_storage.reserve(100);
        fifo_storage.append(input_string);// Same thing as the first function but you would like to append the input_string
    }
    fifo::fifo(const fifo &original) {//Copies the information from the private to &original. had to add const to the lab2 std::string &operator[](unsigned position) in order for this to work.
        fifo_storage.reserve(100);
        front_index = original.front_index;
        back_index= original.back_index;
        for(int i=0; i<back_index;i++){// Have to do an array to copy each array element onto original
            fifo_storage[i]=original.fifo_storage[i];
        }
    }
    fifo::~fifo() {
        fifo_storage.set_size(0);//Makes the size = to 0. This is Bryan's code from lab2, he showed us this during lab
        front_index =-1;//Making them both equal to -1 will make sure that they are both empty
        back_index=-1;
    }
    fifo &fifo::operator=(const fifo &right) {
        fifo_storage.reserve(right.fifo_storage.capacity());
        front_index = right.front_index;//Assignment operators
        back_index = right.back_index;
        for(int i=0;i<=fifo_storage.size();i++){
            fifo_storage[i]=right.fifo_storage[i];
        }
    }
    bool fifo::is_empty() const {//If the front is greater than the back then it should be empty, it does not make sense for the front index to ever be greater than the back
        if(front_index>=back_index){// If they are equal to each other then that means that it is empty, just like how they are in the constructor.
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
        return fifo_storage[front_index];// The top of the Queue will always be the front index because when you dequeue you move the front_index
    }
    void fifo::enqueue(std::string input) {
        ++back_index;// You would need to add an extra element into the back_index and after that you can use the lab2 append to append input into the array of elements
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
