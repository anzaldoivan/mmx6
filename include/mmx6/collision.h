// prog SLUS_013.95 | system collision | range -
/* mmx6/collision.h -- the tile collision functions called outside collision/ (hand-edited; Phase 2.6 T10.c1). Each prototype carries the type its
 * callers declared (an unprototyped `T f();` stays as its callers wrote it). Not included by x4.h: callers include it. */
#ifndef MMX6_COLLISION_H
#define MMX6_COLLISION_H

#include "common.h"
#include "mmx6/x4.h"

s32 get_tile_attr_above(void*);
s32 get_tile_attr_below(void* arg0);
s32 get_tile_attr_bottom();
s32 get_tile_attr_origin();
s32 get_tile_attr_top(void* arg0);
s32 snap_to_tile_slope(void*, s32);

#endif /* MMX6_COLLISION_H */
