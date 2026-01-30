#include "MyString.hpp"
#include <cstring>
//*дефолт конструктор
MyString::MyString() : str_(nullptr), length(0){
    str_ = new char[1];

    // std::cerr<<"std ctor"<<std::endl;
}
//*константный конструктор
MyString::MyString(const char* str) : str_(nullptr), length(0){
    if (str) {
        length = strlen(str);
        str_ = new char[length + 1];
        strcpy(str_, str);
    } else {
        str_ = new char[1];
        str_[0] = '\0';
    }

    // std::cerr<<"cnst ctor"<<std::endl;
}
//*конструктор копирования
MyString::MyString(const MyString& other) : str_(nullptr), length(other.length) {
    str_ = new char[length + 1];
    strcpy(str_, other.str_);
    // std::cerr<<"copy ctor"<<std::endl;
}
//*конструктор(оператор) присваивания
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {  
        delete[] str_;
        length = other.length;
        str_ = new char[length + 1];
        strcpy(str_, other.str_);
    }
    // std::cerr<<"asign ctor"<<std::endl;
    return *this;  
}
//*деструктор
MyString::~MyString() {
    // std::cerr<<str_<<std::endl;
    delete[] str_;
    // std::cerr<<"dtor"<<std::endl;
}


//сложение
MyString MyString::operator+(const MyString& other) const {
    MyString result;
    delete[] result.str_;
    
    result.length = this->length + other.length;
    result.str_ = new char[result.length + 1];
    
    strcpy(result.str_, this->str_);   
    strcat(result.str_, other.str_);
    
    return result;
}
//сравнение
bool MyString::operator==(const MyString& other) const {
    if (this->length != other.length) {
        return false;
    }
    return strcmp(this->str_, other.str_) == 0;
}
//доступ по индексу
const char& MyString::operator[](size_t index) const {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return str_[index];
}
