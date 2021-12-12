// test034.cpp - copy document

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

  std::string pathcopy = unittest::TempPath();

  try
  {
    rntcsv::document doc(path, rntcsv::label_parameters(0, 0));

    rntcsv::document doccopy(doc);

    doccopy.Save(pathcopy);

    std::string csvread = unittest::ReadFile(pathcopy);

    unittest::ExpectEqual(std::string, csv, csvread);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  unittest::DeleteFile(path);
  unittest::DeleteFile(pathcopy);

  return rv;
}
