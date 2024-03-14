#include"JsonSequencer.h"


JsonSequencer::JsonSequencer() {}
JsonSequencer::~JsonSequencer() {}


void JsonSequencer::addCommand(const std::string & command)
{
    commandSequence.push_back(command);
}


void JsonSequencer::removeCommand(const std::string & command) 
{
    // Code pour supprimer une commande de la séquence
}


void JsonSequencer::executeSequence() 
{
    // Code pour exécuter la séquence de commandes
}


void JsonSequencer::clearSequence() 
{
    commandSequence.clear();
}

