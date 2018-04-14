#include "stringVector.h"
#include <iostream>
namespace lab2 {
    int stringCompare(std::string str1, std::string str2);
    stringVector::stringVector() {
        length = 0;
        allocated_length = 0;
        data = NULL;
    }

    stringVector::~stringVector() {
        delete[]data;
    }

    unsigned stringVector::size() const  {
        return length;
        //return ;
    }

    unsigned stringVector::capacity() const {
        return allocated_length;
        //return ;
    }

    void stringVector::reserve(unsigned new_size) {
        if (new_size == allocated_length) return;
        std::string *temp = new std::string[new_size];
        for (int i = 0; i < new_size && i < length; i++) {
            temp[i] = data[i];
        }
        if (length > allocated_length) {
            length = new_size;
        }
        if (allocated_length<new_size){
            allocated_length=new_size;

        }
        allocated_length=new_size;
        delete[] data;
        data=temp;
    }


    bool stringVector::empty() {

        if (length == 0) {
            return true;
        }
        else {
            return false;
        }

    }

    void stringVector::append(std::string new_data) {

        if (allocated_length == 0) {
            data = new std::string[1];
            allocated_length = 1;
        }
        else if (allocated_length == length) {
            std::string *newArr = NULL;
            newArr = new std::string[allocated_length * 2];

            for (int i = 0; i < allocated_length; i++) {
                newArr[i] = data[i];
            }

            allocated_length = allocated_length * 2;
            delete[] data;
            data = newArr;
        }

        data[length] = new_data;
        length++;

    }

    void stringVector::swap(unsigned pos1, unsigned pos2) {
        std::string temp; //a temporary string to hold the data and switch it
        if ((pos1 >= length) || (pos2 >= length)) {
            std::cout << "index Out of bounds" << std::endl;
            return;
        }
        {
            temp = data[pos1];
            data[pos1] = data[pos2];
            data[pos2] = temp;
        }

    }


    stringVector &stringVector::operator=(stringVector const &rhs) {
        if (this != &rhs) {
            delete[] data;
            length = 0;
            allocated_length = 0;
            data = NULL;
            data = new std::string[rhs.capacity()];
            length = rhs.size();
            allocated_length = rhs.capacity();
            for (int i = 0; i < length; i++) {
                data[i] = rhs.data[i];
            }
        }
        return *this;
    }

    std::string stringVector::operator[](unsigned position){

       if (position >= allocated_length) {
           throw "Position is out of bounds. ";
       }
        std::string const return_string = data[position];
        return return_string;

    }

    std::string stringVector::operator[](unsigned position) const {

        if (position >= allocated_length) {
            throw "Position is out of bounds. ";
        }
        std::string const return_string = data[position];
        return return_string;

    }




    void stringVector::sort() {
        std::string temp;
        for (int index = length - 1; index > 0; index--) {
            for (int j = 0; j < index; j++) {
                if (stringCompare(data[j], data[j + 1]) > 0) {
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

    int stringCompare(std::string str1, std::string str2) {
        int pos;
        for (pos = 0; pos < str1.length() && pos < str2.length() && tolower(str1[pos]) == tolower(str2[pos]); ++pos);
        if (str1.length() < str2.length() && pos == str1.length())
            return -1;
        else if (str2.length() < str1.length() && pos == str2.length())
            return 1;
        else
            return pos == str1.length() ? 0 : tolower(str1[pos]) - tolower(str2[pos]);
    }

    void stringVector::set_size(unsigned new_size) {
        if (allocated_length != new_size) reserve(new_size);
        length = new_size;
    }

}