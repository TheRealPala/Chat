#include "gtest/gtest.h"

#include "../User.h"


class UserSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
    }

    User ChatUser;
};


TEST_F(UserSuite, Costructor){


    ASSERT_EQ("alphanumericId", ChatUser.getId());
    ASSERT_EQ("nameFixture", ChatUser.getName());
    ASSERT_EQ("surnameFixture", ChatUser.getSurname());
    ASSERT_EQ("alphanumericMailBoxPath.txt", ChatUser.getMailBoxPath());

}

