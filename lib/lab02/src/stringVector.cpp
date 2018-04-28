#include "../inc/stringVector.h"
namespace lab2 {
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
    stringVector::stringVector() {
        length = 0;
        allocated_length = 0;
        data = nullptr;
    }
    stringVector::~stringVector() {
        length = 0;
        allocated_length = 0;
        delete[] data;
    }
    unsigned stringVector::size() const {
        return length;
    }
    unsigned stringVector::capacity() const {
        return allocated_length;
    }
    void stringVector::reserve(unsigned new_size) {
        if (length == 0 ) {
            data = new std::string[new_size];
            allocated_length = new_size;
        }
        else if (new_size < length) {
            std::string *newlength = new std::string[new_size];
            for(int i = 0; i < new_size; i++){
                newlength[i] = data[i];
            }
            delete []data;
            data = new  std::string[new_size];
            for(int i = 0; i < new_size; i++){
                data[i] = newlength[i];
            }
            delete [] newlength;
            length = new_size;
            allocated_length = new_size;
        }
        else {
            std::string *newsize = new std::string[new_size];
            for (int i = 0; i < length; i++) {
                newsize[i] = data[i];
            }
            delete[] data;
            data = new std::string[new_size];
            for (int i = 0; i < length; i++) {
                data[i] = newsize[i];
            }
            delete[] newsize;
            allocated_length = new_size;
        }
    }
    bool stringVector::empty() const {
        return length == 0;
    }
    void stringVector::append(std::string new_data) {
        if (length == allocated_length) {
            if (length == 0) {
                reserve(1);
                data[length] = new_data;
                length++;
            }
            else
            {
                std::string *replace = new std::string[length];
                for (int i = 0; i < length; i++) {
                    replace[i] = data[i];
                }
                delete[] data;
                data = new std::string[2 * length];
                for (int i = 0; i < length; i++) {
                    data[i] = replace[i];
                }
                delete[] replace;
                allocated_length = 2 * length;
                data[length] = new_data;
                length++;
            }
        }
        else {
            data[length] = new_data;
            length++;
        }
    }
    void stringVector::swap(unsigned pos1, unsigned pos2) {
        if (pos1 > length || pos2 > length) {
            throw "out of bundle";
        } else {
            std::string temp = data[pos1];
            data[pos1] = data[pos2];
            data[pos2] = temp;
        }
    }
    stringVector &stringVector::operator=(stringVector const &rhs) {
        reserve(rhs.allocated_length);
        for (int i = 0; i < allocated_length; i++) {
            this->data[i] = rhs.data[i];
        }
        length = rhs.length;
        return *this;
    }
    std::string & stringVector::operator[](unsigned int position)const {
        if (position > length) {
            throw ("out of bundle");
        }
        else if (length == 0) {
            throw ("empty");
        }
        else {
            return data[position];
        }
    }
    void stringVector::sort() {
        std::string temp;
        for(int index = length - 1; index > 0; index--){
            for (int j = 0; j < index; j++) {
                if(stringCompare(data[j], data[j+1]) > 0){
                    temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                }
            }
        }
    }
    void stringVector::newLength(unsigned new_size){
        length = new_size;
        allocated_length = new_size;
        data = new std::string[new_size];
    }
}