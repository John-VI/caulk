// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#ifndef CLK_WINDOW_H
#define CLK_WINDOW_H

SDL_Window *CLK_NewWindow(const char name[], int width, int height);
SDL_Renderer *CLK_NewRenderer(SDL_Window *win, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
SDL_Renderer *CLK_SetRenderer(SDL_Renderer *newren);
SDL_Window *CLK_SetWindow(SDL_Window *newwin);

#endif /* CAULK_WINDOW_H */
