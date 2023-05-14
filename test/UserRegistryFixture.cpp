#include "gtest/gtest.h"

#include "../User.h"
#include "../UserRegistry.h"


class UserRegistrySuite : public ::testing::Test {

protected:
    virtual void SetUp() {
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
    ASSERT_NE(baseUser.getCreatedAt(), readUser.getCreatedAt());
    ASSERT_EQ(baseUser.getMailBoxPath(), readUser.getMailBoxPath());
}

