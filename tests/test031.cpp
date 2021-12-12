// test031.cpp - generate new document by row, no row/column labels

#include <rntcsv.h>
#include "unittest.h"

int main()
{
  int rv = 0;

  std::string csvref =
    "2,4,16,256\n"
    "3,9,81,6561\n"
    "4,16,256,65536\n"
    "5,25,625,390625\n"
  ;

  std::string path = unittest::TempPath();

  try
  {
    rntcsv::document doc("", rntcsv::label_parameters(-1, -1), rntcsv::separator_parameters(',', false, false));

      doc.assign_row<int>(0, std::vector<int>({2, 4}));
      doc.assign_row<int>(1, std::vector<int>({3, 9, 81, 6561}));
      doc.assign_row<int>(2, std::vector<int>({4, 16, 256, 65536}));
      doc.assign_row<int>(3, std::vector<int>({5, 25, 625, 390625}));

      doc.set_cell<int>(2, 0, 16);
      doc.set_cell<int>(3, 0, 256);

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
