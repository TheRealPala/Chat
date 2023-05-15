#include "gtest/gtest.h"

#include "../User.h"
#include "../UserRegistry.h"


class UserRegistrySuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        blankFile();
    }
    virtual void TearDown() {
      blankFile();
      deleteTxtFile(baseUser.getMailBoxPath());
    }
    void blankFile(){
        std::string path = "config/userRegistry.txt";
        std::ofstream f(path);
        f << "#id_nome_cognome_pathMailBox_createdAt\n";
        f.close();
    }
    void deleteTxtFile(std::string path){
        std::remove(path.c_str());
    }
    User baseUser;
    User readUser;
    UserRegistry registry;
};


TEST_F(UserRegistrySuite, checkDataReadUser){
    registry.addUser(baseUser);
    readUser = registry.getAllUsers().at(0);
    ASSERT_EQ(baseUser.getId(), readUser.getId());
    ASSERT_EQ(baseUser.getName(), readUser.getName());
    ASSERT_EQ(baseUser.getSurname(), readUser.getSurname());
    ASSERT_EQ(baseUser.getCreatedAt(), readUser.getCreatedAt());
    ASSERT_EQ(baseUser.getMailBoxPath(), readUser.getMailBoxPath());
}

