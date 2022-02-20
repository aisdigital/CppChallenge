#include "csvParser.h"

DbnEntry CsvParser::parseLineToStruct( std::string line ){
  DbnEntry entry;
  std::string value;
  std::size_t startPosition = 0;

  value = getSubstring( line, startPosition );
  entry.dbn = value;

  value = getSubstring( line, startPosition );
  entry.schoolName = value;

  value = getSubstring( line, startPosition );
  if( value.empty() == false ) entry.testTakers = std::stoi( value );

  value = getSubstring( line, startPosition );
  if( value.empty() == false ) entry.criticalReadingMean = std::stoi( value );

  value = getSubstring( line, startPosition );
  if( value.empty() == false ) entry.mathsMean = std::stoi( value );

  value = getSubstring( line, startPosition );
  if( value.empty() == false ) entry.writingMean = std::stoi( value );

  return entry;
}

std::string CsvParser::parseStructToLine( DbnEntry entry ){
  std::string line;
  line = entry.dbn + ",";
  entry.schoolName.find( "," ) != std::string::npos
    ? line += "\"" + entry.schoolName + "\","
    : line += entry.schoolName + ",";
  entry.testTakers != 0
    ? line += std::to_string( entry.testTakers ) + ","
    : line += ",";
  entry.criticalReadingMean != 0
    ? line += std::to_string( entry.criticalReadingMean ) + ","
    : line += ",";
  entry.mathsMean != 0
    ? line += std::to_string( entry.mathsMean ) + ","
    : line += ",";
  entry.writingMean != 0
    ? line += std::to_string( entry.writingMean )
    : line; // NOP

  return line;
}

std::string CsvParser::getSubstring(
    std::string line,
    std::size_t& startPosition
  ){
  std::size_t endPosition;
  std::string value;
  if( startPosition < line.length() && line.at( startPosition ) == '"' ){
    endPosition = line.find_first_of( "\"", startPosition + 1 ) + 1;
    value = line.substr( startPosition + 1, endPosition - startPosition - 2 );
  }
  else{
    endPosition = line.find_first_of( ",", startPosition );
    value = line.substr( startPosition, endPosition - startPosition );
  }
  startPosition = endPosition + 1;
  return value;
}

