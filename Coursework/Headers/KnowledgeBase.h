//
// Created by dimaa on 08.05.2022.
//

#ifndef CHUVSU_2KURS_OOP_KNOWLEDGEBASE_H
#define CHUVSU_2KURS_OOP_KNOWLEDGEBASE_H

#include <map>
#include <string>
#include <list>
using namespace std;

struct problem {
    string name;
    list<string> questians;
};

class KnowledgeBase {
    private:
        map<string, bool> dictQuestions = {{"Отсутствует реакция на нажатие кнопки включения? ", false},
                                           {"Все кабели питания подключены правильно? ", false},
                                           {"Провода и коннекторы внетри корпуса пк исправны? ", false},
                                           {"При отсоединении кнопки перезагрузки от мат.платы компьютер начинает работать? ",false},
                                           {"При замыкании двух контактов с надписью 'Power Swirch' происходит запуск компьютера? ", false},
                                           {"Включенный в сеть блок питания не начинает работать при замыкании черного и зеленого контактов? ", false},
                                           {"При нажатии кнопки запуска компьютер начинает работать? ", false},
                                           {"Компьютер сразу прекращает работу? ", false},
                                           {"В процессе загрузки компьютер подает характерный сигнал? ", false}};
        list<problem> problems;


};

#endif //CHUVSU_2KURS_OOP_KNOWLEDGEBASE_H
