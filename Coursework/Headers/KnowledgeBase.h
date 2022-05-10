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
        map<string, bool> dictQuestions = {{"Otsutstvuet reakciya na nazhatie knopki vklyucheniya? ", false},
                                           {"Vse kabeli pitaniya podklyucheny pravil'no? ", false},
                                           {"Provoda i konnektory vnetri korpusa pk ispravny? ", false},
                                           {"Pri otsoedinenii knopki perezagruzki ot mat.platy komp'yuter nachinaet rabotat'? ",false},
                                           {"Pri zamykanii dvuh kontaktov s nadpis'yu 'Power Swirch' proiskhodit zapusk komp'yutera? ", false},
                                           {"Vklyuchennyj v set' blok pitaniya ne nachinaet rabotat' pri zamykanii chernogo i zelenogo kontaktov? ", false},
                                           {"Pri nazhatii knopki zapuska komp'yuter nachinaet rabotat'? ", false},
                                           {"Komp'yuter srazu prekrashchaet rabotu? ", false}};
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

            cout << "- Process vneseniya novyh dannyh v bazu znanij!" << endl;
            cout << "Dobav'te naimenovanie problemy: ";
            cin >> pr.name;

            cout << "Dobav'te spisok voprosov (posle okonchaniya dobavleniya voprosov napishite 'end')" << endl;
            string str;
            while (true) {
                cin >> str;
                if (strstr(str.c_str(),"end")) {
                    break;
                }
                pr.questions.push_back(str);
            }

            cout << "Process vneseniya novyh dannyh v bazu znanij zakonchen!" << endl;
        }

    public:
        KnowledgeBase() {
            problem pr = {"Neispravna knopka perezagruzki", {"Otsutstvuet reakciya na nazhatie knopki vklyucheniya? ",
                                                             "Vse kabeli pitaniya podklyucheny pravil'no? ",
                                                             "Provoda i konnektory vnetri korpusa pk ispravny? ",
                                                             "Pri otsoedinenii knopki perezagruzki ot mat.platy komp'yuter nachinaet rabotat'? "}};
            problems.push_back(pr);

            pr = {"Neispravna knopka zapuska", {"Otsutstvuet reakciya na nazhatie knopki vklyucheniya? ",
                                                "Vse kabeli pitaniya podklyucheny pravil'no? ",
                                                "Provoda i konnektory vnetri korpusa pk ispravny? ",
                                                "Pri zamykanii dvuh kontaktov s nadpis'yu 'Power Swirch' proiskhodit zapusk komp'yutera? "}};
            problems.push_back(pr);

            pr = {"Neispraven blok pitaniya", {"Otsutstvuet reakciya na nazhatie knopki vklyucheniya? ",
                                               "Vse kabeli pitaniya podklyucheny pravil'no? ",
                                               "Vklyuchennyj v set' blok pitaniya ne nachinaet rabotat' pri zamykanii chernogo i zelenogo kontaktov? "}};
            problems.push_back(pr);

            pr = {"Neispraven kakoe-libo ustrojstva i srabatyvaet zashchita bloka pitaniya", {"Pri nazhatii knopki zapuska komp'yuter nachinaet rabotat'? ",
                                                                                              "Komp'yuter srazu prekrashchaet rabotu? "}};
            problems.push_back(pr);
        }



};

#endif //CHUVSU_2KURS_OOP_KNOWLEDGEBASE_H
