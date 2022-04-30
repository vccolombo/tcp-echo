# TCP echo

A TCP/IP based client/server that just echos the messages. Made as a study exercise to learn about boost asio and writting servers in C++.

Based on: [Boost documentation](https://www.boost.org/doc/libs/1_78_0/doc/html/boost_asio/example/cpp11/chat/)

## How to build

```bash
git clone https://github.com/vccolombo/tcp-echo
cd server
mkdir -p build
cd build
cmake ..
make -j`nproc`

cd ../../client/
mkdir -p build
cd build
cmake ..
make -j`nproc`
```

## How to run

```bash
# From server/build
./server
```

```bash
# in another terminal
# From client/build
./client
# The terminal will wait for input
```
