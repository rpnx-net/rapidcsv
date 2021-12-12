// test022.cpp - generate new document by cell, no row labels

#include <rntcsv.h>
#include "unittest.h"

int main()
{
  int rv = 0;

  std::string csvref =
    "A,B,C\n"
    "3,9,81\n"
    "4,16,256\n"
  ;

  std::string path = unittest::TempPath();

  try
  {
    rntcsv::document doc("", rntcsv::label_parameters(), rntcsv::separator_parameters(',', false, false));

      doc.set_cell<int>(0, 0, 3);
      doc.set_cell<int>(1, 0, 9);
      doc.set_cell<int>(2, 0, 81);

      doc.set_cell<int>(0, 1, 4);
      doc.set_cell<int>(1, 1, 16);
      doc.set_cell<int>(2, 1, 256);

      doc.set_column_name(0, "A");
      doc.set_column_name(1, "B");
      doc.set_column_name(2, "C");

      doc.write(path);

    std::string csvread = unittest::ReadFile(path);

    unittest::ExpectEqual(std::string, csvref, csvread);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  unittest::DeleteFile(path);

  return rv;
}
