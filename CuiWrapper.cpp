#include <iostream>
#include <vector>

#include "UserRegistry.h"
#include "UserChatRegister.h"

//
// Created by ale on 16/05/23.
//
bool stringEqualsIgnoreCase(const std::string& s1, const std::string& s2){
    bool result;
    if(s1.size() != s2.size()){
        result = false;
    } else {
        result = true;
        for(int i = 0; i < s1.size(); i++){
            if(std::tolower(s1[i]) != std::tolower(s2[i])){
                result = false;
                break;
            }
        }
    }
    return result;
}
int getArrayElementIndexCheck(const int maxSize, const int minSize = 0, const std::string& message = ""){
    int index;
    bool loop;
    do {
        loop = false;
        if(message != "")
            std::cout << message << std::endl;
        else
            std::cout << "Inserisci un indice compreso tra " << minSize + 1 << " e " << maxSize << ": ";
        std::cin >> index;
        if(index < minSize || index > maxSize) {
            std::cout << "Indice non valido!\nRiprova!" << std::endl;
            loop = true;
        }
    } while (loop);
    return index;
}


int getArrayElementIndexEx(const int maxSize, const int minSize = 0,
                           const std::string& message = ""){
    int index = -1;
    if(message != "")
        std::cout << message << std::endl;
    else
        std::cout << "Inserisci un indice compreso tra " << minSize + 1 << " e " << maxSize << ": ";
    std::cin >> index;
    if(index <= minSize || index > maxSize) {
        throw std::out_of_range("Indice non valido!\nRiprova!");
    }
    return --index;
}


int getfromStdinUserIndex(const UserRegistry& users, const std::string& message=""){
    bool loop;
    int index;
    do {
        loop = false;
        if(message != "")
            std::cout << message << std::endl;
        int count = 0;
        for (auto u: users.getAllUsers()) {
            std::cout << ++count << ") " << std::endl;
            u.printUser();
            std::cout << std::endl;
        }
        try {
            index = getArrayElementIndexEx(users.getAllUsers().size(), 0, "Inserisci il numero dell'utente che vuoi utlizzare: ");
        } catch (std::exception &e) {
            loop = true;
            std::cout << e.what() << std::endl;
        }
    }while(loop);
    return index;
}

int getfromStdinAnotherUserIndex(const UserRegistry& users, const std::string& message, const User& currentUser){
    bool loop;
    int index;
    do {
        loop = false;
        std::cout << message << std::endl;
        int count = 0;
        for (auto u: users.getAllUsers()) {
            std::cout << ++count << ") " << std::endl;
            u.printUser();
            std::cout << std::endl;
        }
        try {
            index = getArrayElementIndexEx(users.getAllUsers().size());
        } catch (std::exception &e) {
            loop = true;
            std::cout << e.what() << std::endl;
        }
        if(users.getUserByIndex(index) == currentUser){
            loop = true;
            std::cout << "Non puoi selezionare te stesso!\nRiprova!" << std::endl;
        }
    }while(loop);
    return index;
}

int getChatMenuChoiceFromStdin(){
    for(;;) {
        std::cout << "\nOpzioni disponibili:\n1) Cambia utente\n2) Invia messaggio"
                     "\n3) Guarda chat con un altro utente\n4) Elenco di tutti i messaggi inviati con un altro utente"
                     "\n5)Esci" << std::endl;
        std::string choice;
        std::cin >> choice;
        if (stringEqualsIgnoreCase(choice, "cambia utente") || choice == "1") {
            return 1;
        } else if (stringEqualsIgnoreCase(choice, "invia messaggio") || choice == "2") {
            return 2;
        } else if (stringEqualsIgnoreCase(choice, "guarda chat con un altro utente") || choice == "3") {
            return 3;
        } else if (stringEqualsIgnoreCase(choice, "elenco di tutti i messaggi inviati") || choice == "4") {
            return 4;
        } else if (stringEqualsIgnoreCase(choice, "esci") || choice == "5") {
            return 5;
        }else {
            std::cout << "Scelta non valida!\nRiprova!" << std::endl;
        }

    }
}

int getMainMenuChoiceFromStdin(){
    for(;;) {
        std::cout << "\nOpzioni disponibili:\n1) Aggiungi utente\n2) Messaggia\n3)Esci"<< std::endl;
        std::string choice;
        std::cin >> choice;
        if (stringEqualsIgnoreCase(choice, "aggiungi utente") || choice == "1") {
            return 1;
        } else if (stringEqualsIgnoreCase(choice, "Messaggia") || choice == "2") {
            return 2;
        } else if (stringEqualsIgnoreCase(choice, "esci") || choice == "3") {
            return 3;
        }else {
            std::cout << "Scelta non valida!\nRiprova!" << std::endl;
        }
    }
}

void addUser(UserRegistry& userRegistry){
    std::string name, surname;
    std::cout << "Inserisci il nome dell'utente: ";
    std::cin >> name;
    std::cout << "Inserisci il cognome dell'utente: ";
    std::cin >> surname;
    userRegistry.addUser(User(name, surname));
    std::cout << "Utente aggiunto correttamente!" << std::endl;
}

void printDivider(){
    std::cout << "------------------------------------------" << std::endl;
}

void subMenu(const UserRegistry& userRegistry){
    User currentUser = userRegistry.getUserByIndex(getfromStdinUserIndex(userRegistry, "Lista Utenti: "));
    bool loop;
    do {
        loop = true;
        printDivider();
        std::cout << "Utente selezionato: " << currentUser.getName() + " " + currentUser.getSurname() << std::endl;
        int choice = getChatMenuChoiceFromStdin();
        switch (choice) {
            case 1: {// cambia utente
                currentUser = userRegistry.getUserByIndex(
                        getfromStdinAnotherUserIndex(userRegistry, "Seleziona il nuovo utente che vuoi utilizzare: ",
                                                     currentUser));
                std::cout << "Utente cambiato correttamente!" << std::endl;
                break;
            }
            case 2: { // invia messaggio
                User reciever = userRegistry.getUserByIndex(
                        getfromStdinAnotherUserIndex(userRegistry,
                                                     "Seleziona l'utente a cui vuoi inviare il messaggio: ",
                                                     currentUser));
                std::cout << "Scrivi il messaggio che vuoi inviare a "
                          << reciever.getName() + " " + reciever.getSurname() << std::endl;
                std::string message;
                std::cin.ignore();
                std::getline(std::cin, message);
                currentUser.sendMessage(message, reciever);
                std::cout << "Messaggio inviato correttamente!" << std::endl;
                break;
            }
            case 3: {// guarda chat con un altro utente
                User otherUser = userRegistry.getUserByIndex(
                        getfromStdinAnotherUserIndex(userRegistry, "Seleziona l'utente con cui vuoi vedere la chat: ",
                                                     currentUser));
                Chat chat(currentUser, otherUser);
                chat.printChat();
                break;
            }
            case 4: { // elenco di tutti i messaggi inviati con un altro utente
                UserChatRegister userChatRegister(currentUser);
                User otherUser = userRegistry.getUserByIndex(
                        getfromStdinAnotherUserIndex(userRegistry, "Seleziona l'utente di cui vuoi vedere i messaggi inviati: ",
                                                     currentUser));
                userChatRegister.getMessagesSentWith(otherUser).printChat();
                break;
            }
            case 5: { // esci
                loop = false;
                break;
            }
            default: {
                std::cout << "Scelta non valida!" << std::endl;
                break;
            }
        }
    } while (loop);
}