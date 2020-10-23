#include <cstddef>  // size_t 
#include <cstring>  // strrchr 
#include <iostream> 
using namespace std; 

size_t const NPOS = -1; 

struct Text_position 

{ 
  size_t line = NPOS, column = NPOS;
}; 

inline bool operator==(Text_position const & a, Text_position const & b) 
{ 
  return a.line == b.line && a.column == b.column; 
} 

inline bool operator!=(Text_position const & a, Text_position const & b) 
{ 
  return !(a == b); 
} 

size_t text_size(char const * const * text) 
{ 
  size_t size = 0; 
  while (*text++) 
    ++size; 
  return size; 
} 

size_t foo(char const * text, char const * sub) 
{ 
 size_t sum = 0;
 for (; auto p = strstr(text, sub); ++sum)
 {
    text = p + 1; // "aaaa", "aa"
 }    
   return sum;
} 
size_t fuk(char const * const * text, char const * const * sub )
{
  size_t summ = 0; 
  while(*text)
  {
    summ += foo(*text, *sub);
    text ++;
    
  }
    return summ;
}
int test_find_last_char() 
{ 
  char const*  text[] 
  { 
    "121978121912", //3
    "12.10.2012", //2
    "19.12.2019", //1
    "yes/not", //0
    nullptr // sum 6
  }; 
  char const * sub[]
  { 
    "12", 
    nullptr 
  }; 
 

  if (fuk(text, sub) != 6) 
    return 1; 
  if (fuk(text +1, sub) != 3) 
    return 2; 
  if (fuk(text +2, sub) != 1) 
    return 3; 
  if (fuk(text +3, sub) != 0) 
    return 4; 

  return 0; 

} 

int main() 
{ 
  cout << "test find_last_char (should write 0): "; 
  cout << test_find_last_char(); 
  return 0; 
} 

//jarosloov//


