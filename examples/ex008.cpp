#if 0
TMP=$(mktemp -d)
c++ -std=c++11 -I src -o ${TMP}/a.out ${0} && ${TMP}/a.out ${@:1} ; RV=${?}
rm -rf ${TMP}
exit ${RV}
#endif

#include <iostream>
#include <vector>
#include "rntcsv.h"

namespace rntcsv
{
  template<>
  void converter<int>::to_value(const std::string& pStr, int& pVal) const
  {
    pVal = static_cast<int>(roundf(100.0f * std::stof(pStr)));
  }
}

int main()
{
  rntcsv::document doc("examples/colrowhdr.csv", rntcsv::label_parameters(0, 0));

  std::vector<int> close = doc.column<int>("Close");
  std::cout << "close[0]  = " << close[0] << std::endl;
  std::cout << "close[1]  = " << close[1] << std::endl;
}
