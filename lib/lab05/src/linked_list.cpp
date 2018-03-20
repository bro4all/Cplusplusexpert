#include <linked_list.h>
#include <iostream>

namespace lab5 {
    linked_list::linked_list() {
        head = nullptr;
        tail = nullptr;

    }

    linked_list::linked_list(std::string &data) {
        head->data = data;
    }

    linked_list::linked_list(const linked_list &original) {
        node *iterator = original.head;
        node *temp = head;
        for (int i = 0; i < original.listSize(); i++) {
            temp->data = iterator->data;
            temp->next = iterator->next;

        }
        tail = original.tail;
    }


    linked_list::~linked_list() {
        while (head) {
            node *temp = head->next;
            delete head;
            head = temp;
        }
    }

    linked_list &lab5::linked_list::operator=(const linked_list &RHS) {
        //return <#initializer#>;
    }


    bool linked_list::isEmpty() const {
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


    unsigned linked_list::listSize() const {
        unsigned size;
        node *temp = head;
        if (head == 0 && tail == 0) {
            return 0;
        } else {
            while (temp != nullptr) {
                size++;
                temp = temp->next;
            }
        }
        return size;
    }

    void linked_list::insert(const std::string input, unsigned int location) {
        node *previous = NULL;
        node *current;
        node *temporary = new node(input);
        current = head;
        for (int i = 0; i < location; ++i) {
            previous = temporary;
            current = current->next;
        }
        if (previous) {
            previous->next = temporary;
            temporary->next = current;
        } else {
            head = temporary;
            temporary->next = current;
        }
        delete temporary;
    }

    void linked_list::append(const std::string input) {
            node *tail = head;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = new node(input);
        }



        void linked_list::sort() {
            node *h = head, *i, *j,;
            for(i = h; i!=NULL && i->next!=NULL; i=i->next)
            {
                node *min;
                min = i;
                for(j = i->next; j!=NULL ; j=j->next)
                {
                    if(j->data < min->data)
                        min=j;
                }
                if(min!=i)
                {
                    std::string temp;
                    temp = min->data;
                    min->data = i->data;
                    i->data = temp;
                }
            }
            head = h;
        }

    void linked_list::remove(unsigned int location) {
        node *prev = NULL;
        node* current = head;
        for(int i = 0; i < location; i++){
            prev = current;
            current = current->next;
        }
        if(prev){
            prev->next = current->next;
            current = NULL;
            tail = prev;
        }
        if(location>listSize()){
            throw 0;
        }
        else if(!prev){
            head = current->next;
        }

    }

    std::ostream &operator<<(std::ostream &stream, linked_list &RHS) {
        node *current = RHS.head;
        stream<<std::endl;
        while(current != NULL){
            stream<<current->data<<" ";
            current = current->next;
        }
        stream<<std::endl;
        return stream;
    }

    std::istream &operator>>(std::istream &stream, linked_list &RHS) {
        std::string temp;
        stream>>temp;
        RHS.append(temp);
        return stream;

    }

    std::string linked_list::get_value_at(unsigned location) const {
        std::string value;
        node* current=head;
        for(int i=0:i<location;i++;){
            current=current->next;
            value=current->data;

        }

        return std::string(value);
    }

}