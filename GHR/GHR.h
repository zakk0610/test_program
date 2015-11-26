#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <assert.h>

template<unsigned value_size>
class GHR {
public:

  GHR(unsigned long init = 0):digit(init) {}

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
  GHR<value_size> caculateGHR(unsigned GHRBitNumber, unsigned fold);

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

template<unsigned value_size>
GHR<value_size> GHR<value_size>::caculateGHR(unsigned GHRBitNumber, unsigned fold) {
		std::bitset<value_size> useField = (digit << (value_size - GHRBitNumber)) >> (value_size - GHRBitNumber);
		assert((GHRBitNumber % fold) == 0 && "GHRBitNumber can't divided by fold\n");

		unsigned sifhtRightWidth = value_size - fold;
		unsigned i = 0;
		std::bitset<value_size> result = (useField << (value_size - fold * (i+1))) >> sifhtRightWidth;
#ifdef DEBUG
		std::cout << "digit:" << digit << std::endl;
		std::cout << "useField:\n" << useField << std::endl;
		std::cout << "GHR:[ " << fold*(i+1)-1 << ":" << fold*i <<"]:\n" << result << std::endl;
#endif
		for (i+=1; i < GHRBitNumber/fold; ++i) {
				std::bitset<value_size> tmp = (useField << (value_size - fold * (i+1))) >> sifhtRightWidth;
#ifdef DEBUG
				std::cout << "GHR:[ " << fold*(i+1)-1 << ":" << fold*i << "]:\n" << tmp << std::endl;
#endif
				result = result ^ tmp;
		}
#ifdef DEBUG
		std::cout << "result:\n" << result << std::endl;
#endif
		GHR<value_size> resultGHR;
		resultGHR.digit |= result;
		return resultGHR;
}
