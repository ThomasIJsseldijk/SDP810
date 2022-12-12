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
 */
SDP810::SDP810()
{

    SDP810_wire = new sensorHub_Wire();
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
 * @param channel 
 */
void SDP810::begin(port channel)
{

    SDP810_wire->begin(channel);

    byte setting[2] = {0x36, 0x15};

    SDP810_wire->send(SDP_addr, setting);
}
void SDP810::read()
{

    SDP810_wire->read(SDP_addr, buffer, 9);

    
    conversionFactor = buffer[6] << 8 | buffer[7];
    sensorRaw = (buffer[0] << 8 | buffer[1]);
    sensorRaw = sensorRaw / conversionFactor; 
}
int16_t SDP810::getRaw()
{
    return sensorRaw;
}
int16_t SDP810::getVolume()
{


return 0;
}
