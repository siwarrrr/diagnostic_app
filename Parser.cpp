#include "Parser.h"
#include "Poco/JSON/Parser.h"
#include "Poco/JSON/Object.h"
#include "Poco/JSON/Array.h"


Parser::Parser() {}
Parser::~Parser() {}

void Parser::readJsonFile(const std::string &output) {
    std::cout << "Opening file: " << output << std::endl;

    std::ifstream file(output);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << output << std::endl;
        return;
    }

    std::cout << "File opened successfully!" << std::endl;

    try {
        Poco::JSON::Parser jsonParser;
        Poco::Dynamic::Var result = jsonParser.parse(file);
        jsonObj = result.extract<Poco::JSON::Object::Ptr>();
    } catch (const Poco::Exception &ex) {
        std::cerr << "Error parsing JSON: " << ex.displayText() << std::endl;

        
        file.clear();
        file.seekg(0, std::ios::beg);
        std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        std::cerr << "File Content:\n" << fileContent << std::endl;

        throw std::runtime_error("JSON parsing error: " + std::string(ex.displayText()));
    }

    file.close();
}


void Parser::setRawData(const std::string &data) {
    rawData = data;
}

void Parser::parserJsonData() {
    try {
        Poco::JSON::Parser jsonParser;
        Poco::Dynamic::Var result = jsonParser.parse(rawData);
        jsonObj = result.extract<Poco::JSON::Object::Ptr>();
    } catch (const Poco::Exception &ex) {
        Poco::Logger::get("ParserLogger").error("JSON parsing error: " + std::string(ex.displayText()));
        throw std::runtime_error("JSON parsing error: " + std::string(ex.displayText()));
    }
}


void Parser::extractInformation() {
    if (!jsonObj) {
        std::cerr << "Les données JSON n'ont pas été analysées. Veuillez appeler parseJsonData() d'abord." << std::endl;
        return;
    }

    for (const auto &requestPair : *jsonObj) {
        const std::string &requestName = requestPair.first;
        const Poco::JSON::Object::Ptr &requestData = requestPair.second.extract<Poco::JSON::Object::Ptr>();

        std::string requestId = requestData->getValue<std::string>("id");
        std::string requestActualName = requestData->getValue<std::string>("name");

        std::cout << "Request Name: " << requestActualName << ", Request ID: " << requestId << std::endl;

        const Poco::JSON::Object::Ptr &params = requestData->getObject("params");

        for (const auto &paramPair : *params) {
            const std::string &paramName = paramPair.first;
            const std::string &paramValue = paramPair.second.convert<std::string>();

            std::cout << "Param Name: " << paramName << ", Param Value: " << paramValue << std::endl;
        }
    }
}




   