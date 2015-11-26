#include "large_number.h"
#include <iterator>

void LargeNumber::set_val(unsigned int val) {
  digit[0] = std::bitset<64>(val);
}

unsigned int LargeNumber::get_uint() {
  return static_cast<unsigned int>(digit[0].to_ulong());
}

std::ostream& operator<<(std::ostream& os, const LargeNumber& obj){
  for (auto rb = obj.digit.rbegin(), re= obj.digit.rend(); rb!=re; ++rb){
		os << rb->to_string() << "|";
	}
	return os;
}
