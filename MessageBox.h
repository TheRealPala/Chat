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
public:
    MessageBox(const std::string& path="CHANGE_ME_defaultMessageBoxPath"):path(path){}

    const std::string &getPath() const;

    void setPath(const std::string &path);

    bool sendMessage(const Message& m);
    bool isEmpty() const;
    void persistMessageBox() const;
};


#endif //PALANOCHATUTENTI_MESSAGEBOX_H
