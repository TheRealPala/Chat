//
// Created by ale on 14/05/23.
//

#ifndef PALANOCHATUTENTI_USER_H
#define PALANOCHATUTENTI_USER_H

#include <ctime>
#include <string>
#include "MessageBox.h"
#include "millisecondTime.h"

class User {
private:
    std::string id;
    std::string name;
    std::string surname;
    std::string messBoxPath;
    std::string createdAt;
    MessageBox messBox;

public:
    User(const std::string &id, const std::string &name, const std::string &surname, const std::string &mailBoxPath,
         const std::string &createdAt) : id(id),
                                         name(name),
                                         surname(surname),
                                         messBoxPath(mailBoxPath),
                                         createdAt(createdAt),
                                         messBox(messBoxPath, this->id) {};

    const MessageBox &getMessBox() const;

    User(const std::string &id, const std::string &name, const std::string &surname, const std::string &mailBoxPath)
            : id(id), name(name),
              surname(surname), messBoxPath(mailBoxPath), messBox(messBoxPath, this->id),
              createdAt(std::to_string(getCurrentUTC())) {};

    User(const std::string &name, const std::string &surname) {
        this->name = name;
        this->surname = surname;
        time_t now = time(nullptr);
        createdAt = std::to_string(now);
        id = this->toHash();
        messBoxPath = "config/" + this->id + ".txt";
        this->messBox = MessageBox(messBoxPath, this->id);
        messBox.persistMessageBox();
    };

    User() : User("nameFixture", "surnameFixture") {};

    bool operator==(const User &rhs) const;

    bool operator!=(const User &rhs) const;

    const std::string &getId() const;

    const std::string &getName() const;

    const std::string &getSurname() const;

    const std::string &getMailBoxPath() const;

    const std::string toString() const;

    const std::string &getCreatedAt() const;

    void setCreatedAt(const std::string &createdAt);

    std::string toHash() const;

    bool sendMessage(const std::string &m, const User &receiver);

    const std::vector<Message> getMessages() const;

    const void printUser() const;

    bool sendMessage(const Message &m, const User &re);

    std::string getShortIdentificator() const {
        return name + " " + surname;
    }
};


#endif //PALANOCHATUTENTI_USER_H
