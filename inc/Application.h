#include <string>

#include "SATResultsManager.h"
#include "UI.h"

using std::string;

class Application
{
    private:
        string m_inputFile;

        SATResultsManager manager;
        UI interface;

        /**
         * @brief Main loop, to keep showing user options.
         */
        void runMainLoop();

        /**
         * @brief Print main menu options.
         */
        void printMainMenu();

        /**
         * @brief Application part that allows user to search results by name.
         */
        void searchByName();

        /**
         * @brief Application part that allows user to search result by DBN.
         */
        void searchByDBN();

        /**
         * @brief Makes it possible for user to store results for search.
         * 
         * @param name      Name searched.
         * @param results   Results obtained.
         */
        void storeResults(string name, list<string> &results);

    public:
        Application(string inputFile);

        /**
         * @brief Execute application, called by external methods.
         */
        void execute();
};