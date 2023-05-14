//
// Created by ale on 14/05/23.
//

#ifndef PALANOCHATUTENTI_USER_H
#define PALANOCHATUTENTI_USER_H

#include <ctime>
#include <string>

class User {
private:
    std::string id;
    std::string name;
    std::string surname;
    std::string mailBoxPath;
    std::string createdAt;

public:
    User(std::string id, std::string name, std::string surname, std::string mailBoxPath, std::string createdAt) : id(id), name(name),
                                                                                           surname(surname),
                                                                                           mailBoxPath(mailBoxPath),
                                                                                           createdAt(createdAt){};

    User(std::string id, std::string name, std::string surname, std::string mailBoxPath) : id(id), name(name),
                                                                                             surname(surname),
                                                                                             mailBoxPath(mailBoxPath){
        time_t now = time(nullptr);
        createdAt = std::to_string(now);
    };

    User():User("alphanumericId", "nameFixture", "surnameFixture", "alphanumericMailBoxPath.txt"){
        time_t now = time(nullptr);
        createdAt = std::to_string(now);
    };

    bool operator==(const User &rhs) const;

    bool operator!=(const User &rhs) const;

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getSurname() const;

    void setSurname(const std::string &surname);

    const std::string &getMailBoxPath() const;

    void setMailBoxPath(const std::string &mailBoxPath);

    void toString() const;

    const std::string &getCreatedAt() const;

    void setCreatedAt(const std::string &createdAt);
};


#endif //PALANOCHATUTENTI_USER_H
