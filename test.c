#include <assert.h>
#include "lib/lib.h"

int main() {
  assert(f1(5) == 2);
  assert(f1(11) == 12);
  assert(f2() == 2);
}
