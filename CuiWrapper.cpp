#include <iostream>
#include <vector>
#include "UserRegister.h"
#include "UserChatRegister.h"

void showAllUsers(UserRegister &registry);

//
// Created by ale on 16/05/23.
//
bool stringEqualsIgnoreCase(const std::string &s1, const std::string &s2) {
    bool result;
    if (s1.size() != s2.size()) {
        result = false;
    } else {
        result = true;
        for (int i = 0; i < s1.size(); i++) {
            if (std::tolower(s1[i]) != std::tolower(s2[i])) {
                result = false;
                break;
            }
        }
    }
    return result;
}

int getArrayElementIndexEx(const int maxSize, const int minSize = 0,
                           const std::string &message = "") {
    int index = -1;
    if (!message.empty())
        std::cout << message << std::endl;
    else
        std::cout << "Inserisci un indice compreso tra " << minSize + 1 << " e " << maxSize << ": ";
    std::cin >> index;
    if (index <= minSize || index > maxSize) {
        throw std::out_of_range("Indice non valido!\nRiprova!");
    }
    return --index;
}

int getfromStdinUserIndex(const UserRegister &users, const std::string &outputMessage = "",
                          const std::string &inputMessage = "Inserisci il numero dell'utente che vuoi utlizzare: ") {
    bool loop;
    int index;
    do {
        loop = false;
        if (!outputMessage.empty())
            std::cout << outputMessage << std::endl;
        int count = 0;
        for (auto u: users.getAllUsers()) {
            std::cout << ++count << ") " << std::endl;
            u.printUser();
            std::cout << std::endl;
        }
        try {
            index = getArrayElementIndexEx(users.getAllUsers().size(), 0, inputMessage);
        } catch (std::exception &e) {
            loop = true;
            std::cout << e.what() << std::endl;
        }
    } while (loop);
    return index;
}

int getfromStdinAnotherUserIndex(const UserRegister &users, const std::string &message, const User &currentUser) {
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
        if (users.getUserByIndex(index) == currentUser) {
            loop = true;
            std::cout << "Non puoi selezionare te stesso!\nRiprova!" << std::endl;
        }
    } while (loop);
    return index;
}

int getChatMenuChoiceFromStdin() {
    for (;;) {
        std::cout << "---USER MENU---" << std::endl;
        std::cout << "Opzioni disponibili:\n1) Cambia utente\n2) Visualizza numero messaggi da leggere\n3) Invia messaggio"
                     "\n4) Guarda chat con un altro utente\n5) Elenco di tutti i messaggi inviati ad un altro utente"
                     "\n6) Visualizza le statistiche dei messaggi inviati ad un utente\n7) Esci" << std::endl;
        std::string choice;
        std::cin >> choice;
        if (stringEqualsIgnoreCase(choice, "cambia utente") || choice == "1") {
            return 1;
        } else if (stringEqualsIgnoreCase(choice, "numero messggi") || choice == "2") {
            return 2;
        } else if (stringEqualsIgnoreCase(choice, "invia messaggio") || choice == "3") {
                return 3;
        } else if (stringEqualsIgnoreCase(choice, "guarda chat con un altro utente") || choice == "4") {
            return 4;
        } else if (stringEqualsIgnoreCase(choice, "elenco di tutti i messaggi inviati") || choice == "5") {
            return 5;
        } else if (stringEqualsIgnoreCase(choice, "statistiche") || choice == "6") {
            return 6;
        } else if (stringEqualsIgnoreCase(choice, "esci") || choice == "7") {
            return 7;
        } else {
            std::cout << "Scelta non valida!\nRiprova!" << std::endl;
        }

    }
}

int getMainMenuChoiceFromStdin() {
    for (;;) {
        std::cout << "---MAIN MENU---" << std::endl;
        std::cout << "Opzioni disponibili:\n1) Gestisci utenti\n2) Messaggia\n3) Esci" << std::endl;
        std::string choice;
        std::cin >> choice;
        if (stringEqualsIgnoreCase(choice, "Gestisci Utenti") || choice == "1") {
            return 1;
        } else if (stringEqualsIgnoreCase(choice, "Messaggia") || choice == "2") {
            return 2;
        } else if (stringEqualsIgnoreCase(choice, "esci") || choice == "3") {
            return 3;
        } else {
            std::cout << "Scelta non valida!\nRiprova!" << std::endl;
        }
    }
}

