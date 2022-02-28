#ifndef CAULK_WINDOW_H
#define CAULK_WINDOW_H

SDL_Window *CLK_NewWindow(const char name[], int width, int height);
SDL_Renderer *CLK_NewRenderer(SDL_Window *win, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

#endif /* CAULK_WINDOW_H */
