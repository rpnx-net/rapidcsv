#if 0
TMP=$(mktemp -d)
c++ -std=c++11 -I src -o ${TMP}/a.out ${0} && ${TMP}/a.out ${@:1} ; RV=${?}
rm -rf ${TMP}
exit ${RV}
#endif

#include <iostream>
#include <vector>
#include "rntcsv.h"

int main()
{
  rntcsv::document doc("examples/colrowhdr.csv", rntcsv::label_parameters(0, 0));

  std::cout << doc.cell<std::string>("Volume", "2017-02-22") << std::endl;
  std::cout << doc.cell<int>("Volume", "2017-02-22") << std::endl;
  std::cout << doc.cell<long>("Volume", "2017-02-22") << std::endl;
  std::cout << doc.cell<long long>("Volume", "2017-02-22") << std::endl;
  std::cout << doc.cell<unsigned>("Volume", "2017-02-22") << std::endl;
  std::cout << doc.cell<unsigned long>("Volume", "2017-02-22") << std::endl;
  std::cout << doc.cell<unsigned long long>("Volume", "2017-02-22") << std::endl;
  std::cout << doc.cell<float>("Volume", "2017-02-22") << std::endl;
  std::cout << doc.cell<double>("Volume", "2017-02-22") << std::endl;
  std::cout << doc.cell<long double>("Volume", "2017-02-22") << std::endl;
  std::cout << doc.cell<char>("Volume", "2017-02-22") << std::endl;
}
