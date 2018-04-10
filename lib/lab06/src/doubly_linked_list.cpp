#include "../inc/doubly_linked_list.h"

namespace lab6 {
    doubly_linked_list::doubly_linked_list() {
        head = nullptr;
        tail = nullptr;

    }

    doubly_linked_list::doubly_linked_list(int input) {
        node *current = new node(input);
        head = current;
        tail = head;
    }

    doubly_linked_list::doubly_linked_list(std::vector<int> vector_input) {

    }

    doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {

    }

    doubly_linked_list::~doubly_linked_list() {
        while (head) {
            node *temp = head->next;
            delete head;
            head = temp;
        }

    }

    int doubly_linked_list::get_data(unsigned position) {
        int j = 0;
        node *current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
            j = current->get_data();

        }

        return j;
    }


    std::vector<int> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {

    }

    unsigned doubly_linked_list::size() {

    }

    bool doubly_linked_list::is_empty() {


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
        lab6::doubly_linked_list one;
        node *current, *pre, *next;
        current = head;
        for (int i = 1; i < position; i++) {
            current = current->next;
        }
        if (current == head) {
            pre = nullptr;
        } else {
            pre = current->prev;
        }
        if (current == tail) {
            next = nullptr;
        } else {
            next = current->prev;
        }
        if (current == head) {
            while (current) {
                one.append(current->get_data());
                current = current->next;
            }
            this->head = nullptr;
            this->tail = nullptr;
            return one;
        } else if (next == tail) {
            return one;
        } else {
            this->tail = current;
            current = current->next;
            while (current) {
                one.append(current->get_data());
                current = current->next;
            }
            tail->next = nullptr;
            return one;
        }
    }

    doubly_linked_list doubly_linked_list::split_set(unsigned position_1, unsigned position_2) {
        lab6::doubly_linked_list one;
        if (position_1 < 1 || position_2 < 1) {
            throw ("please start the index at 1");
        }
        if (position_2 < position_1) {
            int temp = position_2;
            position_2 = position_1;
            position_1 = temp;
        }
        if (!head) {
            throw ("out of scope");
        }
        node *start = head, *end = head, *spre = nullptr, *enext = nullptr;
        for (int i = 1; i < position_1; i++) {
            start = start->next;
        }
        spre = start->prev;
        for (int i = 1; i < position_2; i++) {
            end = end->next;
        }
        enext = end->next;
        if (start == head && enext) {
            while (start != end->next) {
                one.append(start->get_data());
                start = start->next;
            }
            this->head = enext;
            return one;
        } else if (spre && end == tail) {
            while (start) {
                one.append(start->get_data());
                start = start->next;
            }
            this->tail = spre;
            tail->next = nullptr;
            return one;
        } else if (start == head && end == tail) {
            while (start) {
                one.append(start->get_data());
                start = start->next;
            }
            this->head = nullptr;
            this->tail = nullptr;
            return one;
        } else {
            while (start != end->next) {
                one.append(start->get_data());
                start = start->next;
            }
            spre->next = enext;
            enext->prev = spre;
            return one;
        }
    }

    void doubly_linked_list::swap(unsigned position_1, unsigned position_2) {
    }

    void doubly_linked_list::swap_set(unsigned location_1_start, unsigned location_1_end, unsigned location_2_start,
                                      unsigned location_2_end) {
        if (location_1_start < 1 || location_1_end > size() || location_2_start < 1 || location_2_end > size()) {
            throw ("position 1 or 2 out of scope ");
        } else if (location_1_end == location_2_start || location_2_end == location_1_start) {
            throw ("location intersect");
        } else if ((location_1_end < location_2_start && location_1_start < location_2_start) ||
                   (location_2_end < location_1_start && location_2_start < location_1_start)) {
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
            if (start1 == head && end2 != tail && end1->next != start2 &&
                end2->next != start1) { // case head sed swap with non-tail set
                start2->prev = nullptr;
                end2->next = next1;
                next1->prev = end2;
                end1->next = next2;
                next2->prev = end1;
                start1->prev = pre2;
                pre2->next = start1;
                head = start2;
            } else if (start2 == head && end1 != tail && end2->next != start1 && end1->next != start2) {
                start1->prev = nullptr;
                end1->next = next2;
                next2->prev = end1;
                end2->next = next1;
                next1->prev = end2;
                start2->prev = pre1;
                pre1->next = start2;
                head = start1;
            } else if (start1 == head && end2 != nullptr && end1->next == start2 &&
                       end2 != tail) { // case of head set with the set next to it
                start2->prev = nullptr;
                end2->next = start1;
                start1->prev = end2;
                end1->next = next2;
                next2->prev = end1;
                head = start2;
            } else if (start2 == head && end1 != nullptr && end2->next == start1 &&
                       end1 != tail) { // case of head set with the set next to it
                start1->prev = nullptr;
                end1->next = start2;
                start2->prev = end1;
                end2->next = next1;
                next1->prev = end2;
                head = start1;
            } else if (start1 == head && end2 == tail) {//swap set of head and tail
                if (end1->next == start2) {
                    start2->prev = nullptr;
                    end2->next = start1;
                    start1->prev = end2;
                    end1->next = nullptr;
                    head = start2;
                    tail = end1;
                } else {
                    end2->next = next1;
                    end1->next = nullptr;
                    next1->prev = end2;
                    start1->prev = pre2;
                    start2->prev = nullptr;
                    pre2->next = start1;
                    head = start2;
                    tail = end1;
                }
            } else if (start2 == head && end1 == tail) {//swap set of head and tail
                if (end2->next == start1) {
                    start1->prev = nullptr;
                    end1->next = start2;
                    start2->prev = end1;
                    end2->next = nullptr;
                    head = start1;
                    tail = end2;
                } else {
                    end1->next = next2;
                    end2->next = nullptr;
                    next2->prev = end1;
                    start2->prev = pre1;
                    start1->prev = nullptr;
                    pre1->next = start2;
                    head = start1;
                    tail = end2;
                }
            } else if (end2 == tail && start1 != head) {// anyone swap with tail;
                if (end1->next == start2) {
                    end1->next = nullptr;
                    start2->prev = pre1;
                    pre1->next = start2;
                    start1->prev = end2;
                    end2->next = start1;
                    tail = end1;
                } else {
                    end1->next = nullptr;
                    end2->next = next1;
                    start2->prev = pre1;
                    start1->prev = pre2;
                    pre1->next = start2;
                    pre2->next = start1;
                    tail = end1;
                }
            } else if (end1 == tail && start2 != head) {// anyone swap with tail;
                if (end2->next == start1) {
                    end2->next = nullptr;
                    start1->prev = pre2;
                    pre2->next = start1;
                    start2->prev = end1;
                    end1->next = start2;
                    tail = end2;
                } else {
                    end2->next = nullptr;
                    end1->next = next2;
                    start1->prev = pre2;
                    start2->prev = pre1;
                    pre2->next = start1;
                    pre1->next = start2;
                    tail = end2;
                }
            } else {
                if (end1->next == start2) {
                    start2->prev = pre1;
                    pre1->next = start2;
                    end2->next = start1;
                    start1->prev = end2;
                    end1->next = next2;
                    next2->prev = end1;
                } else if (end2->next == start1) {
                    start1->prev = pre2;
                    pre2->next = start1;
                    end1->next = start2;
                    start2->prev = end1;
                    end2->next = next1;
                    next1->prev = end2;
                } else {
                    start2->prev = pre1;
                    pre1->next = start2;
                    end1->next = next2;
                    next2->prev = end1;
                    next1->prev = end2;
                    end2->next = next1;
                    start1->prev = pre2;
                    pre2->next = start1;
                }
            }
        } else {
            throw ("invalid input please check");
        }
    }

    void doubly_linked_list::sort() {
        node *current = head;
        node *holdhead = head;
        node *temp = current->next;
        while (temp != nullptr) {
            if (head->next == current) {
                if (current->get_data() <= head->get_data()) {
                    temp = current->next;
                    current->prev = nullptr;
                    current->next = holdhead;
                    holdhead->prev = current;
                    holdhead->next = temp;
                    temp->prev = holdhead;
                    head = current;
                    holdhead = head;
                }
            }
            while (current != temp) {
                if (temp->get_data() >= current->get_data() && temp->get_data() <= current->next->get_data() &&
                    temp != current->next) {
                    if (temp == tail) {
                        node *new_tail = temp->prev;
                        node *cnext = current->next;
                        temp->prev = current;
                        temp->next = cnext;
                        current->next = temp;
                        cnext->prev = temp;
                        new_tail->next = nullptr;
                        tail = new_tail;
                        temp = new_tail;
                    } else {
                        node *next = temp->next;
                        node *pre = temp->prev;
                        node *cnext = current->next;
                        temp->prev = current;
                        temp->next = cnext;
                        current->next = temp;
                        cnext->prev = temp;
                        pre->next = next;
                        next->prev = pre;
                        temp = pre;
                    }
                } else if (temp->get_data() <= current->get_data() && current == head) {
                    if (temp == tail) {
                        node *new_tail = temp->prev;
                        temp->prev = nullptr;
                        temp->next = current;
                        current->prev = temp;
                        head = temp;
                        holdhead = head;
                        new_tail->next = nullptr;
                        tail = new_tail;
                        temp = new_tail;
                    } else {
                        node *next = temp->next;
                        node *pre = temp->prev;
                        temp->prev = nullptr;
                        temp->next = current;
                        pre->next = next;
                        next->prev = pre;
                        current->prev = temp;
                        head = temp;
                        holdhead = head;
                        temp = pre;
                    }
                }
                current = current->next;
            }
            current = head;
            temp = temp->next;
        }

        node *sorted = NULL;
        // Traverse the given doubly linked list and
        // insert every node to 'sorted'
        node *current = head;
        while (current != NULL) {
            // Store next for next iteration
            node *next = current->next;
            // removing all the links so as to create 'current'
            // as a new node for insertion
            current->prev = current->next = NULL;
            // insert current in 'sorted' doubly linked list
            sort();
            // Update current
            current = next;
        }
        // Update head_ref to point to sorted doubly linked list
        head = sorted;

    }


    doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {
        doubly_linked_list test;
        test = *this;
        test += rhs;
        return test;
    }


    doubly_linked_list &doubly_linked_list::operator=(const doubly_linked_list &rhs) {
        node *p2 = rhs.head;
        if (p2 == nullptr) {
            this->head = nullptr;
            this->tail = nullptr;
        } else {
            auto *ahead = new node(p2->get_data());
            this->head = ahead;
            p2 = p2->next;
            while (p2) {
                auto *temp = new node(p2->get_data());
                p2 = p2->next;
                temp->prev = ahead;
                ahead->next = temp;
                ahead = temp;
                temp = temp->next;
            }
            ahead->next = nullptr;
            this->tail = ahead;
        }
        return *this;
    }

    doubly_linked_list &doubly_linked_list::operator+=(const doubly_linked_list &rhs) {
        node *p1 = rhs.head;
        node *p2 = this->head;
        auto *new_ = new node(p2->get_data());
        node *ahead = new_;
        if (!p1) {
            return *this;
        } else if (!p2) {
            this->head = p1;
            this->tail = rhs.tail;
            return *this;
        } else {
            tail->next = rhs.head;
            rhs.head->prev = tail;
            p2 = p2->next;
            while (p2) {
                auto *temp = new node(p2->get_data());
                p2 = p2->next;
                temp->prev = new_;
                new_->next = temp;
                new_ = temp;
                temp = temp->next;
            }
            while (p1) {
                auto *temp = new node(p1->get_data());
                p1 = p1->next;
                temp->prev = new_;
                new_->next = temp;
                new_ = temp;
                temp = temp->next;
            }
            new_->next = nullptr;
            this->head = ahead;
            this->tail = new_;
            return *this;
        }
    }

    bool doubly_linked_list::operator==(const doubly_linked_list &rhs) {
        node *rhscurr, *lhscurr;
        rhscurr = rhs.head;
        lhscurr = head;
        int count = 0;
        while (rhscurr && lhscurr) {
            if (rhscurr->get_data() == lhscurr->get_data()) {
                count++;
            }
            rhscurr = rhscurr->next;
            lhscurr = lhscurr->next;
        }
        return (count != 0);
    }

    std::ostream &operator<<(std::ostream &stream, doubly_linked_list &RHS) {
        node *current = RHS.head;
        if (current) {
            stream << "nullptr<-";
            while (current != nullptr) {
                if (current->next) {
                    stream << current->get_data() << "<->";
                    current = current->next;
                } else {
                    stream << current->get_data() << "->";
                    current = current->next;

                }
            }
            stream << "nullptr";
            return stream;
        }
    }

    std::istream &operator>>(std::istream &stream, doubly_linked_list &RHS) {
        int temp;
        stream >> temp;
        RHS.append(temp);
        return stream;
    }

}