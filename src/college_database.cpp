/**
 * @file college_database.cpp
 * @author Mariana Leite
 * @brief 
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "college_database.h"

bool CollegeDatabase::load(CSVFile& file){
    if(file.cols() == CollegeDatabaseColumns::Size){
        m_database.clear();
        auto data = file.data();
        std::for_each(data.begin()+1, data.end(), [&](const std::vector<std::string>& row){
            loadCollege(row);
        });
        return true;
    }
    return false;
}

void CollegeDatabase::insert(const College& college){
    auto it = std::lower_bound(m_database.begin(), m_database.end(), college);
    m_database.insert(it, college);
}

std::ostringstream CollegeDatabase::select(const CollegeDatabaseColumns& column, const std::string& value){
    std::ostringstream stream;
    
    if(column == CollegeDatabaseColumns::DBN){
        College college;
        if(searchByDBN(college, value)){
            stream << college << std::endl;
        }
    } else if(column == CollegeDatabaseColumns::SchoolName){
        std::vector<College> colleges;
        if(searchBySchoolName(colleges, value)){
            for(const College& college : colleges){
                stream << college << std::endl;
            }
        }
    }

    return stream;
}

bool CollegeDatabase::searchByDBN(College& college, const std::string& dbn){
    college.dbn = dbn;
    auto it = std::lower_bound(m_database.begin(), m_database.end(), college);
    if(it != m_database.end()){
        if(it->dbn.compare(dbn) == 0){
            college = *it;
            return true;
        }
    }
    return false;
}

bool CollegeDatabase::searchBySchoolName(std::vector<College>& colleges, const std::string& name){
    for(const College& college : m_database){
        if(college.name.find(name) != std::string::npos){
            colleges.push_back(college);
        }
    }
    if(!colleges.empty()){
        std::sort(colleges.begin(), colleges.end(), [](const College& a, const College& b){
            return a.name < b.name;
        });
        return true;
    }
    return false;
}

void CollegeDatabase::loadCollege(const std::vector<std::string>& data){
    College college = {
        data[0], data[1], data[2], data[3], data[4], data[5]
    };
    insert(college);
}