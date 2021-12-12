// test050.cpp - read column header / label by index

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

  try
  {
    rntcsv::document doc(path, rntcsv::label_parameters(0, 0));
    unittest::ExpectEqual(std::string, doc.column_name(0), "A");
    unittest::ExpectEqual(std::string, doc.column_name(1), "B");
    unittest::ExpectEqual(std::string, doc.column_name(2), "C");
    ExpectException(doc.column_name(3), std::out_of_range);

    rntcsv::document doc2(path, rntcsv::label_parameters(-1, -1));
    ExpectException(doc2.column_name(0), std::out_of_range);

    rntcsv::document doc3(path, rntcsv::label_parameters(0, -1));
    unittest::ExpectEqual(std::string, doc3.column_name(0), "-");
    unittest::ExpectEqual(std::string, doc3.column_name(1), "A");
    unittest::ExpectEqual(std::string, doc3.column_name(2), "B");
    unittest::ExpectEqual(std::string, doc3.column_name(3), "C");
    ExpectException(doc3.column_name(4), std::out_of_range);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  unittest::DeleteFile(path);

  return rv;
}
