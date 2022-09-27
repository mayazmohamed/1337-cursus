/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsConfig.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:05:00 by momayaz           #+#    #+#             */
/*   Updated: 2022/09/27 13:30:58 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parsConfig.hpp"


parsConfig::parsConfig(/* args */)
{
	std::ifstream read;
    std::string line;

    _serv = new std::vector<server>;
    
    read.open("configFileEx.config");

    while (getline(read, line)){
        _content += line;
        _content += "\n";
    }
    checkBrak();
    parsFile();

}

parsConfig::~parsConfig()
{
}

void parsConfig::checkBrak(){
     int br = 0;
    for (size_t i = 0; i < _content.length(); i++)
    {
        if (_content[i] == '{')
            br++;
        else if (_content[i] == '}')
            br--;
        if (br < 0)
            exit(1);
    }
    if (br != 0)
        exit(1);
}

std::vector<server> *parsConfig::parsFile(){
    std::vector<server> *result = new std::vector<server>();

	size_t pos = 0;
	size_t nextPos = _content.find_first_not_of(" \t\n", pos);
	if (nextPos == std::string::npos)
		exit(1);
	while (nextPos != std::string::npos)
	{
		pos = _content.find_first_not_of(" \t\n", nextPos);
		nextPos = _content.find_first_of(" \t\n", pos);
		std::string key = _content.substr(pos, nextPos - pos);
		if (key != "server")
			exit(1);
		server server = parsServ(&nextPos);
		result->push_back(server);
	}
    for (std::vector<server>::iterator it = result->begin(); it < result->end(); it++)
    {
        std::cout<< "**************************************************\n";
        it->printServer();
    }
	return result;
    
}


server parsConfig::parsServ(size_t *p){
    server result;
	size_t keyStart;
	size_t valueEnd;
    size_t nextPos;
    size_t pos;
    std::string key;
    std::string value;

	pos = _content.find_first_not_of(" \t\n", *p);
	if (pos == std::string::npos || _content[pos] != '{')
		exit(1);
		
	pos++;
	nextPos = _content.find_first_not_of(" \t\n", pos);
	while (nextPos != std::string::npos)
	{
        pos = _content.find_first_not_of(" \t\n", nextPos);
		if (pos == std::string::npos)
				exit(1);
		keyStart = pos;
        nextPos = _content.find_first_of(" \t\n", pos);
		if (nextPos == std::string::npos)
				exit(1);
		key = _content.substr(pos, nextPos - pos);
		if (key == "}")
		{
			*p = _content.find_first_not_of(" \n\t", nextPos + 1);
			break;
		}

		if (key == "location")
		{
			result._location.push_back(parsLocat(&nextPos));
		}
		else
		{
            pos = _content.find_first_not_of(" \t\n", nextPos);
			if (pos == std::string::npos)
					exit(1);
            nextPos = _content.find_first_of("\n", pos);
			if (nextPos == std::string::npos)
					exit(1);
			if ((valueEnd = syntax(_content.substr(keyStart, nextPos - keyStart))) == -1)
				exit(1);
			if (valueEnd == 0)
				continue;
			value = _content.substr(pos, valueEnd - pos + keyStart + 1);
			if (serverValue(&result, key, value) == -1)
				exit(1);
		}
	}
	return result;
}

int parsConfig::syntax(std::string value){
    size_t com;
    size_t i;
    size_t j;
    
    com = value.find_first_of("#");
    if (com != std::string::npos){
        value.erase(com);
        com = value.find_first_not_of(" \t\n");
        if (com != std::string::npos)
            return 0;
    }
    i = value.find_first_of(";");
    if (i == std::string::npos)
        return -1;
    j = value.find_first_not_of(" \n\t", i + 1, value.length() - i - 1);
    if (j != std::string::npos)
        return -1;
    j = value.find_last_not_of(" \t", i - 1);
    return j;
}


