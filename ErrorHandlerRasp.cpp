#include"ErrorHandlerRasp.h"

ErrorHandlerRasp::ErrorHandlerRasp() {}
ErrorHandlerRasp::~ErrorHandlerRasp() {}



// Méthode pour gérer les erreurs générales
void ErrorHandlerRasp::handleError(const std::string& errorMessage) 
{
    std::cerr << "Error: " << errorMessage << std::endl;
    // Code supplémentaire pour la gestion de l'erreur, par exemple : logging, notification, etc.
}


// Méthode pour gérer les erreurs spécifiques à une classe ou à une fonction
void ErrorHandlerRasp::handleSpecificError(const std::string& errorLocation, const std::string& errorMessage) 
{
    std::cerr << "Error in " << errorLocation << ":"<< errorMessage << std::endl;
    // Code supplémentaire pour la gestion de l'erreur spécifique
}
       
