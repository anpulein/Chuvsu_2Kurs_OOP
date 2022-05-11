#include <iostream>
#include <algorithm>
#include <list>
#include <deque>
#include <stack>
#include <vector>
#include "Headers/linkedList.h"
#include "Headers/lesson2.h"
#include "Headers/lesson7.h"

using namespace std;

void example_show(short i) {
    cout << "/**************************** Example " << i
         << "****************************/" << endl;
}

bool one(string a1, string a2) {
    return  a2 == a1;
}

void fun(Char<char> *pBase) {
    String<char, char> *pDerived = dynamic_cast<String<char, char> *> (pBase);
    if (pDerived) pDerived->Out();
    else cout << "Передан объект не производного класса" << endl;
}

int main() {

    {
        example_show(1);
        LinkedList<int> list_1;
        list_1.push_back(1);
        list_1.push_back(2);
        list_1.push_back(3);
        cout << "List_1: ";
        list_1.show();
        cout << "find (list_1) " << 2 << " = " << (list_1.find(2) != nullptr ? "Yes" : "No") << endl;
        cout << "find (list_1) " << 4 << " = " << (list_1.find(4) != nullptr ? "Yes" : "No") << endl;
        list_1.remove_first();
        cout << "List_1: ";
        list_1.show();

        cout << "-------------------" << endl;

        LinkedList<string> list_2;
        list_2.push_back("1");
        list_2.push_back("2");
        list_2.push_back("3");
        cout << "List_2: ";
        list_2.show();
        cout << "find (list_1) 2 = " << (list_2.find("2") ? "Yes" : "No") << endl;
        cout << "find (list_1) 4 = " << (list_2.find("4") ? "Yes" : "No") << endl;
        list_2.remove_first();
        cout << "List_2: ";
        list_2.show();

    }

    {
        example_show(2);

        Char<char> sChar('1', 2);
        String<char, char> string('1', 2, "234324");

        sChar.Out();
        string.Out();

        cout << "---------------------------" << endl;

        String<char, char> *ptr_Derived = new String<char, char>('1', 2, "3r433");
        Char<char> *ptr_Base = new Char<char>('1', 2);
        fun(ptr_Base);
        fun(ptr_Derived);
    }

    {
        example_show(3);

        Char<char> sChar('1', 2);
        String<char, char> string('1', 2, "234324");

        sChar.Out();
        string.Out();

//        cout << sChar;

    }

    {
        example_show(4);

        list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        cout << "List find(1) = ";
        auto res = find(list.begin(), list.end(), 1);
        cout << distance(list.begin(), res) << endl;

        deque<int> deque;
        deque.push_back(1);
        deque.push_back(2);
        deque.push_back(3);
        cout << "deque find(2) = ";
        auto res_1 = find(deque.begin(), deque.end(), 2);
        cout << distance(deque.begin(), res_1) << endl;

        stack<int> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);
//        cout << "stack find(3) = " << endl;
//        find(stack., deque.end(), 2);

    }

    {
        example_show(5);

        list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        cout << "List find(1) = ";
        auto res = find(list.begin(), list.end(), 1);
        cout << distance(list.begin(), res) << endl;

        deque<int> deque;
        deque.push_back(1);
        deque.push_back(2);
        deque.push_back(3);
        cout << "deque find(2) = ";
        auto res_1 = find(deque.begin(), deque.end(), 2);
        cout << distance(deque.begin(), res_1) << endl;

        stack<int> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);
//        cout << "stack find(3) = " << endl;
//        find(stack., deque.end(), 2);

    }

    {
        example_show(6);

        list<int> list;
        list.push_back(1);
        list.push_back(1);
        list.push_back(2);
        cout << "List count(1) = " << count(list.begin(), list.end(), 1) << endl;

        deque<int> deque;
        deque.push_back(1);
        deque.push_back(2);
        deque.push_back(3);
        cout << "deque count(2) = " << count(deque.begin(), deque.end(), 2) << endl;

        stack<int> stack;
        stack.push(1);
        stack.push(1);
        stack.push(1);


    }

    {
        example_show(7);

        vector<Person> persons;
        persons.push_back(Person("Dima", 19, 1900));
        persons.push_back(Person("Gera", 20, 1700));
        persons.push_back(Person("Bora", 21, 1900));

        vector<Student> students;
        students.push_back(Student("Dima", 19, 2));
        students.push_back(Student("Gera", 20, 2));
        students.push_back(Student("Vera", 21, 2));

        cout << "Search(persons, students) = ";
        auto res = search(persons.begin(), persons.end(), students.begin(), students.end());
        if (res == persons.end()) cout << "Совпадений нет" << endl;
        else cout << res - persons.begin() << endl;

    }

    {
        example_show(8);

        vector<int> arr_1 = {1, 2, 3};
        vector<int> arr_2 = {4, 5, 6};
        list<int> arr_3;
        merge(arr_1.begin(), arr_1.end(), arr_2.begin(), arr_2.end(), arr_3.begin(), arr_3.end());

        cout << "Arr_3 = ";
        for (int i = 0; i < arr_3.size(); ++i) {
            cout << "";
        }

    }

    {
        example_show(9);


    }

    {
        example_show(10);


    }

    {
        example_show(11);


    }

    {
        example_show(12);


    }

}
