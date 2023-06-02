#include "gtest/gtest.h"
#include "../User.h"
#include "../UserRegister.h"
#include "../Chat.h"
#include "../UserChatRegister.h"

class UserChatRegisterFixture : public ::testing::Test {

protected:

    virtual void SetUp() {
        sender.getMessBox().deleteMessageBox();
        receiver.getMessBox().deleteMessageBox();
        sender = User("sender", "sender");
        receiver = User("receiver", "sender");
    }

    virtual void TearDown() {
        sender.getMessBox().deleteMessageBox();
        receiver.getMessBox().deleteMessageBox();
    }

    User sender;
    User receiver;
};

TEST_F(UserChatRegisterFixture, testGetMessagesSentWith) {
    std::vector<Message> messagesOfChat = {Message(sender.getId(), receiver.getId(), "ciao", 1, false),
                                           Message(receiver.getId(), sender.getId(), "ciao", 2, false),
                                           Message(sender.getId(), receiver.getId(), "come stai?", 3, false),
                                           Message(receiver.getId(), sender.getId(), "bene tu?", 4, false),
                                           Message(sender.getId(), receiver.getId(), "bene anche io", 5, false)};
    for (int i = 0; i < messagesOfChat.size(); i++) {
        if (i % 2 == 0)
            ASSERT_TRUE(sender.sendMessage(messagesOfChat[i], receiver));
        else
            ASSERT_TRUE(receiver.sendMessage(messagesOfChat[i], sender));
    }
    UserChatRegister ucrSender(sender);
    UserChatRegister ucrReceiver(receiver);
    std::vector<Message> messagesSentToReceiver = ucrSender.getMessagesSentWith(receiver).getChat();
    std::vector<Message> messagesSentToSender = ucrReceiver.getMessagesSentWith(sender).getChat();
    short int tmpIndexReceiver = 0;
    short int tmpIndexSender = 0;
    for (int i = 0; i < messagesOfChat.size(); i++) {
        if (i % 2 == 0)
            ASSERT_EQ(messagesOfChat[i], messagesSentToReceiver[tmpIndexReceiver++]);
        else
            ASSERT_EQ(messagesOfChat[i], messagesSentToSender[tmpIndexSender++]);
    }
}

