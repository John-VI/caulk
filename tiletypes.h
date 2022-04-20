// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#ifndef TILETYPES_H
#define TILETYPES_H

enum tile_typecode { TILE_FLOOR, TILE_WALL, TILE_TELEPORT };
enum tile_flags { TILE_PASSABLE = 0b1 };

typedef struct tile_info {
  const unsigned int type;
  char flags;
  char c;
} tile_info;

typedef struct tile_floor {
  const unsigned int type;
  char flags;
  char c;
} tile_floor;

typedef struct tile_wall {
  const unsigned int type;
  char flags;
  char c;
  int maxhp;
  int hp;
} tile_wall;

typedef struct tile_teleport {
  const unsigned int type;
  char flags;
  char c;
  int x;
  int y;
} tile_teleport;

typedef union tile_type {
  const unsigned int type;
  tile_info info;
  tile_floor floor;
  tile_wall wall;
  tile_teleport teleport;
} tile_type;

#endif /* TILETYPES_H */
