#ifndef TRANSCEIVER_H
#define TRANSCEIVER_H

#include <string>

class UdsTransceiver 
{

private:
/**
 * @brief 
 * 
 */
   bool connectionStatus;
   int bufferSize;
   double transmissionRate;


public:
/**
 * @brief Construct a new Uds Transceiver object
 * 
 */
    UdsTransceiver();
    ~UdsTransceiver();

    void connect();
    void disconnect();
    void udsTransmitData(const std::string& data);
    std::string udsReceiveData();
    void flushBuffer();
};

#endif // TRANSCEIVER_H