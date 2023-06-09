//
// Created by ale on 16/05/23.
//

#ifndef PALANOCHATUTENTI_CUIWRAPPER_H
#define PALANOCHATUTENTI_CUIWRAPPER_H

#include "UserRegister.h"

int getArrayElementIndexEx(const int maxSize, const int minSize = 0, const std::string &message = "");

bool stringEqualsIgnoreCase(const std::string &s1, const std::string &s2);

int getfromStdinAnotherUserIndex(const UserRegister &users, const std::string &message, const User &currentUser);

int getfromStdinUserIndex(const UserRegister &users, const std::string &outputMessage = "",
                          const std::string &inputMessage = "Inserisci il numero dell'utente che vuoi utlizzare: ");

void printDivider();

int getChatMenuChoiceFromStdin();

int getMainMenuChoiceFromStdin();

int getUserMenuChoiceFromStdin();

void userMenu(UserRegister &userRegistry);

void chatMenu(const UserRegister &userRegistry);

void addUser(UserRegister &userRegistry);

void removeUser(UserRegister &userRegistry);

#endif //PALANOCHATUTENTI_CUIWRAPPER_H
