//
// Created by ale on 15/05/23.
//

#ifndef PALANOCHATUTENTI_CHAT_H
#define PALANOCHATUTENTI_CHAT_H


#include "User.h"

class Chat {
private:
    User userSender;
    User userReceiver;
    std::vector<Message> chat;


public:
    Chat(const User &userSender, const User &userReceiver) : userSender(userSender), userReceiver(userReceiver) {
        generateChat();
    }
    Chat(const User &userSender, const User &userReceiver, const std::vector<Message> &chat) : userSender(userSender), userReceiver(userReceiver), chat(chat) {}

    void generateChat();

    const User &getUserSender() const;

    const std::vector<Message> &getChat() const;

    void setChat(const std::vector<Message> &chat);

    void setUserSender(const User &userSender);

    const User &getUserReceiver() const;

    void setUserReceiver(const User &userReceiver);

    void printChat() const;

};


#endif //PALANOCHATUTENTI_CHAT_H
