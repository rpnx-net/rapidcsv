// test040b.cpp - multiple translation units, part 2

#include <rntcsv.h>
#include "unittest.h"

int help_func()
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
    rntcsv::Document doc(path, rntcsv::LabelParams(0, 0));
    unittest::ExpectEqual(int, doc.GetCell<int>(0, 0), 3);
    unittest::ExpectEqual(int, doc.GetCell<int>(1, 0), 9);
    unittest::ExpectEqual(int, doc.GetCell<int>(2, 0), 81);

    unittest::ExpectEqual(std::string, doc.GetCell<std::string>("A", "2"), "4");
    unittest::ExpectEqual(std::string, doc.GetCell<std::string>("B", "2"), "16");
    unittest::ExpectEqual(std::string, doc.GetCell<std::string>("C", "2"), "256");
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  unittest::DeleteFile(path);

  return rv;
}
