#include "../inc/doubly_linked_list.h"

namespace lab6{
    doubly_linked_list::doubly_linked_list() {
        head=nullptr;
        tail=nullptr;

    }

    doubly_linked_list::doubly_linked_list(int input) {
node* current=new node(input);
        head=current;
        tail=head;
    }

    doubly_linked_list::doubly_linked_list(std::vector<int> vector_input) {

    }

    doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {

    }

    doubly_linked_list::~doubly_linked_list() {

    }

    int doubly_linked_list::get_data(unsigned position) {

    }

    std::vector<int> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {

    }

    unsigned doubly_linked_list::size() {

    }

    bool doubly_linked_list::is_empty() {
        node *head = head;
        node *tail;
        if (head == nullptr) {
            if (tail == nullptr) {
                return true;
            }
            return false;
        }
        return false;

    }

    void doubly_linked_list::append(int input) {
        node *tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = new node(input);
    }

    void doubly_linked_list::insert(int input, unsigned int location) {

    }

    void doubly_linked_list::remove(unsigned location) {

    }

    doubly_linked_list doubly_linked_list::split(unsigned position) {

    }

    doubly_linked_list doubly_linked_list::split_set(unsigned position_1, unsigned position_2) {

    }

  /*  void doubly_linked_list::swap(unsigned position_1, unsigned position_2) {
node* c=head;
        node* cn;
        node
        node* b=head;
        node* bnext;
        bnext=b->next;
        node* bprev=nullptr;
        bprev->next=b;
        b->prev

    }*/

