// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

enum tile_typecode { TILE_FLOOR, TILE_WALL, TILE_TELEPORT };

typedef struct tile_info {
  const uint16_t type;
  char flags;
  char c;
} tile_info;

typedef struct tile_floor {
  const uint16_t type;
  char flags;
  char c;
} tile_floor;

typedef struct tile_wall {
  const uint16_t type;
  char flags;
  char c;
  int maxhp;
  int hp;
} tile_wall;

typedef struct tile_teleport {
  const uint16_t type;
  char flags;
  char c;
  int x;
  int y;
} tile_teleport;

typedef union tile_type {
  const uint16_t type;
  tile_info info;
  tile_floor floor;
  tile_wall wall;
  tile_teleport teleport;
} tile_type;

