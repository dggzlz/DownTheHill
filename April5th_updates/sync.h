#ifndef SYNC_H
#define SYNC_H

#include "types.h"
#include "model.h"
#include "events.h"

void syncTree(Model *model);
void syncSkier(Model *model, UINT32 timeNow);
void syncEdge(Model *model);

#endif