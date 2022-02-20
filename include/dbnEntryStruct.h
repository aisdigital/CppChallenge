#ifndef DBN_ENTRY_STRUCT
#define DBN_ENTRY_STRUCT

#include <string>

typedef struct DbnEntry{
  DbnEntry():
      dbn( "" ),
      schoolName( "" ),
      testTakers( 0 ),
      criticalReadingMean( 0 ),
      mathsMean( 0 ),
      writingMean( 0 )
  {}

  std::string dbn;
  std::string schoolName;
  int testTakers;
  int criticalReadingMean;
  int mathsMean;
  int writingMean;
} DbnEntry;

#endif

