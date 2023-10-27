#include "change.h"

typedef struct {
  uint32_t divisor;
  uint32_t remainder;
} DivisionResult;

static DivisionResult division(uint32_t a, uint32_t b) {
  return (DivisionResult){
      .divisor = a / b,
      .remainder = a % b,
  };
}

const char *coin_type_to_str(CoinType coin) {
  switch (coin) {
  case RAPPEN_1:
    return "  1 Rp.";
  case RAPPEN_5:
    return "  5 Rp.";
  case RAPPEN_10:
    return " 10 Rp.";
  case RAPPEN_20:
    return " 20 Rp.";
  case RAPPEN_50:
    return " 50 Rp.";
  case FRANKEN_1:
    return "  1 Fr.";
  case FRANKEN_2:
    return "  2 Fr.";
  case FRANKEN_5:
    return "  5 Fr.";
  case FRANKEN_10:
    return " 10 Fr.";
  case FRANKEN_20:
    return " 20 Fr.";
  case FRANKEN_50:
    return " 50 Fr.";
  case FRANKEN_100:
    return "100 Fr.";
  }
}

void change_find(uint32_t change,
                 void (*output_fn)(uint32_t amount, CoinType coin)) {
  CoinType coins[] = {
      FRANKEN_100, FRANKEN_50, FRANKEN_20, FRANKEN_10, FRANKEN_5, FRANKEN_2,
      FRANKEN_1,   RAPPEN_50,  RAPPEN_20,  RAPPEN_10,  RAPPEN_5,
  };
  const int coins_count = sizeof(coins) / sizeof(coins[0]);
  for (int i = 0; i < coins_count; i++) {
    DivisionResult res = division(change, coins[i]);
    if (0 < res.divisor) {
      output_fn(res.divisor, coins[i]);
      change -= coins[i] * res.divisor;
    }
    if (res.remainder == 0) {
      return;
    }
  }
  output_fn(change, RAPPEN_1);
}
