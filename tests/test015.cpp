// test015.cpp - set column values, no row labels

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

  std::string csv =
    "A,B,C\n"
    "0,0,0\n"
    "0,0,0\n"
  ;

  std::string path = unittest::TempPath();
  unittest::WriteFile(path, csv);

  try
  {
    rntcsv::document doc(path);

      doc.assign_column<int>(0, std::vector<int>({3, 4}));
      doc.assign_column<int>("B", std::vector<int>({9, 16}));
      doc.assign_column<std::string>(2, std::vector<std::string>({"81", "256"}));

    std::vector<int> ints;
    std::vector<std::string> strs;

    ints = doc.column<int>(0);
    unittest::ExpectEqual(size_t, ints.size(), 2);
    unittest::ExpectEqual(int, ints.at(0), 3);
    unittest::ExpectEqual(int, ints.at(1), 4);

    strs = doc.column<std::string>(1);
    unittest::ExpectEqual(size_t, strs.size(), 2);
    unittest::ExpectEqual(std::string, strs.at(0), "9");
    unittest::ExpectEqual(std::string, strs.at(1), "16");

    ints = doc.column<int>("C");
    unittest::ExpectEqual(size_t, ints.size(), 2);
    unittest::ExpectEqual(int, ints.at(0), 81);
    unittest::ExpectEqual(int, ints.at(1), 256);

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
