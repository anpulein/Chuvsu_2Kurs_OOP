#include <iostream>
#include "Headers/linkedList.h"

using namespace std;

void example_show(short i) {
    cout << "/**************************** Example " << i
         << "****************************/" << endl;
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


    }

    {
        example_show(3);


    }

    {
        example_show(4);


    }

    {
        example_show(5);


    }

    {
        example_show(6);


    }

    {
        example_show(7);


    }

    {
        example_show(8);


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
