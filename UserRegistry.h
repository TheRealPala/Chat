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
public:
    explicit UserRegistry(const std::string& UserRegistryPath = "config/userRegistry.txt");
    bool addUser(const User& user) const ;
    bool removeUser(const User& user) const ;
    bool removeUser(const std::string& id) const ;
    bool findUser(const User &user) const;
    bool findUser(const std::string& id) const;
    bool isEmpty() const;
    std::vector<User>& getAllUsers() const;


};


#endif //PALANOCHATUTENTI_USERREGISTRY_H
