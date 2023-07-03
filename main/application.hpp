#pragma once
#include <string>
#include "level_results.hpp"

class Application
{
    public:
        Application() = default;
        void run();
        bool setup(const std::string& filepath);


    private:
        void optionSearchBySchoolName();
        void optionSearchByDBN();

        LevelResults levelResults;

};