int parsConfig::serverValue(server* server, std::string key, std::string value){
    size_t pos;
    if (key == "listen"){
        pos = value.find_first_of(':');
        int port;
		if (pos == std::string::npos){
            int point = value.find_first_of(".");
            if (point != std::string::npos){
                port = 80;
                if (server->_listen.find(80) != server->_listen.end())
		    	    exit(1);
			    server->_listen[port] = value;
            }
            else{
		        port = atoi(value.c_str());
                if (port < 1 || port > 65535)
                    exit(1);
                if (server->_listen.find(port) != server->_listen.end())
		    	    exit(1);
                server->_listen[port] = "127.0.0.1";
            }
		}
		else{
			std::vector<std::string> tmp ;
            std::stringstream split(value);
            std::string temp;
    
            while (getline(split, temp, ':'))
                tmp.push_back(temp);
		    port = atoi(tmp[1].c_str());
            if (port < 1 || port > 65535)
                exit(1);
		    if (server->_listen.find(port) != server->_listen.end())
		    	exit(1);
		    server->_listen[port] = tmp[0];
		}
	}
    else if (key == "server_name")
		server->_servName = value;
    else if (key == "root")
		server->_root = value;
    else if (key == "autoindex")
		server->_autoIndex = value == "of" ? false : true ;
	else if (key == "client_body_limit")
		server->_clientBodyLimit = atoi(value.c_str());
	else if (key == "recv_timeout")
		server->_recvTimeout.tv_sec = atoi(value.c_str());
	else if (key == "send_timeout")
		server->_sendTimeout.tv_sec = atoi(value.c_str());
    else if (key == "index"){
        std::stringstream split(value);
        std::string temp;
 
        while (getline(split, temp, ' '))
            server->_index.push_back(temp);
             
    }
    else if (key == "redirection"){
        std::vector<std::string> tmp ;
        std::stringstream split(value);
        std::string temp;
        while (getline(split, temp, ' '))
            tmp.push_back(temp);
        server->_status = atoi(tmp[0].c_str());
        server->_url = tmp[1];
    }
    else if (key == "error_page"){
        std::vector<std::string> tmp ;
        std::stringstream split(value);
        std::string temp;
 
        while (getline(split, temp, ' '))
            tmp.push_back(temp);
        std::string page = tmp[tmp.size() - 1];
        for (unsigned long i = 0; i != tmp.size() - 1; i++)
		{
			int errorCode = atoi(tmp[i].c_str());
			if (server->_errorPages.find(errorCode) != server->_errorPages.end())
				continue;
			server->_errorPages[errorCode] = page;
		}
    }
    else if (key == "allow_methods"){
        std::stringstream split(value);
        std::string temp;
 
        while (getline(split, temp, ' '))
            server->_allowMethod.push_back(temp);
    }
    else if (key == "upload_path")
        server->_uploadPath = value;
    else
        return -1;
    return 1;
}

location parsConfig::parsLocat(std::size_t *p){
    location result;
	size_t keyStart;
	size_t valueEnd;
    size_t pos;
    size_t nextPos;
    std::string key;
    std::string value;

	pos = _content.find_first_not_of(" \t\n", *p);
	nextPos = _content.find_first_of(" \t\n", pos);
	result._path = _content.substr(pos, nextPos - pos);

	pos = _content.find_first_not_of(" \t\n", nextPos);
	if (pos == std::string::npos || _content[pos] != '{')
		exit(1);
		
	pos++;
	nextPos = _content.find_first_not_of(" \t\n", pos);
	while (nextPos != std::string::npos)
	{
        pos = _content.find_first_not_of(" \t\n", nextPos);
		if (pos == std::string::npos)
				exit(1);
		keyStart = pos;
        nextPos = _content.find_first_of(" \t\n", pos);
		if (nextPos == std::string::npos)
				exit(1);
		key = _content.substr(pos, nextPos - pos);
		if (key == "}")
		{
			*p = nextPos;
			break;
		}
		else
		{
            pos = _content.find_first_not_of(" \t\n", nextPos);
			if (pos == std::string::npos)
					exit(1);
            nextPos = _content.find_first_of("\n", pos);
			if (nextPos == std::string::npos)
					exit(1);
			if ((valueEnd = syntax(_content.substr(keyStart, nextPos - keyStart))) == -1)
				exit(1);
			if ((int)valueEnd == 0)
				continue;
			value = _content.substr(pos, valueEnd - pos + keyStart + 1);
			if (locationValue(&result, key, value) == -1)
				exit(1);
		}
	}
	return result;
}

int parsConfig::locationValue(location* loc, std::string key, std::string value){
    if (key == "allow_methods"){
        std::stringstream split(value);
        std::string temp;
 
        while (getline(split, temp, ' '))
            loc->_allowMethod.push_back(temp);
    }
    else if (key == "upload_path")
        loc->_uploadPath = value;
    else if (key == "redirection"){
        std::vector<std::string> tmp ;
        std::stringstream split(value);
        std::string temp;
        while (getline(split, temp, ' '))
            tmp.push_back(temp);
        loc->_status = atoi(tmp[0].c_str());
        loc->_url = tmp[1];
    }
    else if (key == "error_page"){
        std::vector<std::string> tmp ;
        std::stringstream split(value);
        std::string temp;
 
        while (getline(split, temp, ' '))
            tmp.push_back(temp);
        std::string page = tmp[tmp.size() - 1];
        for (unsigned long i = 0; i != tmp.size() - 1; i++)
		{
			int errorCode = atoi(tmp[i].c_str());
			if (loc->_errorPages.find(errorCode) != loc->_errorPages.end())
				continue;
			loc->_errorPages[errorCode] = page;
		}
    }
     else if (key == "root")
		loc->_root = value;
    else if (key == "autoindex")
		loc->_autoIndex = value == "on" ? true : false;
    else if (key == "index"){
        std::stringstream split(value);
        std::string temp;
 
        while (getline(split, temp, ' '))
            loc->_index.push_back(temp);
             
    }
    else if (key == "redirection"){
        std::vector<std::string> tmp ;
        std::stringstream split(value);
        std::string temp;
        while (getline(split, temp, ' '))
            tmp.push_back(temp);
        loc->_status = atoi(tmp[0].c_str());
        loc->_url = tmp[1];
    }
    else if (key == "cgi_info"){
        size_t i = value.find_first_of(" ");
		if (i == std::string::npos)
			exit(1);
		size_t j = value.find_first_not_of(" ", i);
		loc->_cgiInfo[value.substr(0, i)] = value.substr(j, value.length());
    }
    else
        return -1;
    return 1;
    
}
