#include "../inc/stringVector.h"
#include <iostream>

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
    *data=*temp;


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
    std::string tmstr; //atemporary string to hold the data and switch it
    if ((pos1>=length)||(pos2>=length)){
        std::cout<<"indec Out of bounds"<<std::endl;
        return;
    }
    tmstr=data[pos1];
    data[pos1]=data[pos2];
    data[pos2]=tmstr;

}


stringVector &stringVector::operator=(stringVector const &rhs) {
    //return ;
}

std::string &stringVector::operator[](unsigned position) {
    //return ;
}

void stringVector::sort() {

}
