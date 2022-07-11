
#include "SchoolSatResult.h"
#include "FileUtils.hpp"
#include "Parser.hpp"

class Database
{
public:
    
    void Read( const std::string filename )
    {
        std::vector<std::string> buffer = FileUtils::ReadCSV(filename);
        schoolSatResultData = Parser::ToSchoolSatList( buffer );
    }

    SchoolSatResult FindByDBN(const std::string & DBN )
    {
        return schoolSatResultData.at(DBN);
    }

    SchoolSatResult FindBySchoolName(const std::string & schoolName )
    {
        SchoolSatResult schoolSatResult;

        return schoolSatResult;
    }

private:
    std::unordered_map<std::string,SchoolSatResult> schoolSatResultData;
};