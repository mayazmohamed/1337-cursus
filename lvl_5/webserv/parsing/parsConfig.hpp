/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsConfig.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:04:57 by momayaz           #+#    #+#             */
/*   Updated: 2022/09/27 13:21:11 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSCONFIG_HPP
#define PARSCONFIG_HPP

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <sstream>
#include <ctime>
#include <dirent.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "location.hpp"
#include "server.hpp"



class parsConfig
{
    public:
        std::string _content;
        std::vector<server> *_serv;
        parsConfig();
        ~parsConfig();
        void checkBrak();
        std::vector<server> *parsFile();
        location parsLocat(std::size_t *p);
        int syntax(std::string value);
        int serverValue(server* serv, std::string key, std::string value);
        int locationValue(location* loc, std::string key, std::string value);
        server parsServ(size_t *p);
        
};



#endif