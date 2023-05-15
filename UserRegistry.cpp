//
// Created by ale on 14/05/23.
//

#include "UserRegistry.h"
#include "fstream"
#include <filesystem>
#include "txtHandleFunctions.h"


bool UserRegistry::isEmpty() const{
    return isTxtFileEmpty(this->UserRegistryPath);
}


UserRegistry::UserRegistry(const std::string& UserRegistryPath):UserRegistryPath(UserRegistryPath){
    initRegistry();
};


void UserRegistry::initRegistry() {
        createTxtFile(this->UserRegistryPath.c_str(), "#id_nome_cognome_pathMailBox_createdAt\n");
}


std::vector<User>& UserRegistry::getAllUsers() const {
    std::fstream f(this->UserRegistryPath.c_str(), std::ios::in);
    std::vector<User> *users = new std::vector<User>();
    std::string line;
    while (std::getline(f, line)) {
        if (line[0] == '#' || line.empty()) {
            continue;
        }
        std::vector<std::string> splittedLine = strExplode(line, '_');
        users->push_back(User(splittedLine[0], splittedLine[1], splittedLine[2], splittedLine[3], splittedLine[4]));
    }
    return *users;
}
bool UserRegistry::addUser(const User& user) const {
    //add user to the registry
    std::fstream f(this->UserRegistryPath.c_str(), std::ios::app);
    if(!f.good()){
        return false;
    }
    f << user.getId() << "_" << user.getName() << "_" << user.getSurname() << "_" << user.getMailBoxPath() << "_" << user.getCreatedAt() << "\n";
    f.close();
    return true;

}