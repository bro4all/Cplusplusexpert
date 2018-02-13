#include "../inc/stringVector.h"
#include <iostream>
int stringCompare (std::string str1, std::string str2 );

stringVector::stringVector() {
    data=nullptr;
    length=0;
    allocated_length=0;
}

stringVector::~stringVector() {
delete[]data;
}

unsigned stringVector::size() {
    return length;
    //return ;
}

unsigned stringVector::capacity() {
    return allocated_length;
    //return ;
}

void stringVector::reserve(unsigned new_size) {
    if (new_size == allocated_length) return;
    std::string* temp= new std::string[new_size];
    for(int i=0;i<new_size && i<length;i++) {
        temp[i] = data[i];
    }
    delete[]data;
    data=temp;


}



bool stringVector::empty() {
    return(length==0)?true:false;//return ;
}

void stringVector::append(std::string new_data) {
    std::string*temp=nullptr;
    if(length==allocated_length){
        if(allocated_length==0){
            data=new std::string[1];
            allocated_length=1;
        }
        else{
            temp=new std::string[2*allocated_length];
            for(int i=0;i<length;i++){
                temp[i]=data[i];
            }
            allocated_length=2*allocated_length;
            if(data!=nullptr){
                delete[]data;
            data=temp;}
        }
    }
    data[length]=new_data;
    length++;
}



void stringVector::swap(unsigned pos1, unsigned pos2) {
    std::string temp; //a temporary string to hold the data and switch it
    if((pos1>=length)||(pos2>=length)){
        std::cout<<"index Out of bounds"<<std::endl;
        return;
    }{
        temp = data[pos1];
        data[pos1] = data[pos2];
        data[pos2] = temp;
    }

}


stringVector &stringVector::operator=(stringVector const &rhs) {
    delete[] data;
    length=rhs.length;
    allocated_length=rhs.allocated_length;
    this->data=new std::string[allocated_length];
    for (int i=0;i<length;i++){
        this->data[i]=rhs.data[i];
    }
    return *this;
    //return ;
}

std::string &stringVector::operator[](unsigned position) {
    if(position>allocated_length){
        throw std::out_of_range("position out of range");}

        return data[position];
    }


    //return ;


void stringVector::sort() {
    std::string temp;
    for(int index = length - 1; index > 0; index--) {
        for (int j = 0; j < index; j++) {
            if(stringCompare(data[j], data[j+1]) > 0){
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}
int stringCompare (std::string str1, std::string str2 ){
    int pos;
    for(pos = 0; pos < str1.length() && pos < str2.length() && tolower(str1[pos]) == tolower(str2[pos]);++pos);
    if (str1.length() < str2.length() && pos == str1.length() )
        return -1;
    else if (str2.length() < str1.length() && pos == str2.length())
        return 1;
    else
        return pos == str1.length() ? 0 :tolower(str1[pos]) - tolower(str2[pos]);
}