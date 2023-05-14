#include <iostream>
#include "UserRegistry.h"

int main() {
    UserRegistry* userRegistration = new UserRegistry();
    std::vector<User>& users = userRegistration->getAllUsers();
    for(auto u: users) {
        u.toString();
    }
    delete userRegistration;
    delete &users;
    return 0;
}
