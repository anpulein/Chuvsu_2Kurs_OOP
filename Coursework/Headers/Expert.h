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
        bool isProblemSolved = false;

        void findAnswer() {
            for (int i = 0; i < problems.size(); ++i) {
                if (findAnswerInProblems(i)) {
                    isProblemSolved = true;
                    break;
                }
            }

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
