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
    }

    virtual void TearDown() {
        sender.getMessBox().deleteMessageBox();
        receiver.getMessBox().deleteMessageBox();
    }

    User sender;
    User receiver;
};

TEST_F(ChatFixture, testGenerateChat) {
    Chat chat(sender, receiver);
    std::vector<Message> messagesOfChat = {Message(sender.getId(), receiver.getId(), "ciao", 1),
                                           Message(receiver.getId(), sender.getId(), "ciao", 2),
                                           Message(sender.getId(), receiver.getId(), "come stai?", 3),
                                           Message(receiver.getId(), sender.getId(), "bene tu?", 4),
                                           Message(sender.getId(), receiver.getId(), "bene anche io", 5)};
    for (int i = 0; i < messagesOfChat.size(); i++) {
        if (i % 2 == 0)
            ASSERT_TRUE(sender.sendMessage(messagesOfChat[i], receiver));
        else
            ASSERT_TRUE(receiver.sendMessage(messagesOfChat[i], sender));
    }
    chat.generateChat();
    std::vector<Message> chatGenerated = chat.getChat();
    EXPECT_EQ(chatGenerated.size(), messagesOfChat.size());
    for (int i = 0; i < chatGenerated.size(); i++) {
        EXPECT_EQ(chatGenerated[i], messagesOfChat[i]) << "The " << i << "th message is different";
    }

}

