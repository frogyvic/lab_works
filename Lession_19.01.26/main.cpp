#include <iostream>
#include "MyString.hpp"

int main(){
    MyString str0;
    MyString str1("World");
    MyString str2(str1);
    //? присваивание строки и поля str1 нашему полю str0
    str0="Hello ";
    std::cout<<str0.c_str()<<str1.c_str()<<std::endl;
    str0=str1;
    std::cout<<str0.c_str()<<str1.c_str()<<std::endl;
    //?поле str2 является копией поля str1
    std::cout<<str2.c_str()<<str1.c_str()<<std::endl;
    str0="Helo ";
    //?сложение
    str2=str0+str1;
    std::cout<<str2.c_str()<<std::endl;
    //?Сравнение
    if (str0=="Helo "){
        std::cout<<true<<std::endl;
    }
    else{
        std::cout<<false<<std::endl;
    }
    //?Доступ к элементу по индексу
    for (int i=0;i<str1.size();i++){
        std::cout<<str1[i]<<" ";
    }


}