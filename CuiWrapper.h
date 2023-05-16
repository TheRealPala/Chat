//
// Created by ale on 16/05/23.
//

#ifndef PALANOCHATUTENTI_CUIWRAPPER_H
#define PALANOCHATUTENTI_CUIWRAPPER_H
#include "UserRegistry.h"
int getArrayElementIndex(const int maxSize, const int minSize = 0);
int getArrayElementIndexEx(const int maxSize, const int minSize = 0);
int getUserIndex(const UserRegistry& users, const std::string& message = "Utenti disponibili:\n");
#endif //PALANOCHATUTENTI_CUIWRAPPER_H
