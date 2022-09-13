
#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <fstream>
#include <sstream>
#include <cstring> 


#define SUCCESS 1
#define FAILED -1
#define EMPTY -2




class location
{
public:
    location(/* args */);
    ~location();
    int _clientBodyLimit;
    std::string _path;
    std::vector<std::string> _allowMethods;
    std::string _root;
    std::vector<std::string> _index;
    std::map<int, std::string> _errorPages;
    std::map<std::string, std::string> _cgiInfo;
};
std::ostream& location::operator<<(std::ostream& os, const location& dt){
    std::cout << "clientBodyLimit       "<< dt._clientBodyLimit<<std::endl;
    std::cout << "_path   "<<dt._path<<std::endl;
    std::cout << "_root"<< dt._root<<std::endl;
    for (int i = 0; i < dt._allowMethods.size(); i++) 
        std::cout << "allowMethods  "<< dt._allowMethods[i] <<std::endl;

    for (int i = 0; i < dt._index.size(); i++) 
        std::cout << "index  "<< dt._index[i] <<std::endl;

    for (std::map<int , std::string>::const_iterator it = dt._errorPages.begin(); it != dt._errorPages.end(); it++){
        std::cout << "errorPages  "<< it->first << "   " << it->second <<std::endl;
    }

    for (std::map<std::string , std::string>::const_iterator it = dt._cgiInfo.begin(); it != dt._cgiInfo.end(); it++){
        std::cout << "errorPages  "<< it->first << "   " << it->second <<std::endl;
    }
}

location::location(){};
location::~location(){};

class serv
{
public:
    std::string _servName;
    std::string _listen;
    std::vector<std::string> _allowMethods;
    std::string _root;
    bool _autoIndex;
    std::vector<std::string> _index;
    int _clientBodyLimit;
    struct timeval _recvTimeout;
    struct timeval _sendTimeout;
    std::map<int, std::string> _errorPages;
    std::vector<location> _location;
    std::string _host;
    std::string _port;
    serv &operator = (const serv &f);
    serv(const serv &f);
    void printServ();


public:
    serv(/* args */);
    ~serv();
};

serv::serv(/* args */){};
serv::serv(const serv&f){
    *this = f;
}

serv::~serv(){};

serv & serv::operator=(const serv &f){
    if (this != &f){
        _servName = f._servName;
        _listen = f._listen;
        _allowMethods = f._allowMethods;
        _root = f._root;
        _autoIndex = f._autoIndex;
        _index = f._index;
        _clientBodyLimit = f._clientBodyLimit;
        _recvTimeout = f._recvTimeout;
        _sendTimeout = f._sendTimeout;
        _errorPages = f._errorPages;
        _location = f._location;
        _host = f._host;
        _port = f._port;
    }
    return *this;
}


void serv::printServ(){
    std::cout << "server name  " << _servName <<std::endl;
    std::cout << "listen  " << _listen <<std::endl;
    std::cout << "root  " << _root <<std::endl;
    std::cout << "autoIndex  " << _autoIndex <<std::endl;
    std::cout << "clientBodyLimit  " << _clientBodyLimit <<std::endl;
    std::cout << "recvTimeout  " << _recvTimeout.tv_sec <<std::endl;
    std::cout << "sendTimeout  " << _sendTimeout.tv_sec <<std::endl;
    std::cout << "host  " << _host <<std::endl;
    std::cout << "port  " << _port <<std::endl;
    for (int i = 0; i < _allowMethods.size(); i++) 
            std::cout << "allowMethods  "<< _allowMethods[i] <<std::endl;

    for (int i = 0; i < _index.size(); i++) 
            std::cout << "index  "<< _index[i] <<std::endl;
    for (int i = 0; i < _location.size(); i++){
            std::cout << _location[i] <<std::endl;
    }
    for (int i = 0; i < _allowMethods.size(); i++) 
        std::cout << "allowMethods  "<< _allowMethods[i] <<std::endl;

    for (int i = 0; i < _index.size(); i++) 
        std::cout << "index  "<< _index[i] <<std::endl;

    for (std::map<int , std::string>::const_iterator it = _errorPages.begin(); it != _errorPages.end(); it++){
        std::cout << "errorPages  "<< it->first << "   " << it->second <<std::endl;
    }

}






