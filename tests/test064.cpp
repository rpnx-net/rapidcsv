// test063.cpp - linebreaks in quoted text

#include <rntcsv.h>
#include "unittest.h"

int main()
{
  int rv = 0;

  std::string csv =
    "-,A,B,C\n"
    "1,3,9,81\n"
    "2,4,16,256\n"
    "text,\"quoted text\",\"quoted\ntext\nwith\nlinebreaks\",\"\""
  ;

  std::string path = unittest::TempPath();
  unittest::WriteFile(path, csv);

  try
  {
    rntcsv::separator_parameters seppar;
    seppar.mQuotedLinebreaks = true;
    rntcsv::document doc(path, rntcsv::label_parameters(-1, -1), seppar, rntcsv::converter_parameters());

    unittest::ExpectEqual(size_t, doc.row_count(), 4);
    unittest::ExpectEqual(size_t, doc.column_count(), 4);

    unittest::ExpectEqual(char, doc.cell<char>(0, 0), '-');
    unittest::ExpectEqual(char, doc.cell<char>(1, 0), 'A');
    unittest::ExpectEqual(char, doc.cell<char>(2, 0), 'B');
    unittest::ExpectEqual(char, doc.cell<char>(3, 0), 'C');

    unittest::ExpectEqual(int, doc.cell<int>(0, 1), 1);
    unittest::ExpectEqual(int, doc.cell<int>(1, 1), 3);
    unittest::ExpectEqual(int, doc.cell<int>(2, 1), 9);
    unittest::ExpectEqual(int, doc.cell<int>(3, 1), 81);

    unittest::ExpectEqual(unsigned int, doc.cell<unsigned int>(0, 2), 2);
    unittest::ExpectEqual(unsigned int, doc.cell<unsigned int>(1, 2), 4);
    unittest::ExpectEqual(unsigned int, doc.cell<unsigned int>(2, 2), 16);
    unittest::ExpectEqual(unsigned int, doc.cell<unsigned int>(3, 2), 256);

    unittest::ExpectEqual(std::string, doc.cell<std::string>(0, 3), "text");
    unittest::ExpectEqual(std::string, doc.cell<std::string>(1, 3), "quoted text");
    unittest::ExpectEqual(std::string, doc.cell<std::string>(2, 3), "quoted\ntext\nwith\nlinebreaks");
    unittest::ExpectEqual(std::string, doc.cell<std::string>(3, 3), "");
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  unittest::DeleteFile(path);

  return rv;
}
