#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <string>

using std::vector;
using std::string;

/**
 * @brief Class that responsible for search data in file
 */
class Search {

public:
    /**
     * @brief Constructor
     */
    Search();

    /**
     * @brief Destructor
     */
    ~Search();

    /**
     * @brief Search data with name filter
     * 
     * @param filter
     */
    vector<string> searchName(string filter);

    /**
     * @brief Search data with dbn filter
     * 
     * @param filter
     */
    vector<string> searchDbn(string filter);

    /**
     * @brief Show search result
     * 
     * @param finalResult
     */
    void showResult(vector<string> finalResult);

private:
    /**
     * @brief Sort data alphabetically
     * 
     * @param data
     * 
     * @return vector<string>
     */
    vector<string> sortData(vector<string> data);
};

#endif // SEARCH_H