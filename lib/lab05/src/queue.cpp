#include "queue.h"
namespace lab5{
    queue::queue() {

    }

    queue::queue(std::string &data) {
storage_structure.append(data);
    }

    queue::queue(const queue &original) {
queue temp;
        temp=original;
        for(int i=0;i<original.queueSize();i++){
            storage_structure.append((temp.top());
            temp.dequeue();

        }
    }

    queue::~queue() {
        for(int i=0;i<storage_structure.listSize();i++){
            storage_structure.remove(i);
        }

    }

    queue &queue::operator=(const queue &RHS) {
        for(int i=0; i<RHS.queueSize(); i++) {
            this->storage_structure.append(RHS.storage_structure.get_value_at(i));
        }
        return *this;
    }

    bool queue::isEmpty() const {
        if(storage_structure.isEmpty()){
            return true;
        }
        return false;
    }

    unsigned queue::queueSize() const {
        return 0;
    }

    std::string queue::top() const {
        //return std::__cxx11::string();
    }

    void queue::enqueue(const std::string &data) {

    }

    void queue::dequeue() {

    }

    std::ostream& operator<<(std::ostream &stream, queue &RHS) {
        return stream;
    }

    std::istream& operator>>(std::istream &stream, queue &RHS) {
        return stream;
    }
}