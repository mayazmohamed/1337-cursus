/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:04:50 by momayaz           #+#    #+#             */
/*   Updated: 2022/09/21 17:46:50 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "location.hpp"

location::location(){
    _root = "";
    _path = "";
    _uploadPath = "";
    _autoIndex = true;
    _status = 0;
    _url = "";
}

location::~location(){
}

location::location(const location &F){
    *this = F;
}

location & location::operator=(const location &F){
    if (this != &F){
        _allowMethod = F._allowMethod;
        _root = F._root;
        _index = F._index;
        _cgiInfo = F._cgiInfo;
        _path = F._path;
        _errorPages = F._errorPages;
        _uploadPath = F._uploadPath;
        _autoIndex = F._autoIndex;
        _status = F._status;
        _url = F._url;
    }
    return *this;
    
}

void location::printLocation(){
    std::cout << "Root -> " << _root << std::endl;
    std::cout << "Path -> " << _path << std::endl;
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
    for(std::map<std::string, std::string>::const_iterator it = _cgiInfo.begin(); it != _cgiInfo.end(); ++it)
    {
        std::cout<< "_Cgi Info -> " << it->first << " " << it->second << std::endl;
    }
    for(std::map<int, std::string>::const_iterator it = _errorPages.begin(); it != _errorPages.end(); ++it)
    {
        std::cout<< "Error Page -> " << it->first << " " << it->second << std::endl;
    }
}