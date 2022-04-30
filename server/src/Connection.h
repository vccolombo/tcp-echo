#ifndef SERVER_CONNECTION_H
#define SERVER_CONNECTION_H

#include <boost/asio.hpp>
#include <memory>

using boost::asio::ip::tcp;

class Connection : public std::enable_shared_from_this<Connection> {
public:
    explicit Connection(tcp::socket socket) : socket(std::move(socket)) {}

    void start();

private:
    void read();

    void write(std::size_t length);

    tcp::socket socket;
    enum {
        max_length = 1024
    };
    char data[max_length]{};
};

#endif //SERVER_CONNECTION_H
