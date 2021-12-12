// test049.cpp - default conversion to custom values

#include <rntcsv.h>
#include "unittest.h"

int main()
{
  int rv = 0;

  std::string csv =
    "-,A,B,C\n"
    "1,,x,#\n"
    "2,,y,$\n"
  ;

  std::string path = unittest::TempPath();
  unittest::WriteFile(path, csv);

  try
  {
    rntcsv::document doc(path, rntcsv::label_parameters(0, 0), rntcsv::separator_parameters(),
                         rntcsv::converter_parameters(true, 0.0, 1));

    unittest::ExpectEqual(int, doc.cell<int>(0, 0), 1);
    unittest::ExpectEqual(long long, doc.cell<long long>(1, 0), 1);
    unittest::ExpectEqual(unsigned int, doc.cell<unsigned int>(2, 0), 1);

    unittest::ExpectEqual(double, doc.cell<double>(0, 1), 0.0);
    unittest::ExpectEqual(long double, doc.cell<long double>(1, 1), 0.0);
    unittest::ExpectEqual(float, doc.cell<float>(2, 1), 0.0);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  unittest::DeleteFile(path);

  return rv;
}
