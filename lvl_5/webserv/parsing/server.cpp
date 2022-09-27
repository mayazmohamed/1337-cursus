/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:04:54 by momayaz           #+#    #+#             */
/*   Updated: 2022/09/27 13:32:05 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

server::server(){
    _servName = "";
    _root = "";
    _autoIndex = true;
    _clientBodyLimit = 0;
    _status = 0;
    _url = "";
    _uploadPath = "";
    _recvTimeout.tv_sec = 0;
    _sendTimeout.tv_sec = 0;
}

server::~server(){
    
}

server::server(const server &F){
    *this = F;
}

server & server::operator=(const server &F){
    if (this != &F){
        _servName = F._servName;
        _root = F._root;
        _allowMethod = F._allowMethod;
        _autoIndex = F._autoIndex;
        _index = F._index;
        _clientBodyLimit = F._clientBodyLimit;
        _recvTimeout = F._recvTimeout;
        _sendTimeout = F._sendTimeout;
        _errorPages = F._errorPages;
        _location = F._location;
        _status = F._status;
        _url = F._url;
        _listen = F._listen;
        _uploadPath = F._uploadPath;
    }
    return *this;
}

void server::printServer(){
    std::cout << "Server Name -> " << _servName << std::endl;
    std::cout << "Root -> " << _root << std::endl;
    std::cout << "Client Body Limit -> " << _clientBodyLimit << std::endl;
    std::cout << "Recv Time Out -> " << _recvTimeout.tv_sec << std::endl;
    std::cout << "Send Time Out -> " << _sendTimeout.tv_sec << std::endl;
    std::cout << "UploadPath -> " << _uploadPath << std::endl;
    std::cout << "AutoIndex -> " << _autoIndex << std::endl;
    std::cout << "Redirection Status -> " << _status << std::endl;
    std::cout << "Redirection URL -> " << _url << std::endl;
    for (std::vector<std::string>::iterator it = _allowMethod.begin(); it < _allowMethod.end(); it++)
    {
        std::cout << "Allow Methods -> " << *it << std::endl;
    }
    for (std::vector<std::string>::iterator it = _index.begin(); it < _index.end(); it++)
    {
        std::cout << "Index Page -> " << *it << std::endl;
    }
    for(std::map<int, std::string>::const_iterator it = _listen.begin(); it != _listen.end(); it++)
    {
        std::cout<< "Listen -> " << it->first << " " << it->second << std::endl;
    }
    for(std::map<int, std::string>::const_iterator it = _errorPages.begin(); it != _errorPages.end(); it++)
    {
        std::cout<< "Error Page -> " << it->first << " " << it->second << std::endl;
    }
    for (std::vector<location>::iterator it = _location.begin(); it < _location.end(); it++)
    {
        std::cout<< "--------------------------------\n";
        it->printLocation();

    }
}