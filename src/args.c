#include "args.h"

void
help(void)
{
  printf("Usage:\n\n\
\tblob (-t|--table) T (-y|--year) Y (-m|--month) M (-d|--day) D (-b|--blobs) B\
\n\nwhere\n\n\
\tT\ttable name\n\
\tY\tyear\n\
\tM\tmonth\n\
\tD\tday\n\
\tB\tnumber of blobs\n\n\
For more information, please take a look the README. There's also an online\n\
version of this at my github page:\n\n\
\thttps://github.com/marcelobarboza/blob\n\n");
}

void
parser(int a, char **A, char **T, int *Y, int *M, int *D, int *B)
{
  for (int i = 1; i <= 9; i += 2)
    if (strcmp("-t", A[i]) == 0 || strcmp("--table", A[i]) == 0) {
      *T = malloc(strlen(A[i + 1]) * sizeof(char));
      strcpy(*T, A[i + 1]);
    } else if (strcmp("-y", A[i]) == 0 || strcmp("--year", A[i]) == 0)
      *Y = atoi(A[i + 1]);
    else if (strcmp("-m", A[i]) == 0 || strcmp("--month", A[i]) == 0)
      *M = atoi(A[i + 1]);
    else if (strcmp("-d", A[i]) == 0 || strcmp("--day", A[i]) == 0)
      *D = atoi(A[i + 1]);
    else if (strcmp("-b", A[i]) == 0 || strcmp("--blobs", A[i]) == 0)
      *B = atoi(A[i + 1]);
    else {
      printf("Unrecognized option. Type\n\n\t./blob.o -h\n\nfor help.\n");
      exit(1);
    }
}
