//
// Created by ale on 15/05/23.
//

#include <vector>
#include "MessageBox.h"
#include <iostream>
#include "txtHandleFunctions.h"
#include "User.h"


void MessageBox::persistMessageBox() const {
    createTxtFile(this->path, "#idFrom_createdAt_read_message\n");
}

bool MessageBox::isEmpty() const {
    return isTxtFileEmpty(this->path);
}

const std::string &MessageBox::getPath() const {
    return path;
}

void MessageBox::setPath(const std::string &path) {
    MessageBox::path = path;
}

void MessageBox::addMessage(const Message &message) const {
    std::ofstream file;
    file.open(this->path, std::ios::app);
    file << message.getIdFrom() + "_" + std::to_string(message.getCreatedAt()) + "_" + (message.isRead() ? "1" : "0") + "_" + message.getText() << std::endl;
    file.close();
}

const std::vector<Message> MessageBox::getAllMessages() const {
    std::ifstream file;
    file.open(this->path);
    std::string line;
    std::vector<Message> messages;
    while (std::getline(file, line)) {
        if(line[0] == '#' || line.empty())
            continue;
        std::vector<std::string> tokens = strExplode(line, '_');//0->idFrom, 1->createdAt, 2->read, 3->text
        //from_to_createdAt_read_text
        messages.push_back(Message(tokens[0], ownerId, tokens[3], std::stol(tokens[1]), tokens[2] == "1"));
    }
    file.close();
    return messages;
}

const std::string& MessageBox::getOwnerId() const {
    return ownerId;
}

void MessageBox::setOwner(const std::string &ownerId){
    this->ownerId = ownerId;
}
