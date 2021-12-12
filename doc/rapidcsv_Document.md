## class rntcsv::document

Class representing a CSV document.  

---

```c++
document (const std::string & pPath = std::string(), const label_parameters & pLabelParams = label_parameters(), const separator_parameters & pSeparatorParams = separator_parameters(), const converter_parameters & pConverterParams = converter_parameters(), const line_reader_parameters & pLineReaderParams = line_reader_parameters())
```
Constructor. 

**Parameters**
- `pPath` specifies the path of an existing CSV-file to populate the document data with. 
- `pLabelParams` specifies which row and column should be treated as labels. 
- `pSeparatorParams` specifies which field and row separators should be used. 
- `pConverterParams` specifies how invalid numbers (including empty strings) should be handled. 
- `pLineReaderParams` specifies how special line formats should be treated. 

---

```c++
document (std::istream & pStream, const label_parameters & pLabelParams = label_parameters(), const separator_parameters & pSeparatorParams = separator_parameters(), const converter_parameters & pConverterParams = converter_parameters(), const line_reader_parameters & pLineReaderParams = line_reader_parameters())
```
Constructor. 

**Parameters**
- `pStream` specifies an input stream to read CSV data from. 
- `pLabelParams` specifies which row and column should be treated as labels. 
- `pSeparatorParams` specifies which field and row separators should be used. 
- `pConverterParams` specifies how invalid numbers (including empty strings) should be handled. 
- `pLineReaderParams` specifies how special line formats should be treated. 

---

```c++
void clear ()
```
Clears loaded document data. 

---

```c++
template<typename T > T cell (const size_t pColumnIdx, const size_t pRowIdx)
```
Get cell by index. 

**Parameters**
- `pColumnIdx` zero-based column index. 
- `pRowIdx` zero-based row index. 

**Returns:**
- cell data. 

---

```c++
template<typename T > T cell (const size_t pColumnIdx, const size_t pRowIdx, conversion_func< T > pToVal)
```
Get cell by index. 

**Parameters**
- `pColumnIdx` zero-based column index. 
- `pRowIdx` zero-based row index. 
- `pToVal` conversion function. 

**Returns:**
- cell data. 

---

```c++
template<typename T > T cell (const std::string & pColumnName, const std::string & pRowName)
```
Get cell by name. 

**Parameters**
- `pColumnName` column label name. 
- `pRowName` row label name. 

**Returns:**
- cell data. 

---

```c++
template<typename T > T cell (const std::string & pColumnName, const std::string & pRowName, conversion_func< T > pToVal)
```
Get cell by name. 

**Parameters**
- `pColumnName` column label name. 
- `pRowName` row label name. 
- `pToVal` conversion function. 

**Returns:**
- cell data. 

---

```c++
template<typename T > T cell (const std::string & pColumnName, const size_t pRowIdx)
```
Get cell by column name and row index. 

**Parameters**
- `pColumnName` column label name. 
- `pRowIdx` zero-based row index. 

**Returns:**
- cell data. 

---

```c++
template<typename T > T cell (const std::string & pColumnName, const size_t pRowIdx, conversion_func< T > pToVal)
```
Get cell by column name and row index. 

**Parameters**
- `pColumnName` column label name. 
- `pRowIdx` zero-based row index. 
- `pToVal` conversion function. 

**Returns:**
- cell data. 

---

```c++
template<typename T > T cell (const size_t pColumnIdx, const std::string & pRowName)
```
Get cell by column index and row name. 

**Parameters**
- `pColumnIdx` zero-based column index. 
- `pRowName` row label name. 

**Returns:**
- cell data. 

---

```c++
template<typename T > T cell (const size_t pColumnIdx, const std::string & pRowName, conversion_func< T > pToVal)
```
Get cell by column index and row name. 

**Parameters**
- `pColumnIdx` zero-based column index. 
- `pRowName` row label name. 
- `pToVal` conversion function. 

**Returns:**
- cell data. 

---

```c++
template<typename T > std::vector<T> column (const size_t pColumnIdx)
```
Get column by index. 

