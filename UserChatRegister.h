//
// Created by ale on 16/05/23.
//

#ifndef PALANOCHATUTENTI_USERCHATREGISTER_H
#define PALANOCHATUTENTI_USERCHATREGISTER_H


#include "User.h"
#include "Chat.h"
#include "UserRegistry.h"

class UserChatRegister {
private:
    User user;
public:
    UserChatRegister(const User& user):user(user){};
    Chat getMessagesSentWith(const User& user) const;
    std::vector<Chat>getAllMessagesSent(const UserRegistry& ur) const;
};


#endif //PALANOCHATUTENTI_USERCHATREGISTER_H
