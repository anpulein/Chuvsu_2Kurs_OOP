//
// Created by dimaa on 10.05.2022.
//

#ifndef CHUVSU_2KURS_OOP_LINKEDLIST_H
#define CHUVSU_2KURS_OOP_LINKEDLIST_H

#include <iostream>
using namespace std;

template<class Type> class LinkedList {
    private:
        // Узел
        class Node {
        public:
            Type value;
            Node *next;

            Node(Type value) : value(value), next(nullptr) {}
        };

        Node *first;
        Node *last;

    public:
        LinkedList() : first(nullptr), last(nullptr) {}

        // Проверка на наличие элементов в списке
        bool is_empty() {
            return first == nullptr;
        }

        // Добавление элемента в конец списка
        void push_back(Type value) {
            Node *p = new Node(value);

            if (is_empty()) {
                first = p;
                last = p;
                return;
            }

            last->next = p;
            last = p;
        }

        // Поиска элемента в строке
        Node* find(Type value) {
            Node* p = first;
            while (p && p->value != value) p = p->next;
            return (p && p->value == value) ? p : nullptr;
        }

        // Удаление элемента из списка
        void remove_first() {
            if (is_empty()) return;
            Node *p = first;
            first = p->next;
            delete p;
        }


        // Вывод списка в консоль
        void show() {
            if (is_empty()) return;
            Node *p = first;
            while (p) {
                cout << p->value << " ";
                p = p->next;
            }
            cout << endl;
        }


};

#endif //CHUVSU_2KURS_OOP_LINKEDLIST_H
