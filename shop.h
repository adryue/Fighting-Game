#ifndef __SHOP_H__
#define __SHOP_H__

#include "hero.h"

void shop(hero_t &hero);
void handlePurchase(hero_t &hero, string type, int cost);
void listStats(hero_t &hero);

#endif