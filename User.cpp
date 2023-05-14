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
    return mailBoxPath;
}

void User::setMailBoxPath(const std::string &mailBoxPath) {
    User::mailBoxPath = mailBoxPath;
}

void User::toString() const {
    time_t date = atol(createdAt.c_str());
    std::cout << "Id: " << id << "\nName: " << name << "\nSurname: " << surname << "\nMailBox Path: " << mailBoxPath << "\nCreatedAt: " <<
              std::ctime(&date) << std::endl;

}
