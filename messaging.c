// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#include <stdlib.h>
#include <SDL2/SDL.h>

#include "clkfont.h"

#include "messaging.h"

msgwrap _message_queue;

message *message_Create(char *str) {
  message *output = malloc(sizeof(message));
  output->str = str;
  output->previous = NULL;
  output->next = NULL;
  return output;
}

void message_Destroy(message *msg) {
  free(msg->str);
  if (msg->previous)
    msg->previous->next = msg->next;
  if (msg->next)
    msg->next->previous = msg->previous;
}

void message_ChainDestroy(message *msg) {
  free(msg->str); //TODO: Fix string literal free() problem here.
  if (msg->next)
    message_ChainDestroy(msg->next);
  free(msg);
}

int backdrawmessages(const message *bck) {
  const CLK_Font *font = CLK_GetFont();
  const SDL_Rect *rect = CLK_GetRect();
  message *msg = bck;
  int err;
  
  int maxlines = rect->h / font->charh;

  for (int i = 0; i < maxlines; i++)
    if (msg) {
      if (err = CLK_DrawGridStr(msg->str,
			  NULL, 0, maxlines - i - 1, 0))
	return err;
      msg = msg->previous;
    } else break;
  return 0;
}

int messaging_Init() {
  _message_queue.size = 1;
  _message_queue.front = message_Create("Messaging initialized.");
  _message_queue.back = _message_queue.front;
  return 0;
}

void messaging_Deinit() {
  message_ChainDestroy(_message_queue.front);
  _message_queue.size = 0;
  _message_queue.front = NULL;
  _message_queue.back = NULL;
}

int pushmessage(char *str) {
  message *msg = message_Create(str);
  _message_queue.back->next = msg;
  msg->previous = _message_queue.back;
  _message_queue.back = msg;
  return ++_message_queue.size;
}

int drawnewmessages() {
  return backdrawmessages(_message_queue.back);
}
