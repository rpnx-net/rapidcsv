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
  rntcsv::document doc("examples/nohdr.csv", rntcsv::label_parameters(-1, -1));

  std::vector<float> close = doc.column<float>(5);
  std::cout << "Read " << close.size() << " values." << std::endl;

  long long volume = doc.cell<long long>(4, 2);
  std::cout << "Volume " << volume << " on 2017-02-22." << std::endl;
}
