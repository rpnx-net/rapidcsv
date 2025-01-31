// test069.cpp - get row index, no row labels

#include <rntcsv.h>
#include "unittest.h"

int main()
{
  int rv = 0;

  std::string csv =
    "-,A,B,C\n"
    "1,3,9,81\n"
    "2,4,16,256\n"
  ;

  std::string path = unittest::TempPath();
  unittest::WriteFile(path, csv);

  try
  {
    rntcsv::document doc(path);

    unittest::ExpectEqual(ssize_t, doc.row_index("-"), -1);
    unittest::ExpectEqual(ssize_t, doc.row_index("1"), -1);
    unittest::ExpectEqual(ssize_t, doc.row_index("2"), -1);
    unittest::ExpectEqual(ssize_t, doc.row_index("3"), -1);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  unittest::DeleteFile(path);

  return rv;
}
