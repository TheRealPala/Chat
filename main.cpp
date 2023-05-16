#include <iostream>
#include "UserRegistry.h"
#include "Chat.h"
#include "millisecondTime.h"
#include "CuiWrapper.h"
#include "UserChatRegister.h"

int main() {
    UserRegistry userRegistry;
    User currentUser = userRegistry.getUserByIndex(getUserIndex(userRegistry));
    User reciever = userRegistry.getUserByIndex(getUserIndex(userRegistry, "Seleziona l'utente con cui chattare: "));
    currentUser.sendMessage("ciao!", reciever);
    system("sleep 0.3");
    reciever.sendMessage("bella!", currentUser);
    system("sleep 0.3");
    currentUser.sendMessage("come va?", reciever);
    Chat chat(currentUser, reciever);
    std::cout << "Chat tra " << currentUser.getName() << " e " << reciever.getName() << std::endl;
    chat.printChat();
    UserChatRegister currentUserRegister(currentUser);
    Chat sentMessageToReciever = currentUserRegister.getMessagesSentWith(reciever);
    std::cout << "Messaggi inviati a reciever" << std::endl;
    sentMessageToReciever.printChat();

    return 0;
}
