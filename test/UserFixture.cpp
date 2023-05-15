#include "gtest/gtest.h"

#include "../User.h"


class UserSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
    }

    User ChatUser;
};


TEST_F(UserSuite, Costructor){
    time_t now = time(nullptr);
    std::string createdAtBase = std::to_string(now);
    ChatUser.setCreatedAt(createdAtBase);
    std::string hash = ChatUser.toHash();
    ASSERT_EQ(hash, ChatUser.getId());
    ASSERT_EQ("nameFixture", ChatUser.getName());
    ASSERT_EQ("surnameFixture", ChatUser.getSurname());
    ASSERT_EQ("config/" + hash +".txt", ChatUser.getMailBoxPath());

}

