#include <iostream>
#include <string.h>
#include "String.h"

MyString::MyString(char* input) {
    if (input != NULL) {
        _size = strlen(input);
        _str = new char[_size + 1];
        strcpy(_str, input);
    }
    else {
        _str = NULL;
    }
}

MyString::~MyString(){
    delete[] _str;
}

void MyString::addSymbol(int position, char symbol) {
    int n = getSize();
    char* buffer = new char[n + 2];
    strcpy(buffer, _str);
    buffer[position] = symbol;
    for(int i = position; i < n; ++i) {
        buffer[i + 1] = _str[i];
    }
    buffer[n + 2] = '\0';
    delete[] _str;
    _str = buffer;
    _size = n + 1;
}

void MyString::replaceSymbol(int position, char symbol) {
    _str[position] = symbol;
}

void MyString::deleteSymbol(int position) {
    int n = getSize();
    char* buffer = new char[n];
    strcpy(buffer, _str);
    for(int i = position; i < n; ++i) {
        buffer[i] = _str[i + 1];
    }
    buffer[n] = '\0';
    delete[] _str;
    _str = buffer;
    _size = n - 1;
}

void MyString::addStr(const MyString& s) {
    int str1 = getSize();
    int str2 = s._size;
    int newstr = str1 + str2;
    char* str = new char[newstr + 1];
    for (int i = 0; i < str1; i++) {
        str[i] = _str[i];
    }
    for(int i = 0; i < str2; i++) {
        str[i + str1] = s._str[i];
    }
    str[newstr] = '\0';
    delete[] _str;
    _str = str;
    _size = newstr;
}

MyString& MyString::operator+(const MyString& s) {
    addStr(s);
    return *this;

}

MyString& MyString::operator+(char* str) {
    addStr(str);
    return *this;
}

MyString& MyString::operator=(char* str) {
    this->_size = strlen(str);
    this->_str = new char[this->_size + 1];
    strcpy(this->_str, str);
    return *this;
}

int MyString::getSize(){
    return _size;
}

void MyString::print(){
    std::cout << _str << std::endl;
}