class configFile
{
private:
    std::string _fileContent;
    std::vector<serv> _serv;
public:
    int check_syntax(std::string value);
    void check_bra(void);
    void parsServ(serv *result, int *i);
    location parse_location(int *pos);
    int fillLocation(location *locat, const std::string key, const std::string value);
    int fillServer(serv *server, const std::string key, const std::string value);
    configFile();
    ~configFile();

};


int configFile::fillServer(serv *server, const std::string key, const std::string value){
    std::size_t pos;
    std::size_t i;
    std::string s;
    
    if (key == "root"){
        server->_root = value;
    }
    else if (key == "client_body_limit"){
        server->_clientBodyLimit = atoi(value.c_str());
    }
    else if (key == "allow_methods"){
        std::istringstream f(value);   
        while (getline(f, s, ' ')) {
           server->_allowMethods.push_back(s);
        }
    }
    else if (key == "index"){
        std::istringstream f(value);   
        while (getline(f, s, ' ')) {
           server->_index.push_back(s);
        }
    }
    else if (key == "server_name"){
        server->_servName = value;
    }
    else if (key == "autoindex"){
        if (value == "on")
            server->_autoIndex = true;
        else
            server->_autoIndex = false;
    }
    else if (key == "recv_timeout")
        server->_recvTimeout.tv_sec = atoi(value.c_str());
    else if (key == "send_timeout")
        server->_sendTimeout.tv_sec = atoi(value.c_str());
    else if (key == "listen"){
        if (value.find_first_of(':') == std::string::npos)
		{
			server->_host = "0.0.0.0";
			server->_port = value;
		}
		else
		{
			std::vector<std::string> tmp;
            std::istringstream f(value);   
            while (getline(f, s, ' ')){
                tmp.push_back(s);
            }
			if (server->_host != "" && server->_host != tmp[0])
				return FAILED;
			server->_host = tmp[0];
			server->_port = tmp[1];
		}
    }
    else if (key == "error_page"){
        std::vector<std::string> tmp;
        std::istringstream f(value);   
            while (getline(f, s, ' ')){
                tmp.push_back(s);
            }
		std::string path = tmp[tmp.size() - 1];
		for (unsigned long i = 0; i != tmp.size() - 1; i++)
		{
			int status_code = atoi(tmp[i].c_str());
			if (server->_errorPages.find(status_code) != server->_errorPages.end())
				continue;
			server->_errorPages[status_code] = path;
		}
    }
    else
        return FAILED;
    return SUCCESS;
}





int configFile::fillLocation(location *locat, const std::string key, const std::string value){
    
    std::size_t pos;
    std::size_t i;
    std::string s;
    
    if (key == "root"){
        locat->_root = value;
    }
    else if (key == "client_body_limit"){
        locat->_clientBodyLimit = atoi(value.c_str());
    }
    else if (key == "cgi_info"){
        if ((pos = value.find_first_of(" ")) == std::string::npos)
            return FAILED;
        i = value.find_first_not_of(" ", pos);
        locat->_cgiInfo[value.substr(0, pos)] = value.substr(i, value.length());
    }
    else if (key == "allow_methods"){
        std::istringstream f(value);   
        while (getline(f, s, ' ')) {
           locat->_allowMethods.push_back(s);
        }
    }
    else if (key == "index"){
        std::istringstream f(value);   
        while (getline(f, s, ' ')) {
           locat->_index.push_back(s);
        }
    }
    else if (key == "error_page"){
        std::vector<std::string> tmp;
        std::istringstream f(value);   
            while (getline(f, s, ' ')){
                tmp.push_back(s);
            }
		std::string path = tmp[tmp.size() - 1];
		for (unsigned long i = 0; i != tmp.size() - 1; i++)
		{
			int status_code = atoi(tmp[i].c_str());
			if (locat->_errorPages.find(status_code) != locat->_errorPages.end())
				continue;
			locat->_errorPages[status_code] = path;
		}
    }
    else
        return FAILED;
    return SUCCESS;
}



int configFile::check_syntax(std::string value){
    int toFind;
    int find;
    
    if (value.find_first_not_of(" \t\n") != std::string::npos)
        return EMPTY;
    toFind = value.find_first_of(";");
    if (toFind == std::string::npos)
        return FAILED;
    find = value.find_first_not_of(" \t\n", toFind + 1, value.length() - toFind - 1);
    if (find == std::string::npos)
        return FAILED;
    find = value.find_first_not_of(" \t", toFind - 1);
    return find;
};



