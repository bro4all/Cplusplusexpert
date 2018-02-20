
#ifndef CMPE126S18_LABS_STRINGVECTOR_H
#define CMPE126S18_LABS_STRINGVECTOR_H

#include <string>
namespace lab2 {
    class stringVector {
    private:
        std::string *data;
        unsigned length;
        unsigned allocated_length;

    public:
        stringVector();

        virtual ~stringVector();

        unsigned size();

        unsigned capacity();

        void reserve(unsigned new_size);

        bool empty();

        void append(std::string new_data);

        void swap(unsigned pos1, unsigned pos2);

        stringVector &operator=(stringVector const &rhs) const ;

        std::string &stringVector::operator[](unsigned position)const ;

        void sort();
    };
}


#endif //CMPE126S18_LABS_STRINGVECTOR_H
