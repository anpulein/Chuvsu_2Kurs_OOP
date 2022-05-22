//
// Created by dimaa on 08.05.2022.
//

#ifndef CHUVSU_2KURS_OOP_EXPERT_H
#define CHUVSU_2KURS_OOP_EXPERT_H

#include <map>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "KnowledgeBase.h"

using namespace std;

class Expert : public KnowledgeBase{
    private:
        int findAnswer() {
            for (int i = 0; i < problems.size(); ++i) {
                if (findAnswerInProblems(i)) {
                    return i;
                }
            }
            return -1;
        }

        void showAnswer() {
            string str;
            int answer = findAnswer();
            cout << "Процесс выявления проблемы завершен. " << endl;
            if (answer == -1) {
                cout << "По полученным ответам в моей базе знаний не существует подобной проблемы\n Хотели бы вы добавить новую проблему в мою базу знаний? " << endl << "Ответ: ";
                cin >> str;

                if (strstr(str.c_str(),"Да") || strstr(str.c_str(),"да")) { addProblem(); }
            } else {
                cout << "Вашей проблемой может являться: " << problems.at(answer).name << endl;
            }

            cout << "Спасибо, что воспользовались нашей системой обслуживания. Хорошего дня:)" << endl;
        }


    public:
        Expert() = default;
        map<string, bool>::iterator iter;

        void askAQuestion() {
            iter = dictQuestions.begin();
            string str;
            while (iter != dictQuestions.end()) {
                cout << iter->first << endl << "Ответ: ";
                cin >> str;

                if (strstr(str.c_str(),"Да") || strstr(str.c_str(),"да")) {
                    iter->second = true;
                }
                else if (strstr(str.c_str(),"Нет") || strstr(str.c_str(),"нет")) {
                    iter->second = false;
                }

                iter.operator++();
            }

            showAnswer();
        }


};

#endif //CHUVSU_2KURS_OOP_EXPERT_H
