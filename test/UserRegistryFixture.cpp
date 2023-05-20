#include "gtest/gtest.h"

#include "../User.h"
#include "../UserRegistry.h"
#include "../txtHandleFunctions.h"

class UserRegistrySuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        blankFile("config/userRegistry.txt", "#id_nome_cognome_pathMailBox_createdAt\n");
    }
    virtual void TearDown() {
      blankFile("config/userRegistry.txt", "#id_nome_cognome_pathMailBox_createdAt\n");
      baseUser.getMessBox().deleteMessageBox();
      readUser.getMessBox().deleteMessageBox();
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
    readUser.getMessBox().deleteMessageBox();
    readUser = registry.getAllUsers().at(0);
    ASSERT_EQ(baseUser.getId(), readUser.getId());
    ASSERT_EQ(baseUser.getName(), readUser.getName());
    ASSERT_EQ(baseUser.getSurname(), readUser.getSurname());
    ASSERT_EQ(baseUser.getCreatedAt(), readUser.getCreatedAt());
    ASSERT_EQ(baseUser.getMailBoxPath(), readUser.getMailBoxPath());
}

