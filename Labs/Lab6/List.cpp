//
// Created by dimaa on 13.02.2022.
//

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class NewList : public list<int>{
    list<int> arrays;
    int size;

    public:
        NewList(const int arr[], int n): size(n){
            for(int i = 0; i < n; i++) {
                arrays.push_back(arr[i]);
            }
        };
        ~NewList();
        int &operator[](int);
        void Out();

};

NewList::~NewList() {
    arrays.clear();
    size = 0;
}

int &NewList::operator[](int i) {

    if(i < 0 || i > size) {
        cout << "array out of bounds" << endl;
        exit(0);
    }

   NewList::iterator im = arrays.begin();
    for (int j = 0; j < i; ++j) {
        ++im;
    }

    return *im;
}

int main() {
    int n = 5;
    int arr[] = {2, 3, 4 ,5 ,6};
    NewList newList(arr, n);
    cout << "List[" << 2 << "] = " << newList[2];
}