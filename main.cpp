#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

void saveResults2Csv(vector<string> results){
    ofstream file;
    string fileName;

    cout << "Type the output filename\n";
    cin >> fileName; 

    file.open("../output/" + fileName);

    for (auto i: results){
        file << i << "\n";
    }

    file.close();
}
       
void searchBySchoolName(string schoolNameEntry){
    struct sdocument {
        string readfilecsv;
        string content_document;
    };

    string complete_document;
    string document_line;
    ifstream document ("./input/SAT__College_Board__2010_School_Level_Results.csv");
    vector<string> results;

    if (document.is_open()) {
        while (getline(document, document_line)){
            for (int i=0; i<document_line.size(); i++){
                if (document_line.find(schoolNameEntry) != std::string::npos) {
                    std::cout << document_line << '\n';
                    results.push_back(document_line);
                    break;
                }
            }
        }   
        cout << "Do you want to save the results into a csv file? type 1 if yes\n";
        int op;
        cin >> op;

        if (op == 1){
            saveResults2Csv(results);
        }

    } else {
        cout << "Document not opened!";
    }
};

void searchByDBN(string entry){
    string myText;

    ifstream MyReadFile("./input/SAT__College_Board__2010_School_Level_Results.csv");

    while (getline (MyReadFile, myText)) {
        if (myText == entry){
            cout << myText << "\n";
            break;
        }

        if (myText.find(entry) != std::string::npos) {
            std::cout << myText << '\n';
            break;
        }
    }

    MyReadFile.close(); 
}

int main(){
    int operation;
    cout << "Type 1 to Search by school name" << "\n" << "Type 2 to Search by DBN\n";
    cin >> operation;

    if (operation == 1){
        string schoolName;
        cout << "Type School Name\n";
        cin >> schoolName;
        searchBySchoolName(schoolName);
    }else if (operation == 2){
        string DBNEntry;
        cout << "Type DBN\n";
        cin >> DBNEntry;
        searchByDBN(DBNEntry);
    }else{
        cout << "Operation not found!";
    }

    return 0;
};
