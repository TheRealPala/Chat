#include "gtest/gtest.h"
#include "../User.h"


class MessageSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
    }
};

//PLAIN OLD CPP OBJECT: THERE IS NOT LOGIC, ONLY DATA
TEST_F(MessageSuite, Costructor) {
    Message mess;
    ASSERT_EQ("alphanumericId", mess.getIdFrom());
    ASSERT_EQ("alphanumericId", mess.getIdTo());
    ASSERT_EQ("textFixture", mess.getText());
}

TEST_F(MessageSuite, hashFunction) {
    Message messA("125225", "258985", "text", false);
    Message messB("125225", "258985", "text", false);
    Message messC("895632", "745210", "provaTestoNonUguale", false);
    ASSERT_EQ(messA.toHash(), messB.toHash()); //prova di uguaglianza Hash su messaggi uguali
    ASSERT_NE(messA.toHash(), messC.toHash()); //prova di disuguaglianza Hash su messaggi non uguali
}

