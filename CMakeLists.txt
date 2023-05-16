cmake_minimum_required(VERSION 3.23)
project(PalanoChatUtenti)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(test)

set(SOURCE_FILES User.cpp User.h UserRegistry.cpp UserRegistry.h Message.cpp Message.h MessageBox.cpp MessageBox.h txtHandleFunctions.cpp txtHandleFunctions.h Chat.cpp Chat.h millisecondTime.cpp millisecondTime.h UserChatRegister.cpp UserChatRegister.h)
add_executable(PalanoChatUtenti main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(PalanoChatUtenti core)