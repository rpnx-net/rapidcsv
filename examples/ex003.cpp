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
  rntcsv::Document doc("examples/rowhdr.csv", rntcsv::LabelParams(-1, 0));

  std::vector<std::string> row = doc.GetRow<std::string>("2017-02-22");
  std::cout << "Read " << row.size() << " values." << std::endl;
}
