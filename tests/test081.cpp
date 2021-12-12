// test081.cpp - generate new document with insert column

#include <rntcsv.h>
#include "unittest.h"

int main()
{
  int rv = 0;

  std::string csvref =
    ",A,B,C,D\n"
    "0,2,4,16,256\n"
    "1,3,9,81,6561\n"
    "2,4,16,256,65536\n"
    "3,5,25,625,390625\n"
  ;

  std::string path = unittest::TempPath();

  try
  {
    rntcsv::document doc("", rntcsv::label_parameters(0, 0), rntcsv::separator_parameters(',', false, false));

      doc.insert_column(0, std::vector<int>({4, 9, 16, 25}), "B");
      doc.insert_column(0, std::vector<int>({2, 3, 4, 5}), "A");

      doc.insert_column<int>(2);
      doc.assign_column(2, std::vector<int>({16, 81, 256, 625}));
      doc.set_column_name(2, "C");

      doc.insert_column(3, std::vector<int>({256, 6561, 65536, 390625}), "D");

      doc.row_name(0, "0");
      doc.row_name(1, "1");
      doc.row_name(2, "2");
      doc.row_name(3, "3");

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
