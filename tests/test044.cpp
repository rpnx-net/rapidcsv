// test044.cpp - set column values as char

#include <rntcsv.h>
#include "unittest.h"

int main()
{
  int rv = 0;

  std::string csvref =
    "-,A,B,C\n"
    "1,a,b,c\n"
    "2,x,y,z\n"
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

      doc.assign_column<char>(0, std::vector<char>({'a', 'x'}));
      doc.assign_column<char>(1, std::vector<char>({'b', 'y'}));
      doc.assign_column<char>("C", std::vector<char>({'c', 'z'}));

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
