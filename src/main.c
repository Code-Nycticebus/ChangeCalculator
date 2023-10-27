#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "change.h"

static void print_output(uint32_t amount, CoinType coin) {
  printf("% 2d x %s\n", amount, coin_type_to_str(coin));
}

int main(int argc, const char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "%s <amount in Rp.>\n", argv[0]);
    return EXIT_FAILURE;
  }
  const int base = 10;
  char *check = NULL;
  int64_t change = strtol(argv[1], &check, base);
  if (*check != '\0' || change < 0 || UINT32_MAX < change) {
    fprintf(stderr, "Invalid input!\n");
    return EXIT_FAILURE;
  }
  change_find(change, print_output);
}
