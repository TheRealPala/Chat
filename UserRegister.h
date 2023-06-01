//
// Created by ale on 14/05/23.
//

#ifndef PALANOCHATUTENTI_USERREGISTER_H
#define PALANOCHATUTENTI_USERREGISTER_H


#include <vector>
#include "User.h"

class UserRegister {
private:
    std::string UserRegistryPath;

    void initRegistry();

    std::vector<User> *users;
public:
    ~UserRegister() {
        delete users;
    }

    explicit UserRegister(const std::string &UserRegistryPath = "config/userRegistry.txt");

    bool addUser(const User &user);

    void removeUser(const User &user);

    void printAllUsers() const;

    bool isEmpty() const;

    const std::vector<User> &getAllUsers() const;

    const User &getUserByIndex(const int index) const {
        return users->at(index);
    }

    void updateUsers();

    bool enoughUsersToChat() const;

    const bool isUserInRegistry(const User &user) const;
};


#endif //PALANOCHATUTENTI_USERREGISTER_H
