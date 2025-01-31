// test086.cpp - exception message reading out-of-range column

#include <rntcsv.h>
#include "unittest.h"

int main()
{
  int rv = 0;

  std::string csv =
    "-,A,B,C\n"
    "1,3,9,81\n"
    "2,4,16\n"
  ;

  std::string path = unittest::TempPath();
  unittest::WriteFile(path, csv);

  try
  {
    rntcsv::document doc(path, rntcsv::label_parameters(0, 0));

    unittest::ExpectEqual(std::string, doc.column_name(0), "A");
    unittest::ExpectEqual(std::string, doc.column_name(1), "B");
    unittest::ExpectEqual(std::string, doc.column_name(2), "C");

    ExpectExceptionMsg(doc.column<int>(2), std::out_of_range,
                       "requested column index 2 >= 2 (number of columns on row index 1)");
    ExpectExceptionMsg(doc.column<int>("C"), std::out_of_range,
                       "requested column index 2 >= 2 (number of columns on row index 1)");
    ExpectExceptionMsg(doc.column<int>(3), std::out_of_range,
                       "requested column index 3 >= 3 (number of columns on row index 0)");
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  unittest::DeleteFile(path);

  return rv;
}
