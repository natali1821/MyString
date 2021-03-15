#include <iostream>
#include "String.cpp"

int main()
{
    MyString s("Adan");
    MyString f("Eva");

    s.addSymbol(3, 'm');
    s.print();

    s.replaceSymbol(4, 'm');
    s.print();

    s.deleteSymbol(3);
    s.print();

    s + f;
    s.print();

    s = "ADAM";
    s.print();

    s + "EVA";
    s.print();
}