    void doubly_linked_list::swap_set(unsigned location_1_start, unsigned location_1_end, unsigned location_2_start,
                                      unsigned location_2_end) {
        if(location_1_start < 1 || location_1_end > size() || location_2_start < 1 || location_2_end > size() ) {
            throw ("position 1 or 2 out of scope ");
        }
        else if(location_1_end == location_2_start ||location_2_end == location_1_start){
            throw ("location intersect");
        }
        else if((location_1_end < location_2_start && location_1_start < location_2_start)||(location_2_end < location_1_start && location_2_start < location_1_start)) {
            node *start1, *start2, *end1, *end2, *pre1 = nullptr, *next1 = nullptr, *pre2 = nullptr, *next2 = nullptr;
            start1 = head;
            start2 = head;
            end1 = head;
            end2 = head;
            for (int i = 1; i < location_1_start; i++) {
                start1 = start1->next;
            }
            pre1 = start1->prev;
            for (int i = 1; i < location_2_start; i++) {
                start2 = start2->next;
            }
            pre2 = start2->prev;
            for (int i = 1; i < location_1_end; i++) {
                end1 = end1->next;
            }
            next1 = end1->next;
            for (int i = 1; i < location_2_end; i++) {
                end2 = end2->next;
            }
            next2 = end2->next;
            if(start1 ==head && end2 != tail && end1->next!=start2 && end2->next!=start1){ // case head sed swap with non-tail set
                start2->prev = nullptr;
                end2->next = next1;
                next1->prev = end2;
                end1->next = next2;
                next2->prev = end1;
                start1->prev = pre2;
                pre2->next = start1;
                head =start2;
            }
            else if(start2 ==head && end1 != tail && end2->next!=start1 && end1->next!=start2){
                start1->prev = nullptr;
                end1->next = next2;
                next2->prev = end1;
                end2->next = next1;
                next1->prev = end2;
                start2->prev = pre1;
                pre1->next = start2;
                head =start1;
            }
            else if(start1 == head && end2 != nullptr && end1->next == start2 && end2 != tail){ // case of head set with the set next to it
                start2->prev = nullptr;
                end2->next = start1;
                start1->prev = end2;
                end1->next = next2;
                next2->prev = end1;
                head = start2;
            }
            else if(start2 == head && end1 != nullptr && end2->next == start1&& end1 != tail){ // case of head set with the set next to it
                start1->prev = nullptr;
                end1->next = start2;
                start2->prev = end1;
                end2->next = next1;
                next1->prev = end2;
                head = start1;
            }
            else if(start1 == head && end2 == tail){//swap set of head and tail
                if(end1->next == start2){
                    start2->prev = nullptr;
                    end2->next = start1;
                    start1->prev = end2;
                    end1->next = nullptr;
                    head = start2;
                    tail = end1;
                }
                else{
                    end2->next = next1;
                    end1->next = nullptr;
                    next1->prev = end2;
                    start1->prev = pre2;
                    start2->prev = nullptr;
                    pre2->next =start1;
                    head = start2;
                    tail = end1;
                }
            }
            else if(start2 == head && end1 == tail){//swap set of head and tail
                if(end2->next == start1){
                    start1->prev = nullptr;
                    end1->next = start2;
                    start2->prev = end1;
                    end2->next = nullptr;
                    head = start1;
                    tail = end2;
                }
                else{
                    end1->next = next2;
                    end2->next = nullptr;
                    next2->prev = end1;
                    start2->prev = pre1;
                    start1->prev = nullptr;
                    pre1->next =start2;
                    head = start1;
                    tail = end2;
                }
            }
            else if(end2 == tail && start1 != head){// anyone swap with tail;
                if(end1->next == start2){
                    end1->next = nullptr;
                    start2->prev = pre1;
                    pre1->next = start2;
                    start1->prev = end2;
                    end2->next = start1;
                    tail = end1;
                }
                else{
                    end1->next = nullptr;
                    end2->next = next1;
                    start2->prev = pre1;
                    start1->prev = pre2;
                    pre1->next = start2;
                    pre2->next = start1;
                    tail = end1;
                }
            }
            else if(end1 == tail && start2 != head){// anyone swap with tail;
                if(end2->next == start1){
                    end2->next = nullptr;
                    start1->prev = pre2;
                    pre2->next = start1;
                    start2->prev = end1;
                    end1->next = start2;
                    tail = end2;
                }
                else{
                    end2->next = nullptr;
                    end1->next = next2;
                    start1->prev = pre2;
                    start2->prev = pre1;
                    pre2->next = start1;
                    pre1->next = start2;
                    tail = end2;
                }
            }
            else{
                if(end1->next == start2){
                    start2->prev = pre1;
                    pre1->next = start2;
                    end2->next = start1;
                    start1->prev = end2;
                    end1->next = next2;
                    next2->prev = end1;
                }
                else if(end2->next == start1){
                    start1->prev = pre2;
                    pre2->next = start1;
                    end1->next = start2;
                    start2->prev = end1;
                    end2->next = next1;
                    next1->prev = end2;
                }
                else{
                    start2->prev = pre1;
                    pre1->next = start2;
                    end1->next = next2;
                    next2->prev = end1;
                    next1->prev = end2;
                    end2->next = next1;
                    start1->prev = pre2;
                    pre2 ->next = start1;
                }
            }
        }
        else{
            throw("invalid input please check");
        }
    }

    void doubly_linked_list::sort() {
        // Implement Insertion Sort
    }

    doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {

    }

    doubly_linked_list& doubly_linked_list::operator=(const doubly_linked_list &rhs) {

    }

    doubly_linked_list& doubly_linked_list::operator+=(const doubly_linked_list &rhs) {

    }

    bool doubly_linked_list::operator==(const doubly_linked_list &rhs) {
node*rhscurr,*lhscurr;
rhscurr=rhs.head;
lhscurr=head;
int count=0;
while(rhscurr&&lhscurr){
    if(rhscurr->get_data()==lhscurr->get_data()){
        count++;
    }
    rhscurr=rhscurr->next;
    lhscurr=lhscurr->next;
}
        return (count!=0);
    }

    std::ostream &operator<<(std::ostream &stream, doubly_linked_list &RHS) {
node* current=RHS.head;
if(current){
    stream<<"nullptr<-";
    while(current!= nullptr){
        if(current->next) {
            stream << current->get_data() << "<->";
            current = current->next;
        }
        else{
            stream<<current->get_data()<<"->";
            current=current->next;

        }
    }
    stream<<"nullptr";
    return stream;
}
    }

    std::istream &operator>>(std::istream &stream, doubly_linked_list &RHS) {
int temp;
stream>>temp;
RHS.append(temp);
        return stream;
    }
}

