#include <linked_list.h>
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
            if (tail = nullptr) {
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
        return 0;
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
        {
            node *tail = head;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = new node(input);
        }

        void linked_list::remove(unsigned location) {
            node*
        }

        std::ostream &operator<<(std::ostream &stream, linked_list &RHS) {
            return stream;
        }

        std::istream &operator>>(std::istream &stream, linked_list &RHS) {
            return stream;
        }

        void linked_list::sort() {

        }
    }
}