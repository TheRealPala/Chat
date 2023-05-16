//
// Created by ale on 16/05/23.
//

#include "UserChatRegister.h"
#include "Chat.h"

Chat UserChatRegister::getMessagesSentWith(const User &user) const {
    std::vector<Message> messageSent;
for(auto m: user.getMessages()) {
        if(m.getIdFrom() == user.getId()) {
            messageSent.push_back(m);
        }
    }
    return Chat(this->user, user, messageSent);
}

std::vector<Chat> UserChatRegister::getAllMessagesSent(const std::vector<User>& users) const {
    std::vector<Chat> allMessagesSent;
    for(auto u: users) {
        allMessagesSent.push_back(getMessagesSentWith(u));
    }
    return allMessagesSent;
}
