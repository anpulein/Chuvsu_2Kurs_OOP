#include <iostream>

struct TypeData {
    int num;
    char ch;
    bool flag;
    float dub;
} data;

int main() {
     int num;
     char ch;
     bool flag;
     float fl;
     double dub;
     wchar_t wh;

     std::cout << "***************** Exercise 1 ****************" << std::endl;
     std::cout << "int: " << sizeof(num) << " bytes" << std::endl;
     std::cout << "char: " << sizeof(ch) << " bytes" << std::endl;
     std::cout << "bool: " << sizeof(flag) << " bytes" << std::endl;
     std::cout << "float: " << sizeof(fl) << " bytes" << std::endl;
     std::cout << "double: " << sizeof(dub) << " bytes" << std::endl;
     std::cout << "wchar_t: " << sizeof(wh) << " bytes" << std::endl << std::endl;

    std::cout << "***************** Exercise 2 ****************" << std::endl;
    typedef short int SHINT;
    typedef unsigned long UNLONG;
    std::cout << "unsigned long" << " ----> " <<  typeid(UNLONG).name() << std::endl << std::endl;

    std::cout << "***************** Exercise 3 ****************" << std::endl;
    enum NumberMounths {JUNUARY, FEBRUARY, MARCH, APRIL};
    enum Lesson {FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7};
    NumberMounths Jun(JUNUARY), Feb(FEBRUARY), Mar(MARCH), Apr(APRIL);
    Lesson four(FOUR), five(FIVE), six(SIX), seven(SEVEN);
    int a = four, b = five, c = six, d = seven;
    std::cout << "NumberMounths: " << sizeof(NumberMounths) << " bytes" << std::endl;
    std::cout << "Lesson: " << sizeof(Lesson) << " bytes" << std::endl;
    std::cout << "Jun: " << Jun << '\n' << "Feb: " << Feb << '\n'
              << "Mar: " << Mar << '\n' << "Apr: " << Apr << std::endl;
    std::cout << "Enum: " << a << ", " << b << ", " << c << ", " << d << std::endl;
    std::cout << four << " -----> " << static_cast<char>(four) << std::endl; // Явное преобразование типа

    if (Jun == NumberMounths::JUNUARY) {
        std::cout << "The mounth is Junuary" << std::endl << std::endl;
    } else if (Jun == NumberMounths::FEBRUARY) {
        std::cout << "The mounth is February" << std::endl << std::endl;
    }

    std::cout << "***************** Exercise 4 ****************" << std::endl;
    std::cout << "TypeData: " << sizeof(data) << " bytes" << std::endl;
    std::cout << "BasicType: " << sizeof(num) + sizeof(ch) + sizeof(flag) + sizeof(fl) << " bytes" << std::endl;

    TypeData typeData;

    std::cout << "TypeData int: " << sizeof(typeData.num) << " bytes" << std::endl;
    std::cout << "TypeData char: " << sizeof(typeData.ch) << " bytes" << std::endl;
    std::cout << "TypeData bool: " << sizeof(typeData.flag) << " bytes" << std::endl;
    std::cout << "TypeData float: " << sizeof(typeData.dub) << " bytes" << std::endl << std::endl;

    std::cout << "***************** Exercise 5 ****************" << std::endl;
    {
        int a = 49;
        char ch = static_cast<char>(a);
        std::cout << a << " ----> " << ch << std::endl;
        int b = 90;
        b = b / 3.6; // Потеря данных
        b = 90;
        b = (float)b / 3.6; // Может возникнуть переполнение
        std::cout << b << std::endl;
        b = 90;
        std::cout << static_cast<int>(b / 3.6) << std::endl << std::endl;
    }
    int f;
    f = char(Jun);
    // Jun = char(f); // выдаст ошибку

    std::cout << "***************** Exercise 5 ****************" << std::endl;
    std::cout << "typeid TypeData: " << typeid(data).name() << std::endl;
    std::cout << "typeid duble: " << typeid(3.03).name() << std::endl;

    return 0;
}
