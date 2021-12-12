## class rntcsv::converter< T >

Class providing conversion to/from numerical datatypes and strings. Only intended for rntcsv internal usage, but exposed externally to allow specialization for custom datatype conversions.  

---

```c++
template<typename T> converter (const converter_parameters & pConverterParams)
```
Constructor. 

**Parameters**
- `pConverterParams` specifies how conversion of non-numerical values to numerical datatype shall be handled. 

---

```c++
template<typename T> void to_string (const T & pVal, std::string & pStr)
```
Converts numerical value to string representation. 

**Parameters**
- `pVal` numerical value 
- `pStr` output string 

---

```c++
template<> void converter< std::string >::to_string (const std::string & pVal, std::string & pStr)
```
Specialized implementation handling string to string conversion. 

**Parameters**
- `pVal` string 
- `pStr` string 

---

```c++
template<typename T> void to_value (const std::string & pStr, T & pVal)
```
Converts string holding a numerical value to numerical datatype representation. 

**Parameters**
- `pVal` numerical value 
- `pStr` output string 

---

```c++
template<> void converter< std::string >::to_value (const std::string & pStr, std::string & pVal)
```
Specialized implementation handling string to string conversion. 

**Parameters**
- `pVal` string 
- `pStr` string 

---

###### API documentation generated using [Doxygenmd](https://github.com/d99kris/doxygenmd)

