//
// Created by ale on 15/05/23.
//
//functions to use txt files
#include "txtHandleFunctions.h"

void blankFile(std::string path, std::string init="#defaultInitString (CHANGE_ME)"){
    std::ofstream f(path);
    if(!init.empty())
        f << init;
    f.close();
}

const std::vector<std::string> strExplode(std::string s, char del)
{
    std::stringstream ss(s);
    std::string word;
    std::vector<std::string> tokens;
    while (!ss.eof()) {
        getline(ss, word, del);
        tokens.push_back(word);
    }
    return tokens;
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

void removeUserFromFile(const std::string& idUserToRemove, const std::string& path ){
    std::string line;
    std::ifstream fin;
    std::vector <std::string> tokens;
    fin.open(path);
    std::ofstream temp;
    temp.open("temp.txt");

    while (getline(fin, line)) {
        tokens = strExplode(line, '_');
        if (tokens[0] != idUserToRemove)
            temp << line << std::endl;
    }

    temp.close();
    fin.close();

    // required conversion for remove and rename functions
    remove(path.c_str());
    rename("temp.txt", path.c_str());
}

bool doesFileExist(const std::string& path){
    std::ifstream f(path);
    bool ret = f.good();
    f.close();
    return ret;
}
//function to use txt files
