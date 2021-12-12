// test080.cpp - test clear

#include <rntcsv.h>
#include "unittest.h"

int main()
{
  int rv = 0;

  std::string csv =
    "A,B,C,D\n"
    "1,3,9,81\n"
    "2,4,16,256\n"
  ;

  std::string path = unittest::TempPath();
  unittest::WriteFile(path, csv);

  try
  {
    rntcsv::document doc(path);
    unittest::ExpectEqual(size_t, doc.GetRowCount(), 2);

      doc.clear();
    unittest::ExpectEqual(size_t, doc.GetRowCount(), 0);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  unittest::DeleteFile(path);

  return rv;
}
