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
  FRANKEN_200 = 20000,
  FRANKEN_1000 = 100000,
} CoinType;

typedef void (*coin_output_fn)(uint32_t amount, CoinType coin);

const char *coin_type_to_str(CoinType coin);

void change_find(uint32_t change, coin_output_fn output_fn);

#endif
