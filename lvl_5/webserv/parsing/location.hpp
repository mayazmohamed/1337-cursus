/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:04:46 by momayaz           #+#    #+#             */
/*   Updated: 2022/09/21 17:46:38 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <fstream>
#include <iterator>

class location
{
public:
    std::vector<std::string> _allowMethod;
    std::string _root;
    std::vector<std::string> _index;
    std::map<std::string, std::string> _cgiInfo;
    std::string _path;
    std::map<int, std::string> _errorPages;
    std::string _uploadPath;
    bool _autoIndex;
    int _status;
    std::string _url;

public:
    location(/* args */);
    location(const location &F);
    location &operator = (const location &F);
    ~location();
    void printLocation();
};




#endif