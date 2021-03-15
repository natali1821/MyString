#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED


class MyString {
public:
    //constructor and destructor
    MyString(char* input);
    ~MyString();
    //methods
    int getSize();
    void addSymbol(int, char);
    void replaceSymbol(int, char);
    void deleteSymbol(int);
    void print();
    void addStr(const MyString&);
    //operators
    MyString& operator+(const MyString&);
    MyString& operator+(char*);
    MyString& operator=(char*);
private:
    int _size;
    char* _str;
};


#endif // STRING_H_INCLUDED
