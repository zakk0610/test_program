#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>


template<unsigned int value_size>
class GHR {
public:
  GHR(unsigned long long init = 0):digit(init) {}

  GHR(const GHR &other) : digit(other.digit){};

  GHR & operator=(GHR<value_size> other) {
    std::swap(digit, other.digit);
    return *this;
  }

  // move assignment operator

  const GHR operator&=(const GHR<value_size> &p2) {
    digit &= p2.digit;
    return *this;
  }

  GHR<value_size> operator|(const GHR<value_size> &rhs) {
    GHR<value_size> temp = *this;
    temp.digit &= rhs.digit;
    return temp;
  }

  GHR<value_size> operator|(unsigned int rhs) {
    GHR<value_size> temp = *this;
    temp.digit |= rhs;
    return temp;
  }

  GHR<value_size> operator<<(const unsigned int rhs) {
    GHR<value_size> temp = *this;
    temp.digit = temp.digit << rhs;
    return temp;
  }

  void set() {
    digit.set();
  }

  void reset() {
    digit.reset();
  }

  friend std::ostream &operator<<(std::ostream &os, const GHR<value_size> &obj){
    os << obj.digit.to_string();
    return os;
  }

private:
  std::bitset<value_size> digit;
};
