//
// Created by ale on 14/05/23.
//

#ifndef PALANOCHATUTENTI_USER_H
#define PALANOCHATUTENTI_USER_H


#include <string>

class User {
private:
    std::string id;
    std::string name;
    std::string surname;
    std::string mailBoxPath;

public:
    User(std::string id, std::string name, std::string surname, std::string mailBoxPath) : id(id), name(name),
                                                                                             surname(surname),
                                                                                             mailBoxPath(mailBoxPath){};

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getSurname() const;

    void setSurname(const std::string &surname);

    const std::string &getMailBoxPath() const;

    void setMailBoxPath(const std::string &mailBoxPath);
};


#endif //PALANOCHATUTENTI_USER_H
