//
// Created by ale on 16/05/23.
//

#include "UserChatRegister.h"
#include "Chat.h"
#include "UserRegister.h"

Chat UserChatRegister::getMessagesSentWith(const User &user) const {
    std::vector<Message> messageSent;
    for (auto m: user.getMessages()) {
        if (m.getIdFrom() == this->user.getId()) {
            messageSent.push_back(m);
        }
    }
    return Chat(this->user, user, messageSent);
}