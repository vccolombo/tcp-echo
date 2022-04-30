#include <cstdint>
#include <exception>
#include <iostream>

#include "server.h"

int main() {
    try {
        uint16_t port = 1337;
        Server s(port);
        s.start();
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}