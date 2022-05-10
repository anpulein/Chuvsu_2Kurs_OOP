//
// Created by dimaa on 08.05.2022.
//

#ifndef CHUVSU_2KURS_OOP_EXPERT_H
#define CHUVSU_2KURS_OOP_EXPERT_H

#include <map>
#include <iostream>
#include <cstring>
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
            cout << "Process vyyavleniya problemy zavershen. " << endl;
            if (answer == -1) {
                cout << "Po poluchennym otvetam v moej baze znanij ne sushchestvuet podobnoj problemy\n Hoteli by vy dobavit' novuyu problemu v moyu bazu znanij? " << endl << "Answer: ";
                cin >> str;

                if (strstr(str.c_str(),"Yes") || strstr(str.c_str(),"yes")) { addProblem(); }
            } else {
                cout << "Vashej problemoj mozhet yavlyat'sya: " << problems.at(answer).name << endl;
            }

            cout << "Spasibo, chto vospol'zovalis' nashej sistemoj obsluzhivaniya. Horoshego dnya:)" << endl;
        }


    public:
        Expert() = default;
        map<string, bool>::iterator iter;

        void askAQuestion() {
            iter = dictQuestions.begin();
            string str;
            while (iter != dictQuestions.end()) {
                cout << iter->first << endl << "Answer: ";
                cin >> str;

                if (strstr(str.c_str(),"Yes") || strstr(str.c_str(),"yes")) {
                    iter->second = true;
                }
                else if (strstr(str.c_str(),"No") || strstr(str.c_str(),"no")) {
                    iter->second = false;
                }

                iter.operator++();
            }

            showAnswer();
        }


};

#endif //CHUVSU_2KURS_OOP_EXPERT_H
