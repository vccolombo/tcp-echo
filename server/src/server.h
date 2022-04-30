#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <boost/asio.hpp>
#include <cstdint>

using boost::asio::ip::tcp;

class Server {
public:
    explicit Server(uint16_t port);

    void start();

private:
    void accept();

    boost::asio::io_context io_context;
    tcp::acceptor acceptor;
};

#endif //SERVER_SERVER_H