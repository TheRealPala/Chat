//
// Created by ale on 15/05/23.
//

#include <vector>
#include "MessageBox.h"
#include <fstream>
#include <filesystem>


void MessageBox::persistMessageBox() const {
    createTxtFile(this->path, "#idFrom_message");
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
