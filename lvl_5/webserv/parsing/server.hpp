/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:04:52 by momayaz           #+#    #+#             */
/*   Updated: 2022/09/27 13:30:12 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <fstream>
#include "location.hpp"



class server
{
public:
    std::string _servName;
    std::string _root;
    std::vector<std::string> _allowMethod;
    bool _autoIndex;
    std::vector<std::string> _index;
    int _clientBodyLimit;
    struct timeval _recvTimeout;
    struct timeval _sendTimeout;
    std::map<int, std::string> _errorPages;
    std::map<int, std::string> _listen;
    std::vector<location> _location;
    int _status;
    std::string _url;
    std::string _uploadPath;

public:
    server();
    ~server();
    server(const server &F);
    server &operator=(const server &F);
    void printServer();
};


#endif