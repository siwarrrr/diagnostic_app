#ifndef JSON_SEQUENCER_H
#define JSON_SEQUENCER_H

#include <vector>
#include <string>

class JsonSequencer 
{
private:
/**
 * @brief 
 * 
 */
    std::vector<std::string> commandSequence;

public:
/**
 * @brief Construct a new Json Sequencer object
 * 
 */
    JsonSequencer();
    ~JsonSequencer();

    void addCommand(const std::string& command);
    void removeCommand(const std::string& command);
    void executeSequence();
    void clearSequence();
};

#endif // SEQUENCER_H