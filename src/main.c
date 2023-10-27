#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum CoinType {
  RAPPEN_5 = 5,
  RAPPEN_10 = 10,
  RAPPEN_20 = 20,
  RAPPEN_50 = 50,
  FRANKEN_1 = 100,
  FRANKEN_2 = 200,
  FRANKEN_5 = 500,
} CoinType;

const char *coin_type_to_str(CoinType coin) {
  switch (coin) {
  case RAPPEN_5:
    return "5 Rp.";
  case RAPPEN_10:
    return "10 Rp.";
  case RAPPEN_20:
    return "20 Rp.";
  case RAPPEN_50:
    return "50 Rp.";
  case FRANKEN_1:
    return "1 Fr.";
  case FRANKEN_2:
    return "2 Fr.";
  case FRANKEN_5:
    return "5 Fr.";
  }
}

typedef struct {
  int divisor;
  int remainder;
} DivisionResult;

DivisionResult division(uint32_t a, uint32_t b) {
  return (DivisionResult){
      .divisor = a / b,
      .remainder = a % b,
  };
}

void find_change(uint32_t change) {
  CoinType coins[] = {
      FRANKEN_5, FRANKEN_2, FRANKEN_1, RAPPEN_50,
      RAPPEN_20, RAPPEN_10, RAPPEN_5,
  };
  const int coins_count = sizeof(coins) / sizeof(coins[0]);
  for (int i = 0; i < coins_count; i++) {
    DivisionResult res = division(change, coins[i]);
    if (0 < res.divisor) {
      printf("%s:\t%d\n", coin_type_to_str(coins[i]), res.divisor);
      change -= coins[i] * res.divisor;
    }
    if (res.remainder == 0) {
      return;
    }
  }
  printf("Remains: %d Rp.\n", change);
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
  find_change(change);
}
