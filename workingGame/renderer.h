#ifndef RENDERER_H
#define RENDERER_H
#include "model.h"
#include "types.h"


void renderPlayer(Snowboarder *player, UINT32 *base);
void renderFakePlayer(UINT32 *base); /*object for 5 second invincibility*/
void renderSkier(NPCskier *skier, UINT32 *base);
void renderTree(Tree *tree, UINT32 *base);
void renderScore(ScoreCounter *score, UINT32 *base);
void renderLives(Lives *lives, UINT32 *base);
void renderModel(const Model *model, UINT32 *base); 



/*
void renderSkierHitCount();
void renderGameOver();
*/

#endif