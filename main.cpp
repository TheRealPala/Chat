#include <iostream>
#include "UserRegister.h"
#include "CuiWrapper.h"

int main() {

    UserRegister userRegistry;
    bool loop;
    do {
        loop = true;
        int choice = getMainMenuChoiceFromStdin();
        switch (choice) {
            case 1: {// gestisci utenti
                userMenu(userRegistry);
                break;
            }
            case 2: { // mesaggia
                if (!userRegistry.enoughUsersToChat())
                    std::cout
                            << "Non ci sono abbastanza utenti disponibili!\nAggiungi almeno due utenti per messaggiare!"
                            << std::endl;
                else
                    chatMenu(userRegistry);
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
    return 0;
}
