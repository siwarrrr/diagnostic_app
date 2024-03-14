#ifndef PRESENCE_TESTER_H
#define PRESENCE_TESTER_H

#include <vector>
#include <string>

class PresenceTester {
private:
/**
 * @brief 
 * 
 */
    std::vector<std::string> connectedVehicule;

public:
/**
 * @brief Construct a new Presence Tester object
 * 
 */
    PresenceTester();
    ~PresenceTester();

    bool checkPresence(const std::string& vehicule);
    void scanForVehicules();
    std::vector<std::string> getConnectedVehicule();
    void testVehicule(const std::string& vehicule);
};

#endif // PRESENCE_TESTER_H