**Parameters**
- `pColumnIdx` zero-based column index. 

**Returns:**
- vector of column data. 

---

```c++
template<typename T > std::vector<T> column (const size_t pColumnIdx, conversion_func< T > pToVal)
```
Get column by index. 

**Parameters**
- `pColumnIdx` zero-based column index. 
- `pToVal` conversion function. 

**Returns:**
- vector of column data. 

---

```c++
template<typename T > std::vector<T> column (const std::string & pColumnName)
```
Get column by name. 

**Parameters**
- `pColumnName` column label name. 

**Returns:**
- vector of column data. 

---

```c++
template<typename T > std::vector<T> column (const std::string & pColumnName, conversion_func< T > pToVal)
```
Get column by name. 

**Parameters**
- `pColumnName` column label name. 
- `pToVal` conversion function. 

**Returns:**
- vector of column data. 

---

```c++
size_t column_count ()
```
Get number of data columns (excluding label columns). 

**Returns:**
- column count. 

---

```c++
ssize_t column_index (const std::string & pColumnName)
```
Get column index by name. 

**Parameters**
- `pColumnName` column label name. 

**Returns:**
- zero-based column index. 

---

```c++
std::string column_name (const ssize_t pColumnIdx)
```
Get column name. 

**Parameters**
- `pColumnIdx` zero-based column index. 

**Returns:**
- column name. 

---

```c++
std::vector<std::string> column_names ()
```
Get column names. 

**Returns:**
- vector of column names. 

---

```c++
template<typename T > std::vector<T> row (const size_t pRowIdx)
```
Get row by index. 

**Parameters**
- `pRowIdx` zero-based row index. 

**Returns:**
- vector of row data. 

---

```c++
template<typename T > std::vector<T> row (const size_t pRowIdx, conversion_func< T > pToVal)
```
Get row by index. 

**Parameters**
- `pRowIdx` zero-based row index. 
- `pToVal` conversion function. 

**Returns:**
- vector of row data. 

---

```c++
template<typename T > std::vector<T> row (const std::string & pRowName)
```
Get row by name. 

**Parameters**
- `pRowName` row label name. 

**Returns:**
- vector of row data. 

---

```c++
template<typename T > std::vector<T> row (const std::string & pRowName, conversion_func< T > pToVal)
```
Get row by name. 

**Parameters**
- `pRowName` row label name. 
- `pToVal` conversion function. 

**Returns:**
- vector of row data. 

---

```c++
size_t row_count ()
```
Get number of data rows (excluding label rows). 

**Returns:**
- row count. 

---

```c++
ssize_t row_index (const std::string & pRowName)
```
Get row index by name. 

**Parameters**
- `pRowName` row label name. 

**Returns:**
- zero-based row index. 

---

```c++
std::string row_name (const ssize_t pRowIdx)
```
Get row name. 

**Parameters**
- `pRowIdx` zero-based column index. 

**Returns:**
- row name. 

---

```c++
std::vector<std::string> row_names ()
```
Get row names. 

**Returns:**
- vector of row names. 

---

```c++
template<typename T > void insert_column (const size_t pColumnIdx, const std::vector< T > & pColumn = std::vector<T>(), const std::string & pColumnName = std::string())
```
Insert column at specified index. 

**Parameters**
- `pColumnIdx` zero-based column index. 
- `pColumn` vector of column data (optional argument). 
- `pColumnName` column label name (optional argument). 

---

```c++
template<typename T > void insert_row (const size_t pRowIdx, const std::vector< T > & pRow = std::vector<T>(), const std::string & pRowName = std::string())
```
Insert row at specified index. 

**Parameters**
- `pRowIdx` zero-based row index. 
- `pRow` vector of row data (optional argument). 
- `pRowName` row label name (optional argument). 

---

```c++
void assign_from_file (const std::string & pPath, const label_parameters & pLabelParams = label_parameters(), const separator_parameters & pSeparatorParams = separator_parameters(), const converter_parameters & pConverterParams = converter_parameters(), const line_reader_parameters & pLineReaderParams = line_reader_parameters())
```
Read document data from file. 

