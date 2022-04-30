#include "Connection.h"

#include <boost/asio.hpp>
#include <iostream>

void Connection::start() {
    read();
}

void Connection::read() {
    auto self(shared_from_this());
    socket.async_read_some(boost::asio::buffer(data, max_length),
                           [this, self](boost::system::error_code ec, std::size_t length) {
                               if (!ec) {
                                   std::cout << "[Connection::read] msg received: "
                                             << std::string(data, data + length)
                                             << std::endl;
                                   write(length);
                               }
                           });
}

void Connection::write(std::size_t length) {
    auto self(shared_from_this());
    boost::asio::async_write(
            socket, boost::asio::buffer(data, length),
            [this, self](boost::system::error_code ec, std::size_t) {
                if (!ec) {
                    read();
                }
            });
}
