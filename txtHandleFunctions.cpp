//
// Created by ale on 15/05/23.
//
//functions to use txt files
#include "txtHandleFunctions.h"

const std::vector<std::string> strExplode(std::string s, char del)
{
    std::stringstream ss(s);
    std::string word;
    std::vector<std::string> *tokens = new std::vector<std::string>();
    while (!ss.eof()) {
        getline(ss, word, del);
        tokens->push_back(word);
    }
    return *tokens;
}


bool isTxtFileEmpty(const std::string& path){
    return std::filesystem::is_empty(path);
}


void createTxtFile(const std::string& path, const std::string& initString){
    std::fstream f(path);
    if(!f.good()){ // se il file non esiste, lo creo
        f.open(path, std::ios::out);
    }
    if(isTxtFileEmpty(path)){
        f << initString;
    }
    f.close();
}
//function to use txt files
