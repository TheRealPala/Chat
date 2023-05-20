#include "gtest/gtest.h"

#include "../User.h"
#include "../MessageBox.h"


class MessageBoxSuite : public ::testing::Test {

protected:
    User ownerA;
    MessageBox messBoxA;
    virtual void TearDown() {
        messBoxA.deleteMessageBox();
    }
    virtual void SetUp() {
        ownerA.getMessBox().deleteMessageBox();
        ownerA = User("nomeOwner", "cognomeOwner");
        messBoxA = ownerA.getMessBox();
    }
};


TEST_F(MessageBoxSuite, Costructor){
    MessageBox messBox;
    ASSERT_EQ("CHANGE_ME_defaultMessageBoxPath", messBox.getPath());
    ASSERT_EQ("0", messBox.getOwnerId());
    messBox = MessageBox("newPath", "newOwnerId");
    ASSERT_EQ("newPath", messBox.getPath());
    ASSERT_EQ("newOwnerId", messBox.getOwnerId());
}

