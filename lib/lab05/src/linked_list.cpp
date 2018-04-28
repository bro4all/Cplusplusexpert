#include <linked_list.h>
#include <iostream>

namespace lab5 {
    linked_list::linked_list() {
        head = nullptr;
        tail = nullptr;

    }

    linked_list::linked_list(std::string &data) {
        node *temp = new node(data);
        head = temp;
        tail = temp;
    }

    linked_list::linked_list(const linked_list &original) {
        node *current = original.head;
        node *temp = head;
        for (int i = 0; i < original.listSize(); i++) {
            temp->data = current->data;
            temp->next = current->next;

        }
        tail = original.tail;
    }


    linked_list::~linked_list() {
        node *temp = head;
        if (temp) {
            while (head) {
                temp = temp->next;
                delete head;
                head = temp;
            }
        } else {
            head = nullptr;
            tail = nullptr;
        }
    }

    linked_list &lab5::linked_list::operator=(const linked_list &RHS) {
        if (this == &RHS) {
            return *this;
        }
        head = new node(RHS.head->data);
        tail = new node(RHS.tail->data);
        node *temp = RHS.head;
        node *current = head;
        while (temp != NULL) {
            temp = temp->next;
            current->next = new node(temp->data);
            current = current->next;
        }
        return *this;
    }


    bool linked_list::isEmpty() const {
        if (head == nullptr) {
            if (tail == nullptr) {
                return true;
            }
        } else {
            return false;
        }
    }


    unsigned linked_list::listSize() const {
        unsigned size=0;
        node *temp = head;
        if (head == nullptr && tail == nullptr) {
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
        node *previous;
        node *current = head;
        node *temporary = new node(input);
        current = head;
        if (isEmpty()) append(input);
        else if (location == 0) {
            node *temp = new node(input);
            temp->next = head;
            head = temp;
        } else {
            for (int i = 0; i < location; ++i) {
                previous = current;
                current = current->next;
            }
            temporary->next = current;
            previous->next = temporary;
        }
    }


    void linked_list::append(const std::string input) {
        node *temp = new node(input);
        temp->data = input;
        if (head == NULL) {
            head = temp;
            tail = temp;
            tail->next = NULL;
        } else {
            tail->next = temp;
            tail = tail->next;
        }
    }


    void linked_list::sort() {
        node *h = head, *i, *j;
        for (i = h; i != NULL && i->next != NULL; i = i->next) {
            node *min;
            min = i;
            for (j = i->next; j != NULL; j = j->next) {
                if (j->data < min->data)
                    min = j;
            }
            if (min != i) {
                std::string temp;
                temp = min->data;
                min->data = i->data;
                i->data = temp;
            }
        }
        head = h;
    }

    void linked_list::remove(unsigned int location) {
        node *prev = nullptr;
        node *current = head;

        if(listSize() == 1){
            delete head;
            head = tail = nullptr;
            return;
        }
        for (int i = 0; i < location && current->next != nullptr; i++) {
            prev = current;
            current = current->next;
        }
        if (prev) {
            prev->next = current->next;
            current = nullptr;
            tail = prev;
        }
        if (location > listSize()) {
            throw "location is out of bounds";
        } else if (!prev) {
            head = current->next;
        }

    }

    std::ostream &operator<<(std::ostream &stream, linked_list &RHS) {
        node *current = RHS.head;
        stream << std::endl;
        while (current != NULL) {
            stream << current->data << " ";
            current = current->next;
        }
        stream << std::endl;
        return stream;
    }

    std::istream &operator>>(std::istream &stream, linked_list &RHS) {
        std::string temp;
        stream >> temp;
        RHS.append(temp);
        return stream;

    }

    std::string linked_list::get_value_at(unsigned location) const {

            node *current = head;
            for (int i = 0; i < location; i++) {
                current = current->next;

            }

            return current->data;//(*current).data;

    }
}