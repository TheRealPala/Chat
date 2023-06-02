#include "gtest/gtest.h"
#include "../User.h"


class UserSuite : public ::testing::Test {

protected:
    virtual void TearDown() {
        userA.getMessBox().deleteMessageBox();
        userB.getMessBox().deleteMessageBox();
        userC.getMessBox().deleteMessageBox();
    }

    virtual void SetUp() {
        userB.setCreatedAt(userA.getCreatedAt()); //condizione necessaria affinche' A == B
    }

    User userA = User("nameEQUAL", "surnameEQUAL");
    User userB = User("nameEQUAL", "surnameEQUAL");
    User userC = User("nameNOT_EQUAL", "surnameNOT_EQUAL");
};


TEST_F(UserSuite, Costructor) {
    User ChatUser("nameFixture", "surnameFixture");
    time_t now = time(nullptr);
    std::string createdAtBase = std::to_string(now);
    ChatUser.setCreatedAt(createdAtBase);
    std::string hash = ChatUser.toHash();
    ASSERT_EQ(hash, ChatUser.getId());
    ASSERT_EQ("nameFixture", ChatUser.getName());
    ASSERT_EQ("surnameFixture", ChatUser.getSurname());
    ASSERT_EQ("config/" + hash + ".txt", ChatUser.getMailBoxPath());
    ChatUser.getMessBox().deleteMessageBox();
}


TEST_F(UserSuite, hashFunction) {
    ASSERT_EQ(userA.toHash(), userB.toHash()); //prova di uguaglianza Hash su utenti uguali
    ASSERT_NE(userA.toHash(), userC.toHash()); //prova di disuguaglianza Hash su utenti non uguali
}

TEST_F(UserSuite, sendMessage) {
    ASSERT_TRUE(userA.sendMessage("text", userC));
    ASSERT_FALSE(userA.sendMessage("text", userA));
    ASSERT_FALSE(userA.sendMessage("", userA));
}

TEST_F(UserSuite, getMessage) {
    blankFile(userC.getMailBoxPath(), "#idFrom_idTo_text\n");
    std::vector<Message> messagesSent = {Message(userA.getId(), userC.getId(), "mess1", false),
                                         Message(userA.getId(), userC.getId(), "mess2", false)};
    userA.sendMessage(messagesSent[0], userC);
    userA.sendMessage(messagesSent[1], userC);
    std::vector<Message> messagesReceived = userC.getMessages();
    for (int i = 0; i < messagesSent.size(); i++) {
        ASSERT_EQ(messagesSent.at(i), messagesReceived.at(i)) << "i: " << i << std::endl;
    }
}

TEST_F(UserSuite, testCountNotReadMessages){
    blankFile(userC.getMailBoxPath(), "#idFrom_idTo_text\n");
    std::vector<Message> messagesSent = {Message(userA.getId(), userC.getId(), "mess1", false),
                                         Message(userA.getId(), userC.getId(), "mess2", false)};
    for(const auto& mess : messagesSent)
        userA.sendMessage(mess, userC);
    ASSERT_EQ(2, userC.getMessBox().countNotReadMessages());
    userC.getMessBox().markAllMessagesAsRead();
    ASSERT_EQ(0, userC.getMessBox().countNotReadMessages());
}