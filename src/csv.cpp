/*
 * CSV.cpp
 *
 *  Created on: 02/04/2022
 *      Author: Gabriel Possamai
 */

#include "../include/csv.h"

CSV::CSV(string path, bool load)
{
    this->filePath = path;

    if(load){
        vector<string> row;
        string line, tempCel;
        fstream file(this->filePath, ios::in);
        if(file.is_open()){
            while(getline(file, line)){
                row.clear();
                line += '\0';
                stringstream str(line);

                while(getline(str, tempCel, ',')){
                    string cel;
                    cel += tempCel;
                    if(cel.find('"') != std::string::npos){
                        cel += ",";
                        getline(str, tempCel, '"');
                        cel += tempCel + '"';
                        getline(str, tempCel, ',');
                    }
                    cel.erase(std::remove(cel.begin(), cel.end(), '\0'), cel.end());
                    row.push_back(cel);
                }
                this->content.push_back(row);
            }
            file.close();
	    }
	    else{
            cout<<"Could not open the file: "<<this->filePath;
            cout<<"\nPlease verify if files exist.\nPress Enter to exit . . ."<<endl;
            fflush(stdin);
            cin.ignore();
            exit(404);
        }
    }
}

CSV::~CSV()
{
    this->content.clear();
}

void CSV::save(){
    CreateDirectory ("output", NULL);
    fstream file(this->filePath, ios::out);

    if(file.is_open()){
        for(int i=0;i<this->content.size();i++){
            for(int j=0;j<this->content[i].size();j++){
                file<<content[i][j];
                if(j != this->content[i].size()-1) file<<",";
            }
            if(i != this->content.size()-1) file<<"\n";
        }
        cout<<"\nFile saved at"<<this->filePath<<endl;
    }
    else cout<<"Could not save the file\n";

    file.close();

    cout<<"\nPress Enter to continue . . ."<<endl;
    fflush(stdin);
    cin.ignore();
}

void CSV::PrintCSV(){
    this->setupMaxLen();
    cout<<endl;
    for(int i=0;i<this->content.size();i++){
        cout<<"| ";
		for(int j=0;j<this->content[i].size();j++){
            if(j == 1) {
                string tmp = content[i][j];
                tmp.erase(std::remove(tmp.begin(), tmp.end(), '\"'), tmp.end());
                cout << std::left << setw(maxLen[j]) << tmp << " | ";
            }
            else
                cout << std::left << setw(maxLen[j]) << content[i][j] << " | ";
		}
		cout<<endl;
	}
}

void CSV::setFilePath(string filePath){
    this->filePath = filePath;
}

void CSV::append(vector<string> line){
    this->content.push_back(line);
}

void CSV::append(vector<vector<string>> lines){
    for(int i=0;i<lines.size();i++){
        this->content.push_back(lines[i]);
    }
}

void CSV::sort(int col){
    std::sort(content.begin()+1, content.end(), [col](vector<string> a, vector<string> b) {
            string tmpA, tmpB;
            tmpA = a[col];
            tmpA.erase(std::remove(tmpA.begin(), tmpA.end(), '\"'), tmpA.end());
            for (int i=0;i<tmpA.length();i++) tmpA[i] = toupper(tmpA[i]);
            tmpB = b[col];
            tmpB.erase(std::remove(tmpB.begin(), tmpB.end(), '\"'), tmpB.end());
            for (int i=0;i<tmpB.length();i++) tmpB[i] = toupper(tmpB[i]);
            return tmpA < tmpB;
        }
    );
}

vector<vector<string>> CSV::find(int col, string search){
    vector<vector<string>> tmp;
    string nameTmp;

    for(int i=1;i<this->content.size();i++){
        nameTmp = this->content[i][col];
        for (int i=0;i<nameTmp.length();i++) nameTmp[i] = toupper(nameTmp[i]);
        if(nameTmp.find(search)  != std::string::npos)
            tmp.push_back(this->content[i]);
    }
    return tmp;
}

vector<string> CSV::findFirst(int col, string search){
    for(int i=0;i<this->content.size();i++){
        if(this->content[i][col] == search)
            return this->content[i];
    }
}

vector<string> CSV::getHeader(){
    return this->content[0];
}

void CSV::setupMaxLen(){
        if(this->maxLen.size() < 1){
        vector<int> len;
        for(int i=0;i<this->content.size();i++){
            len.clear();
            for(int j=0;j<this->content[i].size();j++){
                if(j == 1) {
                    string tmp = content[i][j];
                    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\"'), tmp.end());
                    len.push_back(tmp.length());
                }
                else
                    len.push_back(content[i][j].length());
            }
            this->setupMaxLenHelper(len);
        }
    }
}

void CSV::setupMaxLenHelper(vector<int> len){
    if(this->maxLen.size() < 1)
        this->maxLen = len;
    else{
        for(int i=0;i<this->maxLen.size();i++){
            if(this->maxLen[i] < len[i])
                this->maxLen[i] = len[i];
        }
    }
}
