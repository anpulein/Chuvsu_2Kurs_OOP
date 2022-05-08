//
// Created by dimaa on 12.02.2022.
//

#ifndef UNTITLED_FAMILY_H
#define UNTITLED_FAMILY_H

#include <string>

//enum Status {
//    STUDENT,
//    WORKER,
//    PENSIONER
//};

class Family {
    private:
        std::string surName; // Фамилия
        std::string name; // Имя
        std::string patronymic; // Отчество
        int age; // Возраст
        std::string sex; // Пол
        std::string status; // Статус


        class Finance {
            private:
                int income; // Доход
        };

        Family::Finance finance;

    public:

        Family(); // Конструктор без параметров
        Family(std::string surName, std::string name, std::string patronymic); // Конструктор для ФИО
        Family(std::string surName, std::string name, std::string patronymic, int age); // Конструктор (ФИОб возраст)
        Family(std::string surName, std::string name, std::string patronymic, int age, // Полный конструктор
               std::string sex, std::string status);

        std::string getSurName() const;
        void setSurName(std::string surName);
        std::string getName() const;
        void setName(std::string name);
        std::string getPatronymic() const;
        void setPatronymic(std::string patronymic);
        std::string getFullName() const;
        int getAge() const;
        void setAge(int age);
        std::string isSex() const;
        void setSex(std::string sex);
        std::string getStatus() const;
        void setStatus(std::string status);
        Finance getFinance() const;
        void setFinance(Finance finance);
};

Family::Family() {};
Family::Family(std::string surName, std::string name, std::string patronymic) {
    Family::surName = surName;
    Family::name = name;
    Family::patronymic = patronymic;
};
Family::Family(std::string surName, std::string name, std::string patronymic, int age) {
    Family::surName = surName;
    Family::name = name;
    Family::patronymic = patronymic;
    Family::age = age;
};
Family::Family(std::string surName, std::string name, std::string patronymic, int age,
        std::string sex, std::string status) {
    Family::surName = surName;
    Family::name = name;
    Family::patronymic = patronymic;
    Family::age = age;
    Family::sex = sex;
    Family::status = status;
}


std::string Family::getSurName() const {
    return surName;
}

void Family::setSurName(std::string surName) {
    Family::surName = surName;
}

std::string Family::getName() const {
    return name;
}

void Family::setName(std::string name) {
    Family::name = name;
}

std::string Family::getPatronymic() const {
    return patronymic;
}

void Family::setPatronymic(std::string patronymic) {
    Family::patronymic = patronymic;
}

 std::string Family::getFullName() const {
    return Family::surName + " " + Family::name + " " + Family::patronymic;
}

int Family::getAge() const {
    return age;
}

void Family::setAge(int age) {
    Family::age = age;
}

std::string Family::isSex() const {
    return sex;
}

void Family::setSex(std::string sex) {
    Family::sex = sex;
}

std::string Family::getStatus() const {
    return status;
}

void Family::setStatus(std::string status) {
    Family::status = status;
}

Family::Finance Family::getFinance() const {
    return finance;
}

void Family::setFinance(Family::Finance finance) {
    Family::finance = finance;
}


#endif //UNTITLED_FAMILY_H
