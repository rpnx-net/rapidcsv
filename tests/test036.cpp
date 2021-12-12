// test036.cpp - supported datatypes

#include <rntcsv.h>
#include "unittest.h"

int main()
{
  int rv = 0;

  std::string csv =
    "int,32767\n"
    "long,2147483647\n"
    "long long,9223372036854775807\n"
    "unsigned,65535\n"
    "unsigned long,4294967295\n"
    "unsigned long long,18446744073709551615\n"
    "float,3.3E38\n"
    "double,1.6E308\n"
    "long double,1.6E308\n"
  ;

  std::string path = unittest::TempPath();
  unittest::WriteFile(path, csv);

  try
  {
    rntcsv::document doc(path, rntcsv::label_parameters(-1, -1));

    unittest::ExpectEqual(int, doc.cell<int>(1, 0), 32767);
    unittest::ExpectEqual(long, doc.cell<long>(1, 1), 2147483647);
    unittest::ExpectEqual(long long, doc.cell<long long>(1, 2), 9223372036854775807);

    unittest::ExpectEqual(unsigned, doc.cell<unsigned>(1, 3), 65535);
    unittest::ExpectEqual(unsigned long, doc.cell<unsigned long>(1, 4), 4294967295);
    unittest::ExpectEqual(unsigned long long, doc.cell<unsigned long long>(1, 5), 18446744073709551615llu);

    float floatval = doc.cell<float>(1, 6);
    unittest::ExpectTrue((floatval > 3.2E38) && (floatval < 3.4E38));

    double doubleval = doc.cell<double>(1, 7);
    unittest::ExpectTrue((doubleval > 1.5E308) && (doubleval < 1.7E308));

    long double longdoubleval = doc.cell<long double>(1, 8);
    unittest::ExpectTrue((longdoubleval > 1.5E308) && (longdoubleval < 1.7E308));
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  unittest::DeleteFile(path);

  return rv;
}
