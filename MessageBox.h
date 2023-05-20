//
// Created by ale on 15/05/23.
//

#ifndef PALANOCHATUTENTI_MESSAGEBOX_H
#define PALANOCHATUTENTI_MESSAGEBOX_H


#include <string>
#include "Message.h"
#include "txtHandleFunctions.h"

class MessageBox {
private:
    std::string path;
    std::string ownerId;

public:
    MessageBox(const std::string &path = "CHANGE_ME_defaultMessageBoxPath", const std::string &ownerId = "0") : path(
            path), ownerId(ownerId) {}

    const std::string &getPath() const;

    void setPath(const std::string &path);

    bool isEmpty() const;

    void persistMessageBox() const;

    void deleteMessageBox() const;

    void addMessage(const Message &message) const;

    std::vector<Message> getAllMessages() const;

    const std::string &getOwnerId() const;

    void setOwner(const std::string &owner);

    const void blankMessageBox();
};


#endif //PALANOCHATUTENTI_MESSAGEBOX_H
