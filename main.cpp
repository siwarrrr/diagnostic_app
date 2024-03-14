#include "Parser.h"
#include "JsonSequencer.h"
#include "UdsCodec.h"
#include "UdsTransceiver.h"
#include "PresenceTester.h"
#include "ErrorHandlerRasp.h"

int main() {
//Création des objets des différentes classes
    Parser parser;
    JsonSequencer jsonSequencer;
    UdsCodec udsCodec;
    UdsTransceiver udsTransceiver;
    PresenceTester presenceTester;
    ErrorHandlerRasp errorHandlerRasp;

//Utilisation des méthodes des différentes classe
    parser.readJsonFile("output.json");
    parser.setRawData("Données brutes à analyser");
    parser.parserJsonData();
    parser.extractInformation();

    jsonSequencer.addCommand("Commande 1");
    jsonSequencer.addCommand("Commande 2");
    jsonSequencer.executeSequence();

//udsCodec.setEncodingParameters(/* paramètres */);
    std::string encodedData = udsCodec.udsEncode("Données à encoder");
    std::string decodedData = udsCodec.udsDecode(encodedData);

    udsTransceiver.connect();
    udsTransceiver.udsTransmitData("Données à envoyer");
    std::string receivedData = udsTransceiver.udsReceiveData();
    udsTransceiver.disconnect();

    presenceTester.scanForVehicules();
    std::vector<std::string> connectedVehicule = presenceTester.getConnectedVehicule();

    errorHandlerRasp.handleError("Erreur générale");
    errorHandlerRasp.handleSpecificError("Fonction X", "Erreur spécifique");

    return 0;
};
