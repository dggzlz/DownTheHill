#ifndef RENDERER_H
#define RENDERER_H
#include "model.h"
#include "types.h"


void renderPlayer(Snowboarder *player, UINT32 *base32);
void renderFakePlayer(UINT32 *base32); /*object for 5 second invincibility*/
void renderskier(NPCskier *skier, UINT32 *base32);
void renderTree(Tree *tree, UINT32 *base);
void renderLives(Lives *lives, UINT32 *base32);





/*

void render(const Model *model, UINT32 *base32) counter is 16pixels

void renderSkierHitCount();

void renderGameOver();

*/

#endif