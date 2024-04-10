#ifndef PSG_H
#define PSG_H
#include "types.h"

#define channelA 0
#define channelB 1
#define channelC 2

void writePsg(int reg, UINT8 val);
void setTone(int channel, int tuning);
void setVolume(int channel, int volume);
void enableChannel(int channel, int toneOn, int noiseOn);
void stopSound();
void setNoise(int tuning);
void setEnvelope(int shape, unsigned int sustain);

#endif