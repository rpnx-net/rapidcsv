// test055.cpp - write to stream

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

  std::string outpath = unittest::TempPath();

  try
  {
    // to file stream
    rntcsv::document doc(path, rntcsv::label_parameters(0, 0));
    std::ofstream ostream;
    ostream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    ostream.open(outpath, std::ios::binary | std::ios::ate);
      doc.write(ostream);
    ostream.close();

    std::string csvread = unittest::ReadFile(outpath);
    unittest::ExpectEqual(std::string, csv, csvread);

    // to string stream
    std::ostringstream sstream;
      doc.write(sstream);
    unittest::ExpectEqual(std::string, csv, sstream.str());
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  unittest::DeleteFile(path);

  return rv;
}
