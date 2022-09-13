#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <fstream>


class location
{
public:
 location(/* args */);
 location();
 std::string _location;
 std::string _allowMethods;
 std::string _root;
 std::vector<std::string> _index;
 std::map<std::string, std::string> _cgiInfo;
};



class serv
{
public:
    std::string _servName;
    std::string _listen;
    std::string _root;
    std::string _allowMethod;
    bool _autoIndex;
    std::vector<std::string> _index;
    int _clientBodyLimit;
    struct timeval _recvTimeout;
    struct timeval _sendTimeout;
    std::map<int, std::string> _errorPages;
    std::vector<location> _location;

public:
    serv(/* args */);
    ~serv();
};

serv::serv(/* args */)
{
}

serv::~serv()
{
}


class configFile
{
private:
    std::string _fileContent;
public:
    void check_bra(void);
    configFile();
    ~configFile();

};

void configFile::check_bra(){
    int n = 0;
    for (std::size_t i = 0; _fileContent[i]; i++)
    {
        if (_fileContent[i] == '{')
            n++;
        if (_fileContent[i] == '}')
            n--;
        if (n < 0){
            std::cerr << "syntax error in config file content"<< std::endl;
            exit(1);
        }
    }
    if (n != 0){
            std::cerr << "syntax error in config file content"<< std::endl;
            exit(1);
        }
    
}

configFile::configFile()
{
    std::string line;
    std::ifstream config;

    config.open ("configFileEx");
    while (std::getline(config, line))
        _fileContent += line;
    check_bra();
    std::cout<< _fileContent;
}

configFile::~configFile()
{
}



