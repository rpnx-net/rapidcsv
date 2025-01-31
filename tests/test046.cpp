// test046.cpp - write data with custom separator

#include <rntcsv.h>
#include "unittest.h"

int main()
{
  int rv = 0;

  std::string csvref =
    "-;A;B;C\n"
    "1;3;9;81\n"
    "2;4;16;256\n"
  ;

  std::string csv =
    "-;A;B;C\n"
    "1;0;0;0\n"
    "2;0;0;0\n"
  ;

  std::string path = unittest::TempPath();
  unittest::WriteFile(path, csv);

  try
  {
    rntcsv::document doc(path, rntcsv::label_parameters(0, 0), rntcsv::separator_parameters(';'));

      doc.set_cell<int>(0, 0, 3);
      doc.set_cell<int>(1, 0, 9);
      doc.set_cell<int>(2, 0, 81);

      doc.set_cell<std::string>("A", "2", "4");
      doc.set_cell<std::string>("B", "2", "16");
      doc.set_cell<std::string>("C", "2", "256");

    unittest::ExpectEqual(int, doc.cell<int>(0, 0), 3);
    unittest::ExpectEqual(int, doc.cell<int>(1, 0), 9);
    unittest::ExpectEqual(int, doc.cell<int>(2, 0), 81);

    unittest::ExpectEqual(std::string, doc.cell<std::string>("A", "2"), "4");
    unittest::ExpectEqual(std::string, doc.cell<std::string>("B", "2"), "16");
    unittest::ExpectEqual(std::string, doc.cell<std::string>("C", "2"), "256");

      doc.write();

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
