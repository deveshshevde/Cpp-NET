
#include <iostream>
#include <chrono>


#define ASIO_STANDALONE

#include "asio-1.30.2/include/asio.hpp"
#include "asio-1.30.2/include/asio/ts/buffer.hpp"
#include "asio-1.30.2/include/asio/ts/internet.hpp"
int main(int argc, char const *argv[])
{

    asio::error_code ErrCode;

    asio::io_context context ;

    asio::ip::tcp::endpoint endpoint(asio::ip::make_address("142.251.222.14", ErrCode), 80);

    asio::ip::tcp::socket socket(context);

    socket.connect(endpoint,ErrCode);

    if(!ErrCode){
        std::cout<< "connect success"<<std::endl;
    }
    else{
        std::cout<< "connect fail"<<std::endl;
        std::cout << ErrCode.message() << std::endl;
    }

    if(socket.is_open()){
        std::cout<< "I am opening a socket"<<std::endl;
        std::string request = "HEAD / HTTP/1.0\n\n\r";

        socket.write_some(asio::buffer(request),ErrCode);

        sleep(2);

        int byte  = socket.available();
        std::cout << "byte = " << byte << std::endl;

        if(byte>0){
            std::vector<char> vBuffer(byte); 
            socket.read_some(asio::buffer(vBuffer),ErrCode);
            for(auto c : vBuffer){
                std::cout << c;
            }
            puts("\n");
        }
    }
    return 0;
}
