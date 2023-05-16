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
    User(const std::string&  id, const std::string& name, const std::string& surname, const std::string& mailBoxPath, const std::string& createdAt) : id(id),
                                                                                                                                                      name(name),
                                                                                                                                                      surname(surname),
                                                                                                                                                      messBoxPath(mailBoxPath),
                                                                                                                                                      createdAt(createdAt),
                                                                                                                                                      messBox(messBoxPath, this->id){};

    const std::string &getMessBoxPath() const;

    void setMessBoxPath(const std::string &messBoxPath);

    const MessageBox &getMessBox() const;

    void setMessBox(const MessageBox &messBox);

    User(const std::string&  id, const std::string& name, const std::string& surname, const std::string& mailBoxPath) : id(id), name(name),
                                                    surname(surname), messBoxPath(mailBoxPath), messBox(messBoxPath, this->id),
                                                    createdAt(std::to_string(getCurrentUTC())){};

    User(const std::string& name, const std::string& surname){
        this->name = name;
        this->surname = surname;
        time_t now = time(nullptr);
        createdAt = std::to_string(now);
        id = this->toHash();
        messBoxPath = "config/" + this->id + ".txt";
        this->messBox = MessageBox(messBoxPath, this->id);
        messBox.persistMessageBox();
    };

    User():User("nameFixture", "surnameFixture"){};

    bool operator==(const User &rhs) const;

    bool operator!=(const User &rhs) const;

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getSurname() const;

    void setSurname(const std::string &surname);

    const std::string &getMailBoxPath() const;

    void setMailBoxPath(const std::string &mailBoxPath);

    void toString() const;

    const std::string &getCreatedAt() const;

    void setCreatedAt(const std::string &createdAt);

    std::string toHash() const;

    void sendMessage(const Message& m, const User& receiver);

    void sendMessage(const Message &m, const MessageBox &messageBox);

    void sendMessage(const std::string &m, const User &receiver);

    const std::vector<Message> getMessages() const;
};


#endif //PALANOCHATUTENTI_USER_H
