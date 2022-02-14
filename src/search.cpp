/** \file search.cpp
 *  \brief Implementation of Search class.
 *
 */

#include "search.h"
#include "utils.h"

// ------------ Public methods implementations --------------------------------------

Search::Search()
{
    if(readDataCSV(INPUT_CSV_PATH) != READ_CSV_OK) {
        setStatus(false);
    }
    else {
        setStatus(true);
    }
}

srchFlag Search::searchMethod(srchFlag method, const string &keyword)
{
    switch(method) {
        case SEARCH_BY_NAME:
            return searchByName(keyword);
            break;
        case SEARCH_BY_DBN:
            return searchByDBN(keyword);
            break;
        default:
            // nothing: pass a valid search method!
            break;
    };

    return RES_FOUND;
}

bool Search::getStatus(void)
{
    return this->status;
}

void Search::setStatus(bool newStatus)
{
    // to-do: check if newStatus is valid
    this->status = newStatus;
}

void Search::printResults(void)
{
    // Print the results in the following format: SCHOOL_NAME (DBN)
    for(int i = 0; i < this->results.size(); i++) {
        cout << this->results.at(i).at(POS_NAME)
             << "(DBN: " 
             << this->results.at(i).at(POS_DBN)
             << ")"
             << endl;       
    }

    cout << endl;
}

void Search::clearResults(void)
{
    this->results.clear();
}

srchFlag Search::exportResults(const string &fileName)
{
    // Add the path and extension to fileName
    string fName(OUTPUT_CSV_PATH + fileName + ".csv");

    ofstream fileCSV(fName, ios::out); // Assume that fName does not have any forbidden character

    if(!fileCSV) {
        return EXP_CSV_FAIL;
    }

    // Write the columns names
    fileCSV << this->data.at(0).at(POS_DBN) << ',';
    fileCSV << this->data.at(0).at(POS_NAME) << endl;

    for(int i = 0; i < this->results.size(); i++) {
        fileCSV << this->results.at(i).at(POS_DBN) << ',';
        // Deal with school names that contain ',', putting them within double quotes.
        if(this->results.at(i).at(POS_NAME).find(",") != string::npos) {
            fileCSV << '"' << this->results.at(i).at(POS_NAME) << '"' << endl;          
        }
        else {
            fileCSV << this->results.at(i).at(POS_NAME) << endl; 
        }
    }

    return EXP_CSV_OK;
}

// ------------ Private methods implementations -------------------------------------

srchFlag Search::readDataCSV(const string &fileName)
{
   ifstream fileCSV(fileName, ios::in);

    if(!fileCSV) {
        return READ_CSV_FAIL;
    }

    string line;

    while(getline(fileCSV, line)) {
        stringstream lineStream(line);
        string col;
        vector< string > columns;

        // Deal with school names that contain ',', which are assumed to be within double quotes.
        // It is also assumed that the schools names are always in the second position of each row.
        if(line.find("\"") != string::npos) {
            string tmpCol;

            // Since we know the row doesn't start with the school name, we expect to get other data
            // (DBN) with this first getline
            getline(lineStream, tmpCol, '"');
            stringstream tmpStream(tmpCol);
            while(getline(tmpStream, col, ',')) columns.push_back(col);

            // Here we expect to get the school name
            getline(lineStream, tmpCol, '"');
            columns.push_back(tmpCol);
            // Skip the ',' after the name and continue with the regular column extraction process.
            lineStream.ignore(1, ',');
        }

        // Extract the data into columns vector
        while(getline(lineStream, col, ',')) {
                columns.push_back(col);
        }

        // Store the column
        this->data.push_back(columns);
    }

    return READ_CSV_OK;
}

srchFlag Search::searchByName(const string &name)
{
    vector< string > valuesDBN;
    vector< string > names;
    vector< int > iFound;

    // The search procedure should be case insensitive
    string lowerName(name);
    //transform(name.begin(), name.end(), lowerName.begin(), ::tolower);
    STR_TO_LOWER(name, lowerName);

    // Read each data row to find school names that contain the keyword; store their indexes.
    // Skip the first row which has the columns names.
    for(int i = 1; i < this->data.size(); i++) {
        // Convert to lowercase before searching
        string schoolName(this->data.at(i).at(POS_NAME));
        STR_TO_LOWER(schoolName, schoolName);

        if(schoolName.find(lowerName) != string::npos) {
            iFound.push_back(i);
        }
    }

    if(iFound.size() == 0) {
        return RES_NOT_FOUND;
    }

    // Sort the names alphabetically
    for(int i = 0; i < iFound.size(); i++) {
        string minName = this->data.at(iFound.at(i)).at(POS_NAME);
        int minIndex = iFound.at(i);
        int jPos;
        for(int j = i + 1; j < iFound.size(); j++) {
            if(this->data.at(iFound.at(j)).at(POS_NAME) < minName) {
                minIndex = iFound.at(j);
                jPos = j;
                minName = this->data.at(iFound.at(j)).at(POS_NAME); // Redundant, since we save minIndex
            }
        }

        if(minIndex != iFound.at(i)) {
            int tempIndex = iFound.at(i);
            iFound.at(i) = minIndex;
            iFound.at(jPos) = tempIndex;
        }
    }

    // Save the sorted data into 'results' respecting the original column order of the data
    // Only the DBN and the school name are saved although it was not clearly specified.
    for(int i = 0; i < iFound.size(); i++) {
        vector< string > schoolDBN;
        schoolDBN.push_back(this->data.at(iFound.at(i)).at(POS_DBN));
        schoolDBN.push_back(this->data.at(iFound.at(i)).at(POS_NAME));
        this->results.push_back(schoolDBN);
    }

   return RES_FOUND;
}

srchFlag Search::searchByDBN(const string &dbn)
{
    vector< string > res;
    int maxIndex = this->data.size() - 1, minIndex = 0, index = this->data.size() / 2;
    bool found = false;
    string upperDBN(dbn);

    // The search procedure should be case insensitive. Since the DBNs in the CSV file are always upper
    // case:
    STR_TO_UPPER(dbn, upperDBN);

    // to-do: handle DBNs in the format DBN1/DBN2

    // Since the DBN values are ordered, we can use binary search
    // P.S.: Since the "DBN" word of the first row is always > any DBN value, skipping the row of
    //       columns names it is not necessary.
    while( ((maxIndex - minIndex) > 1) && (found != true) ) {
        if(upperDBN == this->data.at(index).at(POS_DBN)) {
            found = true;
        }
        else if(upperDBN < this->data.at(index).at(POS_DBN)) {
            maxIndex = index;
            index = (minIndex + maxIndex) / 2;
        }
        else {
            // then (upperDBN > this->data.at(index).at(POS_DBN))
            minIndex = index;
            index = (minIndex + maxIndex) / 2;
        }
    }

    // if (found != true), then (maxIndex - minIndex == 1) and the search reached a limit in which there
    // are only three possibilities:
    if(found != true) {
        if(upperDBN == this->data.at(minIndex).at(POS_DBN)) {
            index = minIndex;
        }
        else if(upperDBN == this->data.at(maxIndex).at(POS_DBN)) {
            index = maxIndex;
        }
        else {
            // No results found
            return RES_NOT_FOUND;
        }
    }

    // Now that the result index was found, it can be saved.
    // Only the DBN and the school name are saved although it was not clearly specified.
    res.push_back(this->data.at(index).at(POS_DBN));
    res.push_back(this->data.at(index).at(POS_NAME));

    this->results.push_back(res);

    return RES_FOUND;
}

