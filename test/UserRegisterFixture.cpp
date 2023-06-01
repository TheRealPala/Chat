#include "gtest/gtest.h"
#include "../User.h"
#include "../UserRegister.h"

class UserRegistrySuite : public ::testing::Test {

protected:

    virtual void SetUp() {
        blankFile("config/userRegistry.txt", "#id_nome_cognome_pathMailBox_createdAt\n");
    }

    virtual void TearDown() {
        blankFile("config/userRegistry.txt", "#id_nome_cognome_pathMailBox_createdAt\n");
        baseUser.getMessBox().deleteMessageBox();
        readUser.getMessBox().deleteMessageBox();
        deleteFile("config/userRegistry.txt");
    }

    User baseUser;
    User readUser;
    UserRegister registry;
};

TEST_F(UserRegistrySuite, checkInitRegistry) {
    EXPECT_TRUE(doesFileExist("config/userRegistry.txt"));
    blankFile("config/userRegistry.txt", "#id_nome_cognome_pathMailBox_createdAt\n");
}

TEST_F(UserRegistrySuite, checkAddANDDataReadUser) { //check add and get user
    registry.addUser(baseUser);
    EXPECT_TRUE(registry.isUserInRegistry(baseUser));
    readUser.getMessBox().deleteMessageBox();
    readUser = registry.getAllUsers().at(0);
    EXPECT_EQ(baseUser, readUser);
    ASSERT_EQ(baseUser.getId(), readUser.getId());
    ASSERT_EQ(baseUser.getName(), readUser.getName());
    ASSERT_EQ(baseUser.getSurname(), readUser.getSurname());
    ASSERT_EQ(baseUser.getCreatedAt(), readUser.getCreatedAt());
    ASSERT_EQ(baseUser.getMailBoxPath(), readUser.getMailBoxPath());
}

TEST_F(UserRegistrySuite, checkRemoveUser) {
    blankFile("config/userRegistry.txt", "#id_nome_cognome_pathMailBox_createdAt\n");
    registry.addUser(baseUser);
    ASSERT_TRUE(registry.isUserInRegistry(baseUser));
    registry.removeUser(baseUser);
    ASSERT_FALSE(registry.isUserInRegistry(baseUser));
}

TEST_F(UserRegistrySuite, checkUpdateUsers) {
    blankFile("config/userRegistry.txt", "#id_nome_cognome_pathMailBox_createdAt\n");
    registry.addUser(baseUser);
    registry.updateUsers();
    EXPECT_TRUE(!registry.isEmpty());
    blankFile("config/userRegistry.txt", "#id_nome_cognome_pathMailBox_createdAt\n");
    registry.updateUsers();
    ASSERT_TRUE(registry.isEmpty());
}