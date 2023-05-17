#include <iostream>
#include "UserRegistry.h"
#include "Chat.h"
#include "CuiWrapper.h"
#include "UserChatRegister.h"

int main() {

    UserRegistry userRegistry;
    bool loop;
    do {
        loop = true;
        int choice = getMainMenuChoiceFromStdin();
        switch (choice) {
            case 1: {// aggiungi utente
                addUser(userRegistry);
            }
            case 2: { // mesaggia
                if(!userRegistry.enoughUsersToChat())
                    std::cout << "Non ci sono utenti disponibili!\nAggiungi almeno due utenti per messaggiare!" << std::endl;
                else
                    subMenu(userRegistry);
                break;
            }
            case 3: {// esci
                loop = false;
                break;
            }
            default: {
                std::cout << "Scelta non valida!" << std::endl;
                break;
            }
        }
    } while (loop);
    subMenu(userRegistry);
    return 0;
}
