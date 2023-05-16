//
// Created by ale on 15/05/23.
//

#include "Chat.h"

void Chat::generateChat()  {
    std::vector<Message> messagesOfSender = userSender.getMessages();
    std::vector<Message> messagesOfReceiver = userReceiver.getMessages();
    std::vector<Message>::iterator itSender = messagesOfSender.begin();
    std::vector<Message>::iterator itReceiver = messagesOfReceiver.begin();
    //merge of message in order to get an ordered chat
    while(itSender != messagesOfSender.end() && itReceiver != messagesOfReceiver.end()) {
        if(itSender->getCreatedAt() < itReceiver->getCreatedAt()) {
            chat.push_back(*itSender);
            itSender++;
        } else {
            chat.push_back(*itReceiver);
            itReceiver++;
        }
    }
    while(itSender != messagesOfSender.end()) {
        chat.push_back(*itSender);
        itSender++;
    }
    while(itReceiver != messagesOfReceiver.end()) {
        chat.push_back(*itReceiver);
        itReceiver++;
    }
}

const User &Chat::getUserSender() const {
    return userSender;
}

void Chat::setUserSender(const User &userSender) {
    Chat::userSender = userSender;
}

const User &Chat::getUserReceiver() const {
    return userReceiver;
}

void Chat::setUserReceiver(const User &userReceiver) {
    Chat::userReceiver = userReceiver;
}

const std::vector<Message> &Chat::getChat() const {
    return chat;
}

void Chat::setChat(const std::vector<Message> &chat) {
    Chat::chat = chat;
}

void Chat::printChat() const {
    for(auto m: chat) {
        std::string from = m.getIdFrom() == userSender.getId() ? userSender.getName() : userReceiver.getName();
        std::cout << from << ": " << m.getText() << std::endl;
    }

}