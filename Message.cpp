//
// Created by ale on 14/05/23.
//

#include <string>
#include "Message.h"

std::string Message::toHash() const{
    return std::to_string(std::hash<std::string>{}(this->id_from + this->id_to + std::to_string(this->createdAt)));
}

bool Message::isRead() const {
    return read;
}

void Message::setRead(bool read) {
    Message::read = read;
}

void Message::toString() const{
    std::cout << "id_from: " << id_from << std::endl;
    std::cout << "id_to: " << id_to << std::endl;
    std::cout << "text: " << text << std::endl;
    time_t t = time(nullptr);
    std::cout << "createdAt: " << (std::ctime(&t) ) << std::endl;
    std::cout << "read: " << (read ? "yes":"no") << std::endl;
}
