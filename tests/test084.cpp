// test084.cpp - comment lines

#include <rntcsv.h>
#include "unittest.h"

int main()
{
  int rv = 0;

  std::string csvCommentLines =
    "/ comment line 1\n"
    "/ comment line 2\n"
    "-,A,B,C\n"
    "1,3,9,81\n"
    "2,4,16,256\n"
  ;

  std::string path = unittest::TempPath();
  unittest::WriteFile(path, csvCommentLines);
  try
  {
    rntcsv::document doc(path, rntcsv::label_parameters(), rntcsv::separator_parameters(),
                         rntcsv::converter_parameters(),
                         rntcsv::line_reader_parameters(true, '/'));
    unittest::ExpectEqual(size_t, doc.column<int>("A").size(), 2);
    unittest::ExpectEqual(size_t, doc.column<int>("B").size(), 2);
    unittest::ExpectEqual(size_t, doc.column<int>("C").size(), 2);

    unittest::ExpectEqual(int, doc.cell<int>(0, 0), 1);
    unittest::ExpectEqual(int, doc.cell<int>(1, 1), 4);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  unittest::DeleteFile(path);

  return rv;
}
