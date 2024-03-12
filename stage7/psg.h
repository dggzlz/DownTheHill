#ifndef PSG_H
#define PSG_H
#include "types.h"

void writePsg(int reg, UINT8 val);
void setTone(int channel, int tuning);
void setVolume(int channel, int volume);
void enableChannel(int channel, int toneOn, int noiseOn);
void stopSound();
void set_noise(int tuning);
void setEnvelope(int shape, unsigned int sustain)

#endif