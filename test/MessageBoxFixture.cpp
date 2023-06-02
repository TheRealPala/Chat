#include "gtest/gtest.h"
#include "../User.h"


class MessageBoxSuite : public ::testing::Test {

protected:
    User owner;
    MessageBox messBox;

    virtual void TearDown() {
        messBox.deleteMessageBox();
    }

    virtual void SetUp() {
        owner.getMessBox().deleteMessageBox();
        owner = User("nomeOwner", "cognomeOwner");
        messBox = owner.getMessBox();
    }
};


TEST_F(MessageBoxSuite, Costructor) {
    MessageBox messBox;
    ASSERT_EQ("CHANGE_ME_defaultMessageBoxPath", messBox.getPath());
    ASSERT_EQ("0", messBox.getOwnerId());
    messBox = MessageBox("newPath", "newOwnerId");
    ASSERT_EQ("newPath", messBox.getPath());
    ASSERT_EQ("newOwnerId", messBox.getOwnerId());
}

TEST_F(MessageBoxSuite, persistAndDeleteMessageBox) {
    EXPECT_TRUE(doesFileExist(owner.getMailBoxPath()));
    messBox.deleteMessageBox();
    EXPECT_FALSE(doesFileExist(owner.getMailBoxPath()));
    messBox.persistMessageBox();
    EXPECT_TRUE(doesFileExist(owner.getMailBoxPath()));
}

TEST_F(MessageBoxSuite, addAndGetMessages) {
    messBox.persistMessageBox();
    messBox.blankMessageBox();
    Message messA("125225", owner.getId(), "text", false);
    Message messB("895632", owner.getId(), "text", false);
    messBox.addMessage(messA);
    messBox.addMessage(messB);
    std::vector<Message> messages = messBox.getAllMessages();
    EXPECT_EQ(2, messages.size());
    ASSERT_EQ(messA.toHash(), messages[0].toHash());
    ASSERT_EQ(messB.toHash(), messages[1].toHash());
}