location configFile::parse_location(int *pos){
    location res;
    std::size_t key_start;
    std::size_t value_end;
    std::size_t nextPos;
    std::size_t np;
    std::string key;
    std::string value;

    np = _fileContent.find_first_not_of(" \t\n", *pos);
    nextPos = _fileContent.find_first_of(" \t\n", np);
    res._path = _fileContent.substr(np, nextPos - np);
    np= _fileContent.find_first_not_of(" \t\n", nextPos);
    std::cout << np<< "-----------" << nextPos<< std::endl;
    if (np== std::string::npos || _fileContent[np] != '{')
        exit(1);
    std::cout<< "here" << std::endl;
    np++;
    nextPos = _fileContent.find_first_not_of(" \t\n", np);
    while (nextPos != std::string::npos)
    {
        np = _fileContent.find_first_not_of(" \t\n", nextPos);
        nextPos = _fileContent.find_first_of(" \t\n", np); 
        if (np == std::string::npos || nextPos == std::string::npos)
            exit(1);
        key_start = np;
        key = _fileContent.substr(np, nextPos - np);
        if (key == "}"){
            *pos = nextPos;
            break;
        }
        else{
            np = _fileContent.find_first_not_of(" \t\n", nextPos);
            nextPos = _fileContent.find_first_of(" \t\n", np); 
            if (np == std::string::npos || nextPos == std::string::npos)
                exit(1);
            value = _fileContent.substr(key_start, nextPos - key_start);
            value_end = check_syntax(value);
            if (value_end == FAILED)
                exit(1);
            if (value_end == EMPTY)
                continue;
            value = _fileContent.substr(np, value_end - np + key_start + 1);
            if (fillLocation(&res, key, value) == FAILED)
                exit(1);
        }
    }
    return res;
}

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

void configFile::parsServ(serv *result,int *i){
	std::size_t key_start;
	std::size_t value_end;
    std::string key;
    std::size_t pos;
    int nextPos;
    std::string value;

	pos = _fileContent.find_first_not_of(" \t\n", *i);
	if (pos == std::string::npos || _fileContent[pos] != '{')
		exit(1);
		
	pos++;
	nextPos = _fileContent.find_first_not_of(" \t\n", pos);
	while (nextPos != std::string::npos)
	{
		if ((pos = _fileContent.find_first_not_of(" \t\n", nextPos)) == std::string::npos)
				exit(1);
		key_start = pos;
		if ((nextPos = _fileContent.find_first_of(" \t\n", pos)) == std::string::npos)
				exit(1);
		key = _fileContent.substr(pos, nextPos - pos);
		if (key == "}")
		{
			*i = _fileContent.find_first_not_of(" \n\t", nextPos + 1);
			break;
		}

		if (key == "location")
		{
			result->_location.push_back(parse_location(&nextPos));
		}
		else
		{
			if ((pos = _fileContent.find_first_not_of(" \t\n", nextPos)) == std::string::npos)
					exit(1);
            std::cout<< pos<< std::endl;
			if ((nextPos = _fileContent.find_first_of("\n", pos)) == std::string::npos)
					exit(1);
			if ((value_end = check_syntax(_fileContent.substr(key_start, nextPos - key_start))) == FAILED)
				exit(1);
			if ((int)value_end == EMPTY)
				continue;
			value = _fileContent.substr(pos, value_end - pos + key_start + 1);
			if (fillServer(result, key, value) == FAILED)
				exit(1);
		}
	}
}


configFile::configFile()
{
    std::string line;
    std::ifstream config;
    std::string key;
    serv server;

    config.open ("configFileEx.config");
    if (!config.is_open()){
        std::cerr <<"ERROR file open failed.\n";
        exit(1);
    }
    while (std::getline(config, line)){
        _fileContent += line;
        _fileContent += "\n";
        
    }
    config.close();
    check_bra();
    size_t pos = 0;
	int nextPos = _fileContent.find_first_not_of(" \t\n", pos);
    if (nextPos == std::string::npos)
        exit(1);
        
    while (nextPos != std::string::npos){
        pos = _fileContent.find_first_not_of(" \t\n", nextPos);
        nextPos = _fileContent.find_first_of(" \t\n", pos);
        key = _fileContent.substr(pos, nextPos - pos);
        std::cout << key << std::endl;
        if (key != "server")
            exit(1);
        parsServ(&server, &nextPos);
    }
    std::cout<< _fileContent;
}

configFile::~configFile()
{
}

#endif