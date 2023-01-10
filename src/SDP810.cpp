/**
 * @file SDP810.cpp
 * @author Thomas IJsseldijk (fhm.ijsseldijk@student.han.nl)
 * @brief 
 * @version 0.1
 * @date 07-10-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "SDP810.h"



/**
 * @brief Construct a new SDP810::SDP810 object
 * 
 * @param sensorAddress 
 */
SDP810::SDP810(char sensorAddress)
{
    SDP810address = sensorAddress;
}


/**
 * @brief Destroy the SDP810::SDP810 object
 * 
 */
SDP810::~SDP810()
{
}


/**
 * @brief 
 * 
 * @param wire 
 */
void SDP810::begin(TwoWire *wire)
{
    byte setting[2] = {0x36, 0x15};
    SDP810wire = wire;

    SDP810wire->beginTransmission(SDP810address);
    SDP810wire->write(setting, sizeof(setting));
    SDP810wire->endTransmission(true);
}



/**
 * @brief 
 * 
 */
void SDP810::read()
{

    SDP810wire->requestFrom(SDP810address, sizeof(buffer), true);
    SDP810wire->readBytes(buffer, sizeof(buffer));

    conversionFactor = buffer[6] << 8 | buffer[7];
    sensorRaw = (buffer[0] << 8 | buffer[1]);
    sensorRaw = sensorRaw / conversionFactor; 
}

/**
 * @brief 
 * 
 * @return int16_t 
 */
int16_t SDP810::getRaw()
{
    return sensorRaw;
}
float SDP810::getVolume()
{
return sqrt(sensorRaw*2);
}
