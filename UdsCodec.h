#ifndef UDSCODEC_H
#define UDSCODEC_H

#include <string>

class UdsCodec 
{
private:
/**
 * @brief 
 * 
 */
   std::string encodedDataSize;
   std::string decodedDataSize;

public:
/**
 * @brief Construct a new Uds Codec object
 * 
 */
    UdsCodec();
    ~UdsCodec();


    std::string udsEncode(const std::string& data);
    std::string udsDecode(const std::string& encodedData);
    void resetUdsCodec();
};

#endif // UDSCODEC_H