//
// Created by ale on 14/05/23.
//

#include "UserRegistry.h"
#include "fstream"
#include <filesystem>

const std::vector<std::string> strExplode(std::string s, char del)
{
    std::stringstream ss(s);
    std::string word;
    std::vector<std::string> *tokens = new std::vector<std::string>();
    while (!ss.eof()) {
        getline(ss, word, del);
        tokens->push_back(word);
    }
    return *tokens;
}


UserRegistry::UserRegistry(const std::string& UserRegistryPath):UserRegistryPath(UserRegistryPath){
    initRegistry();
};


bool UserRegistry::isEmpty() const{
    return std::filesystem::is_empty(this->UserRegistryPath);
}


void UserRegistry::initRegistry() {
        std::fstream f(this->UserRegistryPath.c_str());
         if(!f.good()){ // se il file non esiste, lo creo
             f.open(this->UserRegistryPath.c_str(), std::ios::out);
         }
         if(this->isEmpty()){
             f << "#id_nome_cognome_pathMailBox_createdAt\n";
         }
         f.close();
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
    std::fstream f(this->UserRegistryPath.c_str(), std::ios::app);
    if(!f.good()){
        return false;
    }
    f << user.getId() << "_" << user.getName() << "_" << user.getSurname() << "_" << user.getMailBoxPath() << "_" << user.getCreatedAt() << "\n";
    f.close();
    return true;
}