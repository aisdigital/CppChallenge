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
        searchByName("saTellite");
        string name(OUTPUT_CSV_PATH);
        name += "myfile.csv";
        exportResults(name);
    }
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

    // The search procedure should be case independent
    string lowerName(name);
    //transform(name.begin(), name.end(), lowerName.begin(), ::tolower);
    STR_TO_LOWER(name, lowerName);

    // Read each data row to find school names that contain the keyword; store their indexes
    for(int i = 0; i < this->data.size(); i++) {
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

srchFlag Search::exportResults(const string &fileName)
{
    ofstream fileCSV(fileName, ios::out); // Assume that fileName does not have any forbidden character

    if(!fileCSV) {
        return EXP_CSV_FAIL;
    }

    for(int i = 0; i < this->data.size(); i++) {
        fileCSV << this->data.at(i).at(POS_DBN) << ',';
        // Deal with school names that contain ',', putting them within double quotes.
        if(this->data.at(i).at(POS_NAME).find(",") != string::npos) {
            fileCSV << '"' << this->data.at(i).at(POS_NAME) << '"' << endl;          
        }
        else {
            fileCSV << this->data.at(i).at(POS_NAME) << endl; 
        }
    }

    return EXP_CSV_OK;
}

/*
srchFlag Search::searchByDBN(const DataCSV &data, DataCSV &results, const string &dbn)
{
    vector< string > res;
    int maxIndex = data.size() - 1, minIndex = 0, index = data.size() / 2;
    bool found = false;
    string upperDBN(dbn);

    // The search procedure should be case independent. Since the DBNs in the CSV file are always upper
    // case:
    STR_TO_UPPER(dbn, upperDBN);

    // to-do: handle DBNs in the format DBN1/DBN2

    // Since the DBN values are ordered, we can use binary search
    while( ((maxIndex - minIndex) > 1) && (found != true) ) {
        if(upperDBN == data.at(index).at(POS_DBN)) {
            found = true;
        }
        else if(upperDBN < data.at(index).at(POS_DBN)) {
            maxIndex = index;
            index = (minIndex + maxIndex) / 2;
        }
        else {
            // then (upperDBN > data.at(index).at(POS_DBN))
            minIndex = index;
            index = (minIndex + maxIndex) / 2;
        }
    }

    // if (found != true), then (maxIndex - minIndex == 1) and the search reached a limit in which there
    // are only three possibilities:
    if(found != true) {
        if(upperDBN == data.at(minIndex).at(POS_DBN)) {
            index = minIndex;
        }
        else if(upperDBN == data.at(maxIndex).at(POS_DBN)) {
            index = maxIndex;
        }
        else {
            // No results found
            return RES_NOT_FOUND;
        }
    }

    // Now that the result index was found, it can be saved.
    // Only the DBN and the school name are saved although it was not clearly specified.
    res.push_back(data.at(index).at(POS_DBN));
    res.push_back(data.at(index).at(POS_NAME));

    results.push_back(res);

    return RES_FOUND;
}
*/
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
