/**
 * @file lib.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01
 * 
 * @copyright Copyright © 2022 Christian Sargusingh
 * 
 */

#include "lib.h"

int f1(int a) {
  if (a > 10) {
    return a + 1;
  } else {
    return 2;
  }
}

int f2() {
  int a = 1;
  return ++a;
}
