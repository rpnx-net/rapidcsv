// test042.cpp - test column_count() and row_count()

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
    rntcsv::document doc1(path, rntcsv::label_parameters(0, 0));
    unittest::ExpectEqual(size_t, doc1.column_count(), 3);
    unittest::ExpectEqual(size_t, doc1.row_count(), 2);

    rntcsv::document doc2(path, rntcsv::label_parameters(-1, -1));
    unittest::ExpectEqual(size_t, doc2.column_count(), 4);
    unittest::ExpectEqual(size_t, doc2.row_count(), 3);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  unittest::DeleteFile(path);

  return rv;
}
