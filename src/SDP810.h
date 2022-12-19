#ifndef SDP810_H
#define SDP810_H

#include <robotPatient_Wire.h>


#define SDP_addr 0x25



class SDP810
{
private:
    /* data */

double flow;
int16_t sensorRaw;
int16_t conversionFactor;



byte buffer[9];


public:

    SDP810();
    ~SDP810();
    void begin(robotPatient_Wire *SDP810wire);
    void read();
    int16_t getRaw();
    float getVolume();
    robotPatient_Wire *SDP810_wire;

};

#endif // SDP810