**Parameters**
- `pPath` specifies the path of an existing CSV-file to populate the document data with. 
- `pLabelParams` specifies which row and column should be treated as labels. 
- `pSeparatorParams` specifies which field and row separators should be used. 
- `pConverterParams` specifies how invalid numbers (including empty strings) should be handled. 
- `pLineReaderParams` specifies how special line formats should be treated. 

---

```c++
void assign_from_file (std::istream & pStream, const label_parameters & pLabelParams = label_parameters(), const separator_parameters & pSeparatorParams = separator_parameters(), const converter_parameters & pConverterParams = converter_parameters(), const line_reader_parameters & pLineReaderParams = line_reader_parameters())
```
Read document data from stream. 

**Parameters**
- `pStream` specifies an input stream to read CSV data from. 
- `pLabelParams` specifies which row and column should be treated as labels. 
- `pSeparatorParams` specifies which field and row separators should be used. 
- `pConverterParams` specifies how invalid numbers (including empty strings) should be handled. 
- `pLineReaderParams` specifies how special line formats should be treated. 

---

```c++
void erase_column (const size_t pColumnIdx)
```
Remove column by index. 

**Parameters**
- `pColumnIdx` zero-based column index. 

---

```c++
void erase_column (const std::string & pColumnName)
```
Remove column by name. 

**Parameters**
- `pColumnName` column label name. 

---

```c++
void erase_row (const size_t pRowIdx)
```
Remove row by index. 

**Parameters**
- `pRowIdx` zero-based row index. 

---

```c++
void erase_row (const std::string & pRowName)
```
Remove row by name. 

**Parameters**
- `pRowName` row label name. 

---

```c++
void write (const std::string & pPath = std::string())
```
Write document data to file. 

**Parameters**
- `pPath` optionally specifies the path where the CSV-file will be created (if not specified, the original path provided when creating or loading the document data will be used). 

---

```c++
void write (std::ostream & pStream)
```
Write document data to stream. 

**Parameters**
- `pStream` specifies an output stream to write the data to. 

---

```c++
template<typename T > void set_cell (const size_t pColumnIdx, const size_t pRowIdx, const T & pCell)
```
Set cell by index. 

**Parameters**
- `pRowIdx` zero-based row index. 
- `pColumnIdx` zero-based column index. 
- `pCell` cell data. 

---

```c++
template<typename T > void set_cell (const std::string & pColumnName, const std::string & pRowName, const T & pCell)
```
Set cell by name. 

**Parameters**
- `pColumnName` column label name. 
- `pRowName` row label name. 
- `pCell` cell data. 

---

```c++
template<typename T > void assign_column (const size_t pColumnIdx, const std::vector< T > & pColumn)
```
Set column by index. 

**Parameters**
- `pColumnIdx` zero-based column index. 
- `pColumn` vector of column data. 

---

```c++
template<typename T > void assign_column (const std::string & pColumnName, const std::vector< T > & pColumn)
```
Set column by name. 

**Parameters**
- `pColumnName` column label name. 
- `pColumn` vector of column data. 

---

```c++
void set_column_name (size_t pColumnIdx, const std::string & pColumnName)
```
Set column name. 

**Parameters**
- `pColumnIdx` zero-based column index. 
- `pColumnName` column name. 

---

```c++
template<typename T > void assign_row (const size_t pRowIdx, const std::vector< T > & pRow)
```
Set row by index. 

**Parameters**
- `pRowIdx` zero-based row index. 
- `pRow` vector of row data. 

---

```c++
template<typename T > void assign_row (const std::string & pRowName, const std::vector< T > & pRow)
```
Set row by name. 

**Parameters**
- `pRowName` row label name. 
- `pRow` vector of row data. 

---

```c++
void row_name (size_t pRowIdx, const std::string & pRowName)
```
Set row name. 

**Parameters**
- `pRowIdx` zero-based row index. 
- `pRowName` row name. 

---

###### API documentation generated using [Doxygenmd](https://github.com/d99kris/doxygenmd)

