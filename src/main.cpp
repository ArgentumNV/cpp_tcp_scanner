#include <iostream>
#include <sys/socket.h> // для sockaddr, socket, bind, connect
#include <netinet/in.h> // для sockaddr_in, htons, htonl
#include <arpa/inet.h>  // для inet_addr
#include <string>

using std::string;

bool isPortOpen(const std::string &ip, int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        throw "Failed to create socket.";
    }

    struct sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip.c_str());
    if (addr.sin_addr.s_addr == INADDR_NONE)
    {
        throw "Invalid ip addres.";
    }

    int res = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (res < 0)
    {
        return false;
    }

    return true;
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return -1;

    int port = std::stoi(argv[1]);

    string localhost = "127.0.0.1";

    bool is_open{false};
    try
    {
        is_open = isPortOpen(localhost, port);
    }
    catch (const char *s)
    {
        std::cerr << s << '\n';
    }

    string res = (is_open) ? "open" : "close";
    std::cout << "Port: " << port << ' ' << "on IP-Address " << localhost << ' ' << res << std::endl;
    return 0;
}