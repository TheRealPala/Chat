//
// Created by ale on 15/05/23.
//

#ifndef PALANOCHATUTENTI_TXTHANDLEFUNCTIONS_H
#define PALANOCHATUTENTI_TXTHANDLEFUNCTIONS_H

#include "fstream"
#include <filesystem>
#include <vector>

const std::vector<std::string> strExplode(std::string s, char del);


bool isTxtFileEmpty(const std::string& path);


void createTxtFile(const std::string& path, const std::string& initString="#defaultInitString (CHANGE_ME)");
#endif //PALANOCHATUTENTI_TXTHANDLEFUNCTIONS_H
