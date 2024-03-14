#include"PresenceTester.h"


PresenceTester::PresenceTester() {}
PresenceTester::~PresenceTester() {}

/**
 * @brief 
 * 
 * @param vehicule 
 * @return true 
 * @return false 
 */
bool PresenceTester::checkPresence(const std::string& vehicule) 
{
   // Code pour vérifier la présence d'un dispositif spécifique
   return true; // Ou false selon la présence
}


void PresenceTester::scanForVehicules()
{
   // Code pour rechercher et détecter les dispositifs connectés
}


std::vector<std::string> PresenceTester::getConnectedVehicule() 
{
   // Code pour obtenir la liste des dispositifs connectés
   return connectedVehicule;
}


void PresenceTester::testVehicule(const std::string& device) 
{
   // Code pour effectuer des tests spécifiques sur un dispositif
}