int getUserMenuChoiceFromStdin() {
    for (;;) {
        std::cout << "---USER MENU---" << std::endl;
        std::cout << "Opzioni disponibili:\n1) Aggiungi utente\n2) Elimina utente\n3) Stampa lista utenti\n4) Esci"
                  << std::endl;
        std::string choice;
        std::cin >> choice;
        if (stringEqualsIgnoreCase(choice, "Aggiungi utente") || choice == "1") {
            return 1;
        } else if (stringEqualsIgnoreCase(choice, "Elimna Utente") || choice == "2") {
            return 2;
        } else if (stringEqualsIgnoreCase(choice, "Stampa lista utenti") || choice == "3") {
            return 3;
        } else if (stringEqualsIgnoreCase(choice, "esci") || choice == "4") {
            return 4;
        } else {
            std::cout << "Scelta non valida!\nRiprova!" << std::endl;
        }
    }
}

void addUser(UserRegister &userRegistry) {
    std::string name, surname;
    std::cout << "Inserisci il nome dell'utente: ";
    std::cin >> name;
    std::cout << "Inserisci il cognome dell'utente: ";
    std::cin >> surname;
    userRegistry.addUser(User(name, surname));
    std::cout << "Utente aggiunto correttamente!" << std::endl;
}

void removeUser(UserRegister &userRegistry) {
    if (!userRegistry.isEmpty()) {
        int index = getfromStdinUserIndex(userRegistry, "", "Seleziona l'utente da eliminare:");
        User userToDelete = userRegistry.getUserByIndex(index);
        userToDelete.getMessBox().deleteMessageBox();
        userRegistry.removeUser(userRegistry.getUserByIndex(index));
    } else {
        std::cout << "Errore!\nNon ci sono utenti da eliminare!" << std::endl;
    }
}

void printDivider() {
    std::cout << "------------------------------------------" << std::endl;
}

void userMenu(UserRegister &userRegistry) {
    bool loop;
    do {
        loop = true;
        printDivider();
        int choice = getUserMenuChoiceFromStdin();
        switch (choice) {
            case 1: {// aggiungi utente
                addUser(userRegistry);
                break;
            }
            case 2: { //elimina utente
                removeUser(userRegistry);
                break;
            }
            case 3: { //lista utenti
                showAllUsers(userRegistry);
                break;
            }
            case 4: { // esci
                loop = false;
                break;
            }
        }
    } while (loop);
}

void showAllUsers(UserRegister &registry) {
    if (registry.isEmpty())
        std::cout << "Il registro e'vuoto!" << std::endl;
    else
        std::cout << "Lista utenti disponibili:" << std::endl;
    registry.printAllUsers();
}

void chatMenu(const UserRegister &userRegistry) {
    User currentUser = userRegistry.getUserByIndex(
            getfromStdinUserIndex(userRegistry, "Lista Utenti: ")); // seleziona utente
    bool loop;
    do {
        loop = true;
        printDivider();
        std::cout << "Utente selezionato: " << currentUser.getShortIdentificator() << std::endl;
        int choice = getChatMenuChoiceFromStdin();
        switch (choice) {
            case 1: {// cambia utente
                currentUser = userRegistry.getUserByIndex(
                        getfromStdinAnotherUserIndex(userRegistry, "Seleziona il nuovo utente che vuoi utilizzare: ",
                                                     currentUser));
                std::cout << "Utente cambiato correttamente!" << std::endl;
                break;
            }
            case 2: { // visualiza numero messaggi da leggere
                currentUser.getMessBox().countNotReadMessages();
                break;
            }
            case 3: { // invia messaggio
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
            case 4: {// guarda chat con un altro utente
                User otherUser = userRegistry.getUserByIndex(
                        getfromStdinAnotherUserIndex(userRegistry, "Seleziona l'utente con cui vuoi vedere la chat: ",
                                                     currentUser));
                Chat chat(currentUser, otherUser);
                chat.printChat();
                break;
            }
            case 5: { // elenco di tutti i messaggi inviati con un altro utente
                UserChatRegister userChatRegister(currentUser);
                User otherUser = userRegistry.getUserByIndex(
                        getfromStdinAnotherUserIndex(userRegistry,
                                                     "Seleziona l'utente di cui vuoi vedere i messaggi inviati: ",
                                                     currentUser));
                userChatRegister.getMessagesSentWith(otherUser).printChat();
                break;
            }
            case 6: { //statistiche chat con un altro utente
                User otherUser = userRegistry.getUserByIndex(
                        getfromStdinAnotherUserIndex(userRegistry,
                                                     "Seleziona l'utente con cui vuoi vedere le statistiche della chat: ",
                                                     currentUser));
                Chat chat(currentUser, otherUser);
                chat.printChatStatistics();
            }
            case 7: { // esci
                loop = false;
                break;
            }
        }
    } while (loop);
}