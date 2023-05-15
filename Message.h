//
// Created by ale on 14/05/23.
//

#ifndef PALANOCHATUTENTI_MESSAGE_H
#define PALANOCHATUTENTI_MESSAGE_H


#include <string>
#include <ctime>
class Message {
    std::string id_from;
    std::string id_to;
    std::string text;
    std::time_t createdAt; //time_t is an alias for long
    bool read;
public:
     Message(const std::string &idFrom, const std::string &idTo, const std::string &text, const time_t &createdAt): id_from(idFrom),
                                                                                                                                    id_to(idTo),
                                                                                                                                    text(text),
                                                                                                                                    createdAt(createdAt), read(false){};
     Message(const std::string &idFrom, const std::string &idTo, const std::string &text): id_from(idFrom),
                                                                                           id_to(idTo),text(text), read(false){
         createdAt = time(nullptr);

     };
     Message():Message("alphanumericId", "alphanumericId", "textFixture"){};

    const std::string &getIdFrom() const {
        return id_from;
    }

    void setIdFrom(const std::string &idFrom) {
        id_from = idFrom;
    }

    const std::string &getIdTo() const {
        return id_to;
    }

    void setIdTo(const std::string &idTo) {
        id_to = idTo;
    }

    const std::string &getText() const {
        return text;
    }

    void setText(const std::string &text) {
        Message::text = text;
    }

    const time_t getCreatedAt() const {
        return createdAt;
    }

    void setCreatedAt(const time_t createdAt) {
        Message::createdAt = createdAt;
    }
    std::string toHash() const;
    bool operator==(const Message &rhs) const {
        return id_from == rhs.id_from &&
               id_to == rhs.id_to &&
               text == rhs.text &&
               createdAt == rhs.createdAt;
    }

};


#endif //PALANOCHATUTENTI_MESSAGE_H
