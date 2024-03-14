#ifndef ERROR_HANDLER_RASP_H
#define ERROR_HANDLER_RASP_H

#include <iostream>
#include <string>

class ErrorHandlerRasp 
{
public:
/**
 * @brief Construct a new Error Handler Rasp object
 * 
 */

    ErrorHandlerRasp();
    ~ErrorHandlerRasp();

    void handleError(const std::string& errorMessage);
    void handleSpecificError(const std::string& errorLocation, const std::string& errorMessage);

};

#endif // ERROR_HANDLER_H