// test047.cpp - exception on invalid conversion

#include <rntcsv.h>
#include "unittest.h"

int main()
{
  int rv = 0;

  std::string csv =
    "-,A,B,C\n"
    "1,,x,#\n"
    "2,,y,$\n"
  ;

  std::string path = unittest::TempPath();
  unittest::WriteFile(path, csv);

  try
  {
    rntcsv::document doc(path, rntcsv::label_parameters(0, 0));

    ExpectException(doc.cell<int>(0, 0), std::invalid_argument);
    ExpectException(doc.cell<int>(1, 0), std::invalid_argument);
    ExpectException(doc.cell<int>(2, 0), std::invalid_argument);

    ExpectException(doc.cell<double>(0, 1), std::invalid_argument);
    ExpectException(doc.cell<double>(1, 1), std::invalid_argument);
    ExpectException(doc.cell<double>(2, 1), std::invalid_argument);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  unittest::DeleteFile(path);

  return rv;
}
