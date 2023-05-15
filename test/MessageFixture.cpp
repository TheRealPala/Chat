#include "gtest/gtest.h"

#include "../User.h"


class MessageSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
    }

    Message mess;
};


TEST_F(MessageSuite, Costructor){


    ASSERT_EQ("alphanumericId", mess.getIdFrom());
    ASSERT_EQ("alphanumericId", mess.getIdTo());
    ASSERT_EQ("textFixture", mess.getText());
}

