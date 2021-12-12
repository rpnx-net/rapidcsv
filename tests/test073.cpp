// test073.cpp - get column index, shift column name index

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
    rntcsv::document doc(path, rntcsv::label_parameters(1));

    unittest::ExpectEqual(ssize_t, doc.column_index("-"), -1);
    unittest::ExpectEqual(ssize_t, doc.column_index("A"), -1);
    unittest::ExpectEqual(ssize_t, doc.column_index("B"), -1);
    unittest::ExpectEqual(ssize_t, doc.column_index("C"), -1);
    unittest::ExpectEqual(ssize_t, doc.column_index("D"), -1);

    unittest::ExpectEqual(ssize_t, doc.column_index("1"), 0);
    unittest::ExpectEqual(ssize_t, doc.column_index("3"), 1);
    unittest::ExpectEqual(ssize_t, doc.column_index("9"), 2);
    unittest::ExpectEqual(ssize_t, doc.column_index("81"), 3);
    unittest::ExpectEqual(ssize_t, doc.column_index("91"), -1);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  unittest::DeleteFile(path);

  return rv;
}
