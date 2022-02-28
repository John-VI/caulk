#include <stdio.h>
#include <stdlib.h>

#define INITBUFFSIZE 256

ssize_t getdelim (char **lineptr, size_t *n, int delimiter, FILE *stream) {
  if (stream == NULL)
    return -1;
  /* if (*n < 0 || n == NULL) */
  /*   return -1; */
  if (lineptr == NULL)
    return -1;
  
  if (*n == 0) {
    *lineptr = malloc(INITBUFFSIZE * sizeof(char));
    if (!*lineptr)
      return -1;
    else
      *n = INITBUFFSIZE;
  }

  char c;
  ssize_t i = 0;

  if ((c = fgetc(stream)) == EOF)
    return -1;

  do {
    if (i == INITBUFFSIZE - 2)
      *lineptr = realloc(*lineptr, *n = (*n + INITBUFFSIZE) * sizeof(char));
    (*lineptr)[i] = c;
    i++;
  } while ((c = fgetc(stream)) != delimiter && c != EOF);
  
  (*lineptr)[i] = delimiter;
  (*lineptr)[++i] = '\0';
  return i;
}
