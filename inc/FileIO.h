#include <string>
#include <fstream>

using std::string;
using std::fstream;

class FileIO 
{
    private:
        fstream m_fstream;

    public:
        ~FileIO();

        /**
         * @brief Opens a file.
         * 
         * @param fileName Relative or absolute pathname of file to open.
         *  
         * @return true on Success.
         */
        virtual bool openFile(string fileName) = 0;
};