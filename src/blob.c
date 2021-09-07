#include "blob.h"

static int
nclss(const int b, const blob_t *const B, const date_t d)
{
  int i;
  for (i = 0; (B + i)->wday != weekday(d) && i < b; i++)
    ;
  return (B + i)->qty;
}

static int
delta(const int b, const blob_t *const B, const date_t d)
{
  int delta = 0;
  int i;
  for (i = 0; (B + i)->wday != weekday(d) && i < b; i++)
    ;
  if (i < b - 1)
    delta = (B + i + 1)->wday - (B + i)->wday;
  else
    delta = B->wday - (B + i)->wday + 7;
  return delta;
}

void
cron(const int s, const char *const S, const int b, const blob_t *const B,
     const int h, const date_t *const H, date_t d)
{
  PGconn *conn = PQconnectdb("dbname=teaching");

  if (PQstatus(conn) == CONNECTION_BAD) {
    PQfinish(conn);
    exit(EXIT_FAILURE);
  }

  if (S == NULL)
    exit(EXIT_FAILURE);

  char *query = malloc((14 + s) * sizeof(char));
  strcpy(query, "SELECT * FROM ");
  strcat(query, S);

  PGresult *R = PQexec(conn, query);

  free(query);

  if (PQresultStatus(R) != PGRES_TUPLES_OK) {
    PQclear(R);
    PQfinish(conn);
    exit(EXIT_FAILURE);
  }

  FILE *cronf = fopen("cron.md", "w");

  if (cronf == NULL) {
    exit(EXIT_FAILURE);
  }

  int i = 0;
  int j = 0;
  int k;

  while (i < PQntuples(R)) {
    if (!found_in(h, H, d)) {
      fprintf(cronf, "- %d/%d/%d:\n", d.day, d.month, d.year);
      k = nclss(b, B, d);
      while (k > 0 && i < PQntuples(R))
        if (j > 0) {
          if (j <= k) {
            fprintf(cronf, "\t- %s: %d\n", PQgetvalue(R, i++, 1), j);
            k -= j;
            j = 0;
          } else {
            fprintf(cronf, "\t- %s: %d\n", PQgetvalue(R, i, 1), k);
            j -= k;
            k = 0;
          }
        } else {
          if (atoi(PQgetvalue(R, i, 2)) <= k) {
            fprintf(cronf, "\t- %s: %s\n", PQgetvalue(R, i, 1),
                    PQgetvalue(R, i, 2));
            k -= atoi(PQgetvalue(R, i++, 2));
          } else {
            fprintf(cronf, "\t- %s: %d\n", PQgetvalue(R, i, 1), k);
            j = atoi(PQgetvalue(R, i, 2)) - k;
            k = 0;
          }
        }
    }
    d = time_travel(d, delta(b, B, d));
  }

  PQclear(R);
  PQfinish(conn);
  fclose(cronf);
}

void
blober(const int b, blob_t **B, const date_t d)
{
  int i, j;
  blob_t b_tmp;
  *B = malloc(b * sizeof(blob_t));
  for (i = 0; i < b; i++) {
    if (i == 0) {
      (*B + i)->wday = weekday(d);
      printf("\n\t0. wday = %d", (*B + i)->wday);
      printf("\n\t    qty = ");
      scanf("%d", &(*B + i)->qty);
    } else {
      printf("\n\t%d. wday = ", i);
      scanf("%d", &(*B + i)->wday);
      printf("\t    qty = ");
      scanf("%d", &(*B + i)->qty);
    }
  }
  /* bubble sort B */
  for (i = 0; i < b - 1; i++)
    for (j = 0; j < b - 1; j++)
      if ((*B + j)->wday > (*B + j + 1)->wday) {
        b_tmp = *(*B + j);
        *(*B + j) = *(*B + j + 1);
        *(*B + j + 1) = b_tmp;
      }
}
