//
// Created by ale on 14/05/23.
//

#include <iostream>
#include "User.h"

const std::string &User::getId() const {
    return id;
}

const std::string &User::getName() const {
    return name;
}

const std::string &User::getCreatedAt() const {
    return createdAt;
}

void User::setCreatedAt(const std::string &createdAt) {
    User::createdAt = createdAt;
}

const std::string &User::getSurname() const {
    return surname;
}

const std::string &User::getMailBoxPath() const {
    return messBoxPath;
}

const std::string User::toString() const {
    time_t date = atol(createdAt.c_str());
    return "Id: " + id + "\nName: " + name + "\nSurname: " + surname + "\nMailBox Path: " + messBoxPath +
           "\nCreatedAt: " +
           std::ctime(&date);
}

const void User::printUser() const {
    std::cout << this->toString();
}

bool User::operator==(const User &rhs) const {
    return (this->toHash() == rhs.toHash());
}

bool User::operator!=(const User &rhs) const {
    return !(rhs == *this);
}

std::string User::toHash() const {

    return std::to_string(std::hash<std::string>{}(this->name + this->surname + this->createdAt));
}

bool User::sendMessage(const std::string &text, const User &re) {
    if (text.empty() || re == *this) {
        return false;
    }
    Message m(this->id, re.getId(), text);
    re.messBox.addMessage(m);
    return true;
}

bool User::sendMessage(const Message &m, const User &re) {
    if (m.getText().empty() || re == *this) {
        return false;
    }
    re.messBox.addMessage(m);
    return true;
}

const MessageBox &User::getMessBox() const {
    return messBox;
}

const std::vector<Message> User::getMessages() const {
    return this->messBox.getAllMessages();
}

