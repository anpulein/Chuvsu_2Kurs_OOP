//
// Created by dimaa on 08.05.2022.
//

#ifndef CHUVSU_2KURS_OOP_EXPERT_H
#define CHUVSU_2KURS_OOP_EXPERT_H

#include <map>
#include <string>
#include <list>
#include <iostream>
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
            cout << "Процесс выявления проблемы завершен. ";
            if (answer == -1) {
                cout << "По полученным ответам в моей базе знаний не существует подобной проблемы\n Хотели бы вы добавить новую проблему в мою базу знаний? " << endl << "Ответ: ";
                cin >> str;
                
                if (str.find("Да") || str.find("да")) { iter->second = true; }
                else if (str.find("Нет") || str.find("нет")) { iter->second = false; }
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
            while (true) {
                cout << iter->first << endl << "Ответ: ";
                cin >> str;

                if (str.find("Да") || str.find("да")) { iter->second = true; }
                else if (str.find("Нет") || str.find("нет")) { iter->second = false; }

                if (iter == dictQuestions.end()) {
                    break;
                }

                iter.operator->();
            }
        }


};

#endif //CHUVSU_2KURS_OOP_EXPERT_H
