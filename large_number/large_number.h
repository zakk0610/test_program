#include<vector>
#include<bitset>
#include<algorithm>
#include<iostream>

class LargeNumber {
    public:
    LargeNumber(unsigned long long init = 0, size_t value_size = 32) {
      digit.push_back(std::bitset<64>(init));
      if (value_size > 64) {
        unsigned int num = value_size / 64;
        for(auto i = 1; i < num; ++i) {
          digit.push_back(std::bitset<64>());
        }
      }
    }

    LargeNumber(const LargeNumber& other): digit(other.digit) {};

    // move constructor
    LargeNumber(const LargeNumber&& other): digit(std::move(other.digit)) {};

//    LargeNumber & operator=(LargeNumber other) {
//      std::swap(digit, other.digit);
//      return *this;
//    }

    // move assignment operator
    LargeNumber & operator=(LargeNumber&& other) {
      digit = std::move(other.digit);
      return *this;
    }

    const LargeNumber operator&=(const LargeNumber &p2) {
      auto b2 = p2.digit.begin(),  e2 = p2.digit.end();
      for(auto b1 = digit.begin(), e1 = digit.end(); (b1 != e1 && b2 != e2); ++b1, ++b2) {
        *b1 &= *b2;
      }
      return *this;
    }

    LargeNumber operator|(const LargeNumber &rhs) {
      LargeNumber temp = *this;
      auto b1 = temp.digit.begin(), e1 = temp.digit.end();
      auto b2 = rhs.digit.begin(),  e2 = rhs.digit.end();
      if (temp.digit.size() > rhs.digit.size()) {
        for ( ; b2!=e2 ; ++b1, ++b2) {
          *b1 &= *b2;
        }
      } else {
        for ( ; b1!=e1 ; ++b1, ++b2) {
          *b1 &= *b2;
        }
        for ( ; b2 != e2; ++b2) {
          temp.digit.push_back(*b2);
        }
      }
      return temp;
    }

    LargeNumber operator|(unsigned int rhs) {
      LargeNumber temp = *this;
      temp.digit[0] |= rhs;
      return temp;
    }

		LargeNumber operator<<(const unsigned int rhs) {
			if (rhs > 64) 
				std::cerr << "TODO shift > 64" << std::endl;
			LargeNumber temp = *this;
		  unsigned long long shift_val = 0;
			for (auto &&i: temp.digit) {
        std::bitset<64> tmp = i;
				i = (i << rhs)| std::bitset<64>(shift_val);
        shift_val = (tmp >> (64 - rhs)).to_ullong(); 
      }
			return temp;
    }

	  friend std::ostream& operator<<(std::ostream& os, const LargeNumber& obj);

    void set_val(unsigned);
    unsigned int get_uint();

    private:
    std::vector<std::bitset<64>> digit;
};

