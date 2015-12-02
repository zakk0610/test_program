#include "GHR.h"
#include <climits>
int main() {
  GHR<32> a, b;
  a.set();
  a = a << 1;
  std::cout << a << std::endl;
  std::cout << a.caculateGHR(6,0) << std::endl;
  std::cout << a.caculateGHR(24,6) << std::endl;
}
