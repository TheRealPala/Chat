//
// Created by ale on 14/05/23.
//

#ifndef PALANOCHATUTENTI_MESSAGE_H
#define PALANOCHATUTENTI_MESSAGE_H


#include <string>
#include <ctime>
#include <iostream>
#include <chrono>
#include <sstream>
#include "millisecondTime.h"
class Message {
    std::string id_from;
    std::string id_to;
    std::string text;
    time_t createdAt; //time_t is an alias for long 
    bool read;
public:

    Message(const std::string &idFrom, const std::string &idTo, const std::string &text, const long &createdAt, const bool read): id_from(idFrom),
                                                                                                                   id_to(idTo),
                                                                                                                   text(text),
                                                                                                                   createdAt(createdAt), read(read){};

     Message(const std::string &idFrom, const std::string &idTo, const std::string &text, const long &createdAt): id_from(idFrom),
                                                                                                                                    id_to(idTo),
                                                                                                                                    text(text),
                                                                                                                                    createdAt(createdAt), read(false){};
     Message(const std::string &idFrom, const std::string &idTo, const std::string &text): id_from(idFrom),
                                                                                           id_to(idTo),text(text), read(false), createdAt(getCurrentUTC()){};
     Message():Message("alphanumericId", "alphanumericId", "textFixture"){};

    const std::string &getIdFrom() const {
        return id_from;
    }


    const std::string &getIdTo() const {
        return id_to;
    }


    const std::string &getText() const {
        return text;
    }


    const long getCreatedAt() const {
        return createdAt;
    }


    std::string toHash() const;

    bool operator==(const Message &rhs) const {
        return this->toHash() == rhs.toHash();
    }

    bool isRead() const;


};


#endif //PALANOCHATUTENTI_MESSAGE_H
