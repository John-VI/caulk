// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#include "media.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_gamecontroller.h>
#include <SDL2/SDL_ttf.h>

struct pad {
  bool buttons[SDL_CONTROLLER_BUTTON_MAX];
  int axis[SDL_CONTROLLER_AXIS_MAX];
};

SDL_Surface *loadmedia(const char filename[]) {
  SDL_Surface *img = NULL;
  if ((img = IMG_Load(filename)) == NULL)
    logger->warn("Failed to load media {}: {}", filename, SDL_GetError());
  return img;
}

SDL_Texture *loadtex(SDL_Renderer *ren, const char filename[]) {
  SDL_Texture *tex = NULL;
  SDL_Surface *surf = loadmedia(filename);
  tex = SDL_CreateTextureFromSurface(ren, surf);
  if (tex == NULL) 
    logger->warn("Couldn't load texture: {}", SDL_GetError());

  SDL_FreeSurface(surf);
  return tex;
}

SDL_Texture *texttexture(SDL_Renderer *ren,  TTF_Font *font,
			 const char *str,  SDL_Color color) {
  SDL_Surface *surf = TTF_RenderText_Solid(font, str, color);
  return SDL_CreateTextureFromSurface(ren, surf);
}

