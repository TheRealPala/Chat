//
// Created by ale on 14/05/23.
//

#ifndef PALANOCHATUTENTI_MESSAGE_H
#define PALANOCHATUTENTI_MESSAGE_H


#include <string>

class Message {
    std::string id_from;
    std::string id_to;
    std::string text;
    std::string createdAt;
    bool read;
public:
     Message(const std::string &idFrom, const std::string &idTo, const std::string &text, const std::string &createdAt): id_from(idFrom),
                                                                                                                                    id_to(idTo),
                                                                                                                                    text(text),
                                                                                                                                    createdAt(createdAt), read(false){};
     Message(const std::string &idFrom, const std::string &idTo, const std::string &text): id_from(idFrom),
                                                                                           id_to(idTo),text(text), read(false){
         time_t now = time(nullptr);
         createdAt = std::to_string(now);
     };
     Message():Message("alphanumericId", "alphanumericId", "textFixture"){
        time_t now = time(nullptr);
        createdAt = std::to_string(now);
    };

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

    const std::string &getCreatedAt() const {
        return createdAt;
    }

    void setCreatedAt(const std::string &createdAt) {
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
