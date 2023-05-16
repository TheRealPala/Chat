#include <iostream>
#include <vector>

#include "UserRegistry.h"

//
// Created by ale on 16/05/23.
//
int getArrayElementIndexCheck(const int maxSize, const int minSize = 0){
    int index;
    bool loop;
    do {
        loop = false;
        std::cout << "Inserisci un indice compreso tra " << minSize + 1 << " e " << maxSize << ": ";
        std::cin >> index;
        if(index < minSize || index > maxSize) {
            std::cout << "Indice non valido!\nRiprova!" << std::endl;
            loop = true;
        }
    } while (loop);
    return index;
}


int getArrayElementIndexEx(const int maxSize, const int minSize = 0){
    int index = -1;
    std::cout << "Inserisci un indice compreso tra " << minSize + 1 << " e " << maxSize << ": ";
    std::cin >> index;
    if(index <= minSize || index > maxSize) {
        throw std::out_of_range("Indice non valido!\nRiprova!");
    }
    return --index;
}


int getUserIndex(const UserRegistry& users, const std::string& message){
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
    }while(loop);
    return index;
}

