//
// Created by ale on 14/05/23.
//

#ifndef PALANOCHATUTENTI_USERREGISTRY_H
#define PALANOCHATUTENTI_USERREGISTRY_H


#include <vector>
#include "User.h"

class UserRegistry {
private:
    std::string UserRegistryPath;
    void initRegistry();
    std::vector<User> *users;
public:
    ~UserRegistry(){
        delete users;
    }
    explicit UserRegistry(const std::string& UserRegistryPath = "config/userRegistry.txt");
    bool addUser(const User& user);
    void removeUser(const User& user);
    void printAllUsers() const;
    bool removeUser(const std::string& id) const ;
    bool findUser(const User &user) const;
    bool findUser(const std::string& id) const;
    bool isEmpty() const;
    const std::vector<User>& getAllUsers() const;
    const User& getUserById(const std::string& id) const;
    const bool isUserInRegistry(const User& user) const;
    const User& getUserByIndex(const int index) const {
        return users->at(index);
    }


    void updateUsers();

    bool enoughUsersToChat() const;

    bool deleteUser(const User &u);

    void removeUser();

};


#endif //PALANOCHATUTENTI_USERREGISTRY_H
