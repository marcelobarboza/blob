#ifndef BLOB_H_INCLUDED
#define BLOB_H_INCLUDED

#include "date.h"
#include <libpq-fe.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  wday_t wday;
  int qty;
} blob_t;

static int nclss(const int, const blob_t *const, const date_t);
static int delta(const int, const blob_t *const, const date_t);
void cron(const int, const char *const, const int, const blob_t *const,
          const int, const date_t *const, date_t);
void blober(const int, blob_t **, const date_t);

#endif // BLOB_H_INCLUDED
