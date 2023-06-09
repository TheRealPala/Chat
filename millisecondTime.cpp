//
// Created by ale on 16/05/23.
//
#include <chrono>
#include "millisecondTime.h"

long getCurrentUTC() {
    std::chrono::time_point<std::chrono::system_clock> now =
            std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    return millis;
}