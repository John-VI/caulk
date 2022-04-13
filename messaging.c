
typedef struct message {
  const char *str;
  struct message *previous;
  struct message *next;
} message;

typedef struct msgwrap {
  int size;
  message *front;
  message *back;
} msgwrap;

msgwrap _message_queue;

message *message_Create(const char *str) {
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
  free(msg->str);
  if (msg->next)
    message_ChainDestroy(msg->next);
  free(msg);
}

int backdrawmessages(message *bck) {
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

