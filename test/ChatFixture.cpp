#include "gtest/gtest.h"
#include "../User.h"
#include "../UserRegister.h"
#include "../Chat.h"

class ChatFixture : public ::testing::Test {

protected:

    virtual void SetUp() {
        sender.getMessBox().deleteMessageBox();
        receiver.getMessBox().deleteMessageBox();
        sender = User("sender", "sender");
        receiver = User("receiver", "reciever");
        messagesOfChat = {Message(sender.getId(), receiver.getId(), "ciao", 1, false),
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
    }

    virtual void TearDown() {
        sender.getMessBox().deleteMessageBox();
        receiver.getMessBox().deleteMessageBox();
    }

    User sender;
    User receiver;
    std::vector<Message> messagesOfChat;
};

TEST_F(ChatFixture, testGenerateChat) {
    Chat chat(sender, receiver);
    std::vector<Message> chatGenerated = chat.getChat();
    EXPECT_EQ(chatGenerated.size(), messagesOfChat.size());
    for (int i = 0; i < chatGenerated.size(); i++) {
        EXPECT_EQ(chatGenerated[i], messagesOfChat[i]) << "The " << i << "th message is different";
    }
}

TEST_F(ChatFixture, testChatStatistics){
    Chat chat(sender, receiver);
    ASSERT_EQ(chat.countAllMessages(), messagesOfChat.size());
    ASSERT_EQ(chat.countNotReadMessages(), 2); // 2 are the messages sent by reciever to sender
    sender.getMessBox().markAllMessagesAsRead();
    Chat newChat(sender, receiver);
    ASSERT_EQ(newChat.countNotReadMessages(), 0);
}

