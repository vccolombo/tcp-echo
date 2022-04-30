#include "server.h"
#include "Connection.h"

Server::Server(uint16_t port) : acceptor(io_context, tcp::endpoint(tcp::v4(), port)) {
    accept();
}

void Server::start() {
    io_context.run();
}

void Server::accept() {
    acceptor.async_accept([this](boost::system::error_code ec, tcp::socket socket) {
        if (!ec) {
            std::make_shared<Connection>(std::move(socket))->start();
        }

        accept();
    });
}
