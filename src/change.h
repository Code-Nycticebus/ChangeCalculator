#ifndef __CHANGE_H__
#define __CHANGE_H__

#include <stdint.h>

typedef enum CoinType {
  RAPPEN_1 = 1,
  RAPPEN_5 = 5,
  RAPPEN_10 = 10,
  RAPPEN_20 = 20,
  RAPPEN_50 = 50,
  FRANKEN_1 = 100,
  FRANKEN_2 = 200,
  FRANKEN_5 = 500,
  FRANKEN_10 = 1000,
  FRANKEN_20 = 2000,
  FRANKEN_50 = 5000,
  FRANKEN_100 = 10000,
} CoinType;

const char *coin_type_to_str(CoinType coin);

void find_change(uint32_t change,
                 void (*output_fn)(uint32_t amount, CoinType coin));

#endif
