#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>


template<unsigned value_size>
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

  GHR<value_size> operator|(unsigned rhs) {
    GHR<value_size> temp = *this;
    temp.digit |= rhs;
    return temp;
  }

  GHR<value_size> operator<<(const unsigned rhs) {
    GHR<value_size> temp = *this;
    temp.digit = temp.digit << rhs;
    return temp;
  }

  // GHR25_fold5 = GHR[4:0] ^ GHR [9:5] ^ GHR [14:10] ^ GHR [19:15] ^ GHR[24:20]
  // GHR72_fold6 =
  // GHR147_fold7 =
  // getIndex(25,5)
  GHR<value_size> getIndex(unsigned bitNumber, unsigned fold) {
    std::bitset<value_size> tmp = (digit << (value_size - bitNumber)) >> bitNumber;


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
