#include "args.h"
#include "blob.h"

#define HDAYS 22

int main(int argc, char **argv) {
  if (argc == 2) {
    if (strcmp("-h", argv[1]) == 0 || strcmp("--help", argv[1]) == 0)
      help();
  } else if (argc == 11) {
    char *TABLE = NULL;
    int YEAR = 1;
    int MONTH = 1;
    int DAY = 1;
    int BLOBS = 1;
    blob_t *blob = NULL;

    parser(argc, argv, &TABLE, &YEAR, &MONTH, &DAY, &BLOBS);

    const date_t EASTER = easter(YEAR);

    date_t holidays[HDAYS] = {{YEAR, 1, 1},
                              time_travel(EASTER, -48),
                              time_travel(EASTER, -47),
                              time_travel(EASTER, -46),
                              time_travel(EASTER, -3),
                              time_travel(EASTER, 60),
                              {YEAR, 4, 21},
                              {YEAR, 8, 6},
                              {YEAR, 9, 7},
                              {YEAR, 10, 12},
                              {YEAR, 10, 15},
                              {YEAR, 10, 28},
                              {YEAR, 11, 2},
                              {YEAR, 11, 15},
                              {YEAR, 12, 15},
                              {YEAR, 12, 25},
                              {YEAR, 12, 27},
                              {YEAR, 12, 28},
                              {YEAR, 12, 29},
                              {YEAR, 12, 30},
                              {YEAR, 12, 31}};

    bubble_sort(HDAYS, holidays);

    date_t date = {YEAR, MONTH, DAY};

    printf("\n\twday code list:");
    printf("\n\tsun: 0, tue: 1, wed: 3, thu: 4, fri: 5, sat: 6\n");

    blober(BLOBS, &blob, date);

    cron(strlen(TABLE), TABLE, BLOBS, blob, HDAYS, holidays, date);

    free(TABLE);
    free(blob);

    printf("\n\tcron.md file generated.\n\n");
  }
  return 0;
}
