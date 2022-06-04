//
// Created by dimaa on 08.05.2022.
//

#ifndef CHUVSU_2KURS_OOP_KNOWLEDGEBASE_H
#define CHUVSU_2KURS_OOP_KNOWLEDGEBASE_H

#include <map>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

struct problem {
    string name;
    vector<string> questions;
};

class KnowledgeBase {
    private:
        int countProblems = 4;
    protected:
        map<string, bool> dictQuestions = {{"Отсутствует реакция на нажатие кнопки включения? ", false},
                                           {"Все кабели питания подключены правильно? ", false},
                                           {"Провода и коннекторы внутри ПК исправны? ", false},
                                           {"При отсоединении кнопки перезагрузки от материнской платы начинает работать? ",false},
                                           {"При замыкании двух контактов с надписью 'Power Switch' происходит запуск компьютера? ", false},
                                           {"Включенный в сеть кабель блок питания не начинает работать при замыкании черного и зеленого контактов? ", false},
                                           {"При нажатии кнопки запуска компьютер начинает работать? ", false},
                                           {"Компьютер сразу прекращает работу? ", false}};
        vector<problem> problems;

        bool findAnswerInProblems(int index) {
            problem pr = problems.at(index);
            string question;
            for (int i = 0; i < pr.questions.size(); ++i) {
                question = pr.questions.at(i);
                if (!dictQuestions[question]) {
                    return false;
                }
            }

            return true;
        }

        void addProblem() {
            problem pr;

            cout << "- Процесс внесения данных в базу знаний!" << endl;
            cout << "Добавьте наименования проблемы: ";
            cin >> pr.name;

            cout << "Добавьте список вопросов (после окончания добавления вопросов напишите 'end')" << endl;
            string str;
            while (true) {
                cin >> str;
                if (strstr(str.c_str(),"end")) {
                    break;
                }
                pr.questions.push_back(str);
            }

            cout << "Процесс внесения новый данных в базу знаний закончен!" << endl;
        }

    public:
        KnowledgeBase() {
            problem pr = {"Неисправна кнопка перезагрузки", {"Отсутствует реакция на нажатие кнопки включения? ",
                                                                              "Все кабели питания подключены правильно? ",
                                                                              "Провода и коннекторы внутри ПК исправны? ",
                                                                              "При отсоединении кнопки перезагрузки от материнской платы начинает работать? "}};
            problems.push_back(pr);

            pr = {"Неисправна кнопка запуска", {"Отсутствует реакция на нажатие кнопки включения? ",
                                                                 "Все кабели питания подключены правильно? ",
                                                                 "Провода и коннекторы внутри ПК исправны? ",
                                                                 "При замыкании двух контактов с надписью 'Power Switch' происходит запуск компьютера? "}};
            problems.push_back(pr);

            pr = {"Неисправен блок питания", {"Отсутствует реакция на нажатие кнопки включения? ",
                                                               "Все кабели питания подключены правильно? ",
                                                               "Включенный в сеть кабель блок питания не начинает работать при замыкании черного и зеленого контактов? "}};
            problems.push_back(pr);

            pr = {"Неисправно какое-либо устройство и срабатывает защита блока питания", {"При нажатии кнопки запуска компьютер начинает работать? ",
                                                                                                           "Компьютер сразу прекращает работу? "}};
            problems.push_back(pr);
        }



};

#endif //CHUVSU_2KURS_OOP_KNOWLEDGEBASE_H
