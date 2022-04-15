// Copyright (c) John Allen Whitley, 2022, BSD 3-Clause

#ifndef MESSAGING_H
#define MESSAGING_H

typedef struct message {
  char *str;
  struct message *previous;
  struct message *next;
} message;

typedef struct msgwrap {
  int size;
  message *front;
  message *back;
} msgwrap;

int messaging_Init();
void messaging_Deinit();
int pushmessage(const char *str);
int drawnewmessages();

#endif /* MESSAGING_H */
