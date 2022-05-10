//
// Created by dimaa on 08.05.2022.
//

#ifndef CHUVSU_2KURS_OOP_KNOWLEDGEBASE_H
#define CHUVSU_2KURS_OOP_KNOWLEDGEBASE_H

#include <map>
#include <string>
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
                                           {"Провода и коннекторы внетри корпуса пк исправны? ", false},
                                           {"При отсоединении кнопки перезагрузки от мат.платы компьютер начинает работать? ",false},
                                           {"При замыкании двух контактов с надписью 'Power Swirch' происходит запуск компьютера? ", false},
                                           {"Включенный в сеть блок питания не начинает работать при замыкании черного и зеленого контактов? ", false},
                                           {"При нажатии кнопки запуска компьютер начинает работать? ", false},
                                           {"Компьютер сразу прекращает работу? ", false},
                                           {"В процессе загрузки компьютер подает характерный сигнал? ", false}};
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

            cout << "- Процесс внесения новых данных в базу знаний!" << endl;
            cout << "Добавьте наименование проблемы: ";
            cin >> pr.name;

            cout << "Добавьте список вопросов (после окончания добавления вопросов напишите 'end')" << endl;
            string str;
            while (true) {
                cin >> str;
                if (str.find("end")) {
                    break;
                }
                pr.questions.push_back(str);
            }

            cout << "Процесс внесения новых данных в базу знаний закончен!" << endl;
        }

    public:
        KnowledgeBase() {
            problem pr = {"Неисправна кнопка перезагрузки", {"Отсутствует реакция на нажатие кнопки включения? ",
                                                                              "Все кабели питания подключены правильно? ", "Провода и коннекторы внетри корпуса пк исправны? ",
                                                                              "При отсоединении кнопки перезагрузки от мат.платы компьютер начинает работать? "}};
            problems.push_back(pr);

            pr = {"Неисправна кнопка запуска", {"Отсутствует реакция на нажатие кнопки включения? ",
                                                                 "Все кабели питания подключены правильно? ", "Провода и коннекторы внетри корпуса пк исправны? ",
                                                                 "При замыкании двух контактов с надписью 'Power Swirch' происходит запуск компьютера? "}};
            problems.push_back(pr);

            pr = {"Неисправен блок питания", {"Отсутствует реакция на нажатие кнопки включения? ",
                                                               "Все кабели питания подключены правильно? ",
                                                               "Включенный в сеть блок питания не начинает работать при замыкании черного и зеленого контактов? "}};
            problems.push_back(pr);

            pr = {"Неисправен какое-либо устройства и срабатывает защита блока питания", {"При нажатии кнопки запуска компьютер начинает работать? ",
                                                                                                           "Компьютер сразу прекращает работу? "}};
            problems.push_back(pr);
        }



};

#endif //CHUVSU_2KURS_OOP_KNOWLEDGEBASE_H
