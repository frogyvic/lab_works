#include <iostream>
#include <cstring>

class MyString {
private:
    size_t length;  
    char* str_;      

public:
    //конструкторы и деструктор
    explicit MyString();

    MyString(const char* str);

    MyString(const MyString& other);

    MyString& operator=(const MyString& other);

    ~MyString();

    //геттеры
    const char* c_str() const { 
        return str_;
     }
    size_t size() const { 
        return length;
     }

    //перегруженные операторы
    MyString operator+(const MyString& other) const;    // сложение строк
    bool operator==(const MyString& other) const;       // сравнение строк
    const char& operator[](size_t index) const;         // доступ к элементу по индексу
};