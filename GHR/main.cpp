#include "GHR.h"
#include <climits>
int main() {
  GHR<128> a, b;
  a.set();
  std::cout << a << std::endl;
  a = a << 1;
  std::cout << a << std::endl;
}
