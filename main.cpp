/**
 * @file main.cpp
 * @author Mariana Leite
 * @brief 
 * @version 0.1
 * @date 2022-07-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

#include "console.h"
#include "college_database.h"

int main(int argc, const char * argv[]) { 

	CSVFile file("input/SAT__College_Board__2010_School_Level_Results.csv");
	CollegeDatabase database;
	database.load(file);

	while(1){
		Console::printOperationsMenu();
		Operation operation = Console::getUserOperation();

		if(operation == Operation::SearchSchoolName){
			std::string search = Console::getUserSearch();
			std::ostringstream stream = database.select(CollegeDatabaseColumns::SchoolName, search);
			Console::printSearchResult(stream);
			if(Console::getUserFilePreference()){
				std::ofstream file("output/result.csv");
				file << stream.str();
				file.close();
			}
		} else if(operation == Operation::SearchDBN){
			std::string search = Console::getUserSearch();
			std::ostringstream stream = database.select(CollegeDatabaseColumns::DBN, search);
			Console::printSearchResult(stream);
		} else if(operation == Operation::Exit){
			break;
		}
	}

	return 0;
}