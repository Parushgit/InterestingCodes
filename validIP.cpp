#include <iostream>
#include <string>
#include <sstream>
#include <arpa/inet.h>
 
using std::string;
using std::cout;
using std::endl;
using std::stringstream;
 
bool is_ipv4_address(const string& str);
bool is_ipv6_address(const string& str);

bool is_ipv4_address(const string& str)
{
    struct sockaddr_in sa;
    return inet_pton(AF_INET, str.c_str(), &(sa.sin_addr))!=0;
}

bool is_ipv6_address(const string& str)
{
    struct sockaddr_in sa;
    return inet_pton(AF_INET, str.c_str(), &(sa.sin_addr))!=0;
}

int main()
{
    cout <<"ipv4 succeed:"<<endl;
    cout <<is_ipv4_address("1.1.1.1") << endl;
    cout <<"ipv6 succeed:"<<endl;
    cout <<is_ipv6_address("1::8") << endl;
}
