#include "Parser.h"
#include "Poco/JSON/Parser.h"
#include "Poco/JSON/Object.h"
#include "Poco/JSON/Array.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>

Parser::Parser() {}
Parser::~Parser() {}


Poco::JSON::Object::Ptr Parser::getJsonData() const {
    return jsonObj;
}

void displayRequest(const Poco::JSON::Object::Ptr &requestData, int depth = 0) {
    // Indentation based on depth
    std::string indentation(depth * 4, ' ');

    // Extract request name and id
    std::string requestName = requestData->optValue("name", "NoName");
    std::string requestId = requestData->optValue("id", "NoID");

    // Display request information
    std::cout << indentation << "Request Name: " << requestName << ", Request ID: " << requestId;

    // Display request parameters if available
    if (requestData->has("params")) {
        const std::string &requestParams = requestData->getValue<std::string>("params");
        std::cout << ", Request Params: " << requestParams;
    } else {
        std::cout << ", No Request Params";
    }
    std::cout << std::endl;

    // Display response conditions if available
    if (requestData->has("Response")) {
        const Poco::JSON::Object::Ptr &response = requestData->getObject("Response");
        for (const auto &responsePair : *response) {
            std::cout << indentation << "Response Condition: " << responsePair.first << ": " << responsePair.second.toString() << std::endl;
        }
    } else {
        std::cerr << "Request has no response" << std::endl;
    }

    // Display nested requests if available
    if (requestData->has("Request")) {
        const Poco::JSON::Object::Ptr &subRequest = requestData->getObject("Request");
        std::cout << std::endl << indentation << "Sub-Request: " << std::endl;
        displayRequest(subRequest, depth + 1); // Recursively display nested requests with increased depth
    }

    // Extraire les valeurs des clés "name" et "id"
    std::string requestName;
    if (requestData->has("name")) {
        requestName = requestData->get("name").toString();
    } else {
        requestName = "NoName";
    }

    std::string requestId;
    if (requestData->has("id")) {
        requestId = requestData->get("id").toString();
    } else {
        requestId = "NoID";
    }

    // Afficher les informations de la demande
    std::cout << "Request Name: " << requestName << ", Request ID: " << requestId;

    // Vérifier si la demande a des paramètres
    if (requestData->has("params")) {
        const std::string &requestParams = requestData->getValue<std::string>("params");
        std::cout << ", Request Params: " << requestParams;
    } else {
        std::cout << ", No Request Params";
    }
    std::cout << std::endl;

    // Vérifier si la demande a des réponses
    if (requestData->has("Response")) {
        const Poco::JSON::Object::Ptr &response = requestData->getObject("Response");
        // Parcourir chaque condition de la réponse
        for (const auto &responsePair : *response) {
            std::cout << "Response Condition: " << responsePair.first << ": " << responsePair.second.toString() << std::endl;
        }
    } else {
        std::cerr << "Request has no response" << std::endl;
    }

    // Vérifier si la demande a des sous-demandes
    if (requestData->has("Request")) {
        const Poco::JSON::Object::Ptr &subRequest = requestData->getObject("Request");
        std::cout << std::endl << "Sub-Request: " << std::endl;
        displayRequest(subRequest);
    }
}

void Parser::readJsonFile(const std::string &output) {
    std::cout << "Opening file: " << output << std::endl;

    // Ouvrir le fichier en lecture
    std::ifstream file(output);

    if (!file.is_open()) {
        // Si le fichier n'est pas ouvert, afficher une erreur et retourner
        std::cerr << "Error opening file: " << output << std::endl;
        return;
    }

    std::cout << "File opened successfully!" << std::endl;

    try {
        // Créer un analyseur JSON
        Poco::JSON::Parser jsonParser;

        // Analyser le contenu du fichier
        Poco::Dynamic::Var result = jsonParser.parse(file);

        // Extraire l'objet JSON à partir du résultat de l'analyse
        auto obj = result.extract<Poco::JSON::Object::Ptr>();

        // Parcourir chaque demande dans l'objet JSON
        for (const auto &requestPair : *obj) {
            const Poco::JSON::Object::Ptr &requestData = requestPair.second.extract<Poco::JSON::Object::Ptr>();
            std::cout << "-------------------------------------------------" << std::endl;
            displayRequest(requestData);
        }
    } catch (const Poco::Exception &ex) {
        // En cas d'erreur pendant l'analyse JSON, afficher l'erreur
        std::cerr << "Error parsing JSON: " << ex.displayText() << std::endl;

        // Lancer une exception avec l'erreur d'analyse JSON
        throw std::runtime_error("JSON parsing error: " + std::string(ex.displayText()));
    }

    // Fermer le fichier après avoir terminé la lecture
    file.close();
}

