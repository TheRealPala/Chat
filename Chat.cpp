//
// Created by ale on 15/05/23.
//

#include "Chat.h"
#include "CuiWrapper.h"
#include "stdlib.h"

void Chat::generateChat() {
    std::vector<Message> messagesOfSender = userSender.getMessages();
    std::vector<Message> messagesOfReceiver = userReceiver.getMessages();
    auto itSender = messagesOfSender.begin();
    auto itReceiver = messagesOfReceiver.begin();
    //merge of message in order to get an ordered chat
    while (itSender != messagesOfSender.end() && itReceiver != messagesOfReceiver.end()) {
        if (itSender->getCreatedAt() < itReceiver->getCreatedAt()) {
            chat.push_back(*itSender);
            itSender++;
        } else {
            chat.push_back(*itReceiver);
            itReceiver++;
        }
    }
    while (itSender != messagesOfSender.end()) {
        chat.push_back(*itSender);
        itSender++;
    }
    while (itReceiver != messagesOfReceiver.end()) {
        chat.push_back(*itReceiver);
        itReceiver++;
    }
}

const std::vector<Message> &Chat::getChat() const {
    return chat;
}

void Chat::printChat() const {
    if (chat.empty()) {
        std::cout << "Non ci sono messaggi da visualizzare!" << std::endl;
        return;
    }
    printDivider();
    std::cout << "Chat tra " << userSender.getShortIdentificator() << " e " << userReceiver.getShortIdentificator() << "\n" << std::endl;
    for (const auto& m: chat) {
        std::string from = m.getIdFrom() == userSender.getId() ? userSender.getName() : userReceiver.getName();
        std::cout << from << ": " << m.getText() << std::endl;
    }

}

int Chat::countAllMessages() const {
    return static_cast<int>(chat.size());
}

int Chat::countReadMessages() const {
    int count = 0;
    for (const auto& m: chat) {
        if (m.isRead()) {
            count++;
        }
    }
    return count;
}
