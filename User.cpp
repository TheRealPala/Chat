//
// Created by ale on 14/05/23.
//

#include <iostream>
#include "User.h"

const std::string &User::getId() const {
    return id;
}

void User::setId(const std::string &id) {
    User::id = id;
}

const std::string &User::getName() const {
    return name;
}

void User::setName(const std::string &name) {
    User::name = name;
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

void User::setSurname(const std::string &surname) {
    User::surname = surname;
}

const std::string &User::getMailBoxPath() const {
    return messBoxPath;
}

void User::setMailBoxPath(const std::string &mailBoxPath) {
    User::messBoxPath = mailBoxPath;
}

const std::string User::toString() const {
    time_t date = atol(createdAt.c_str());
    return "Id: " + id + "\nName: " + name + "\nSurname: " + surname + "\nMailBox Path: " + messBoxPath + "\nCreatedAt: " +
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

    return std::to_string(std::hash<std::string>{}(this->name+this->surname+this->createdAt));
}

void User::sendMessage(const Message &m, const User &re) {
    re.messBox.addMessage(m);
}


void User::sendMessage(const std::string &text, const User &re) {
    Message m(this->id, re.getId(), text);
    re.messBox.addMessage(m);
}

void User::sendMessage(const Message &m, const MessageBox &messageBox) {
    messageBox.addMessage(m);
}

const std::string &User::getMessBoxPath() const {
    return messBoxPath;
}

void User::setMessBoxPath(const std::string &messBoxPath) {
    User::messBoxPath = messBoxPath;
}

const MessageBox &User::getMessBox() const {
    return messBox;
}

void User::setMessBox(const MessageBox &messBox) {
    User::messBox = messBox;
}

const std::vector<Message> User::getMessages() const {
    return this->messBox.getAllMessages();
}
