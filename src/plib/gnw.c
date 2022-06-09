#include "plib/gnw.h"

int GNWSystemError(char *msg) {
  printf("[ERROR] %s\n", msg);
  return 0;
}