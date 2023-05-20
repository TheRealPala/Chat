//
// Created by ale on 14/05/23.
//

#include "UserRegister.h"
#include "fstream"
#include "txtHandleFunctions.h"


bool UserRegister::isEmpty() const {
    return users->empty();
}


UserRegister::UserRegister(const std::string &UserRegistryPath) : UserRegistryPath(UserRegistryPath) {
    initRegistry();
}


bool UserRegister::enoughUsersToChat() const {
    return users->size() >= 2;
}


void UserRegister::removeUser(const User &user) {
    if (!isEmpty()) {
        removeUserFromFile(user.getId(), this->UserRegistryPath);
        updateUsers();
    } else {
        std::cout << "Impossibile eliminare un utente! Il registro è vuoto!" << std::endl;
    }
}


void UserRegister::initRegistry() {
    createTxtFile(this->UserRegistryPath.c_str(), "#id_nome_cognome_pathMailBox_createdAt\n");
    users = new std::vector<User>();
    updateUsers();
}


void UserRegister::updateUsers() {
    std::fstream f(this->UserRegistryPath.c_str(), std::ios::in);
    std::string line;
    users->clear();
    while (std::getline(f, line)) {
        if (line[0] == '#' || line.empty()) {
            continue;
        }
        std::vector<std::string> splittedLine = strExplode(line, '_');
        User u(splittedLine[0], splittedLine[1], splittedLine[2], splittedLine[3], splittedLine[4]);
        users->push_back(u);
    }
}


bool UserRegister::addUser(const User &user) {
    //add user to the registry
    std::fstream f(this->UserRegistryPath.c_str(), std::ios::app);
    if (!f.good()) {
        return false;
    }
    f << user.getId() << "_" << user.getName() << "_" << user.getSurname() << "_" << user.getMailBoxPath() << "_"
      << user.getCreatedAt() << "\n";
    f.close();
    updateUsers();
    return true;
}

const User &UserRegister::getUserById(const std::string &id) const {
    for (auto &user: *users) {
        if (user.getId() == id) {
            return user;
        }
    }
    throw std::invalid_argument("User not found");
}

const std::vector<User> &UserRegister::getAllUsers() const {
    return *users;
}

void UserRegister::printAllUsers() const {
    for (auto &user: *users) {
        user.printUser();
        std::cout << std::endl;
    }
}

const bool UserRegister::isUserInRegistry(const User &user) const {
    bool found = false;
    for (auto &u: *users) {
        if (u == user) {
            found = true;
            break;
        }
    }
    return found;
}
