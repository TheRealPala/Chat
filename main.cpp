#include <iostream>
#include "UserRegistry.h"
#include "Chat.h"
#include "millisecondTime.h"

int main() {

    UserRegistry* userRegistration = new UserRegistry();
    User sender("sender", "sender");
    User receiver("receiver", "receiver");
    userRegistration->addUser(sender);
    userRegistration->addUser(receiver);
    std::vector<User> users = userRegistration->getAllUsers();
    for(auto u: users) {
        u.toString();
    }
    std::string pause = "100";
    sender.sendMessage("Hi, how are you?", receiver);
    system("sleep 0.2");
    receiver.sendMessage("Fine, thanks", sender);
    system("sleep 0.2");
    receiver.sendMessage("And you?", sender);
    system("sleep 0.2");
    sender.sendMessage("Fine, thanks", receiver);
    system("sleep 0.2");
    sender.sendMessage("Bye", receiver);
    system("sleep 0.2");
    receiver.sendMessage("Bye", sender);
    system("sleep 0.2");
    Chat chat(sender, receiver);
    chat.printChat();


    return 0;
}
