// test006.cpp - set row values

#include <rntcsv.h>
#include "unittest.h"

int main()
{
  int rv = 0;

  std::string csvref =
    "-,A,B,C\n"
    "1,3,9,81\n"
    "2,4,16,256\n"
  ;

  std::string csv =
    "-,A,B,C\n"
    "1,0,0,0\n"
    "2,0,0,0\n"
  ;

  std::string path = unittest::TempPath();
  unittest::WriteFile(path, csv);

  try
  {
    rntcsv::document doc(path, rntcsv::label_parameters(0, 0));

      doc.assign_row<int>(0, std::vector<int>({3, 9, 81}));
    doc.assign_row<std::string>("2", std::vector<std::string>({"4", "16", "256" }));

    std::vector<int> ints;
    std::vector<std::string> strs;

    ints = doc.row<int>("1");
    unittest::ExpectEqual(size_t, ints.size(), 3);
    unittest::ExpectEqual(int, ints.at(0), 3);
    unittest::ExpectEqual(int, ints.at(1), 9);
    unittest::ExpectEqual(int, ints.at(2), 81);

    strs = doc.row<std::string>(1);
    unittest::ExpectEqual(size_t, strs.size(), 3);
    unittest::ExpectEqual(std::string, strs.at(0), "4");
    unittest::ExpectEqual(std::string, strs.at(1), "16");
    unittest::ExpectEqual(std::string, strs.at(2), "256");

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
