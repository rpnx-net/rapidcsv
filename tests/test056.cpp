// test056.cpp - write cells containing separator character

#include <rntcsv.h>
#include "unittest.h"

int main()
{
  int rv = 0;

  std::string csv =
    "-,A,B,C\n"
    "1,\"3,8\",9,81\n"
    "2,4,16,\"256,8\"\n"
  ;

  std::string path = unittest::TempPath();
  unittest::WriteFile(path, csv);
  std::string outpath = unittest::TempPath();

  try
  {
    rntcsv::Document doc(path, rntcsv::LabelParams(0, 0));
    doc.SetCell<std::string>("C", "2", "256,8");
    doc.Save(outpath);
    std::string csvread = unittest::ReadFile(outpath);
    unittest::ExpectEqual(std::string, csv, csvread);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  unittest::DeleteFile(path);
  unittest::DeleteFile(outpath);

  return rv;
}
