#include "FileIO.h"

class FileReader : FileIO
{
    public:
        /**
         * @brief Opens a file for reading.
         * 
         * @param fileName Relative or absolute pathname of file to open.
         *  
         * @return true on Success.
         */
        bool openFile(string fileName);

        /**
         * @brief Get lines from file
         * 
         * @return list with lines.
         */
        list<string > getLines();
};