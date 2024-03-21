#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "Poco/JSON/Object.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <Poco/Logger.h>


class Parser
{
private:
/**
 * @brief 
 * 
 */
    std::string rawData;
    Poco::JSON::Object::Ptr jsonObj;    // Declare jsonObj as a private member

public:
/**
 * @brief Construct a new Parser object
 * 
 */
    Parser();
    ~Parser();
    void displayRequest(const Poco::JSON::Object::Ptr &requestData);
    void readJsonFile(const std::string &filename);
    void setRawData(const std::string& data);
    void parserJsonData();
    void extractInformation();
    //bool validateData();
    Poco::JSON::Object::Ptr getJsonData() const;
};

#endif // PARSER_Hm

// Parser.h

