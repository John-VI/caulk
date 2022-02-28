#ifndef GNU_H
#define GNU_H

ssize_t getdelim (char **lineptr, size_t *n, int delimiter, FILE *stream);

#define getline(lineptr, n, stream) getdelim(lineptr, n, '\n', stream)

#endif
