//
// Created by ale on 16/05/23.
//

#ifndef PALANOCHATUTENTI_CUIWRAPPER_H
#define PALANOCHATUTENTI_CUIWRAPPER_H
#include "UserRegistry.h"
int getArrayElementIndex(const int maxSize, const int minSize = 0, const std::string& message = "");
int getArrayElementIndexEx(const int maxSize, const int minSize = 0, const std::string& message = "");
int getMenuChoiceFromStdin();
bool stringEqualsIgnoreCase(const std::string& s1, const std::string& s2);
int getfromStdinAnotherUserIndex(const UserRegistry& users, const std::string& message, const User& currentUser);
int getfromStdinUserIndex(const UserRegistry& users, const std::string& outputMessage="",
                          const std::string& inputMessage = "Inserisci il numero dell'utente che vuoi utlizzare: ");
int getfromStdinUserIndex(const std::vector<User>& users, const std::string& outputMessage="",
                          const std::string& inputMessage = "Inserisci il numero dell'utente che vuoi utlizzare: ");
int getArrayElementIndexCheck(const int maxSize, const int minSize = 0);
void printDivider();
int getChatMenuChoiceFromStdin();
int getMainMenuChoiceFromStdin();
int getUserMenuChoiceFromStdin();
void userMenu(UserRegistry& userRegistry);
void chatMenu(const UserRegistry& userRegistry);
void addUser(UserRegistry& userRegistry);
void removeUser(UserRegistry& userRegistry);
#endif //PALANOCHATUTENTI_CUIWRAPPER_H
