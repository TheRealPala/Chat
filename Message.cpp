//
// Created by ale on 14/05/23.
//

#include "Message.h"

std::string Message::toHash() const{
    return std::to_string(std::hash<std::string>{}(this->id_from + this->id_to + std::to_string(this->createdAt)));
}