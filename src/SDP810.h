#ifndef SDP810_H
#define SDP810_H

#include <sensorHub_Wire.h>


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
    void begin(port channel);
    void read();
    int16_t getRaw();
    int16_t getVolume();
    sensorHub_Wire *SDP810_wire;

};

#endif // SDP810




