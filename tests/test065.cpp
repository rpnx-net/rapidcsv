// test065.cpp - row/column count with header index out of data size

#include <rntcsv.h>
#include "unittest.h"

int main()
{
  int rv = 0;

  std::string csvEmpty = "";

  std::string path = unittest::TempPath();
  unittest::WriteFile(path, csvEmpty);

  try
  {
    // empty doc, column header index 0, no row header
    rntcsv::document doc1(path, rntcsv::label_parameters(0, -1));
    unittest::ExpectEqual(size_t, doc1.row_count(), 0);
    unittest::ExpectEqual(size_t, doc1.column_count(), 0);

    // empty doc, row header index 0, no row header
    rntcsv::document doc2(path, rntcsv::label_parameters(-1, 0));
    unittest::ExpectEqual(size_t, doc2.row_count(), 0);
    unittest::ExpectEqual(size_t, doc2.column_count(), 0);

    std::string csv =
      "-,A,B,C\n"
      "1,3,9,81\n"
      "2,4,16,256\n"
    ;

    // doc with three rows, column header index 10, no row header
    std::istringstream sstream3(csv);
    rntcsv::document doc3(sstream3, rntcsv::label_parameters(10, -1));
    unittest::ExpectEqual(size_t, doc3.row_count(), 0);
    unittest::ExpectEqual(size_t, doc3.column_count(), 4);

    // doc with three rows, row header index 10, no column header
    std::istringstream sstream4(csv);
    rntcsv::document doc4(sstream4, rntcsv::label_parameters(-1, 10));
    unittest::ExpectEqual(size_t, doc4.row_count(), 3);
    unittest::ExpectEqual(size_t, doc4.column_count(), 0);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  unittest::DeleteFile(path);

  return rv;
}
