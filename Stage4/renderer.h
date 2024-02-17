#include "model.h"
#include "raster.h"
#include "arrays.h"




void renderTree(const Tree *tree, UINT32 *base);

void renderLives(const Lives *lives, UINT32 *base32);

void renderskier(const NPCskier *skier, UINT32 *base32);

void renderFakePlayer(UINT32 *base32, const UINT32 *bitmap); /*object for 5 second invincibility*/

void renderPlayer(Snowboarder *player, UINT32 *base32, const UINT32 *bitmap, unsigned int height);


/*

void render(const Model *model, UINT32 *base32) counter is 16pixels

void renderSkierHitCount();

void renderGameOver();

*/