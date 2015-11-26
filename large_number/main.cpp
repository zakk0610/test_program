#include "large_number.h"
#include <climits>
int main() {
  LargeNumber a(ULLONG_MAX-1, 256);
  a = a << 32;
  std::cout << a << std::endl;
}
