#include <string>

#include "FileIO.h"

using std::string;

class FileWriter : FileIO
{
    public:
        /**
         * @brief Opens a file for writing.
         * 
         * @param fileName Relative or absolute pathname of file to open.
         *  
         * @return true on Success.
         */
        bool openFile(string fileName);

        /**
         * @brief Writes a line to a file.
         * 
         * @param line Line to write.
         */
        void writeLine(string line);
};