// Challenge C++ AISDigital

/*
 * main.cpp
 *
 *  Modified on: 02/04/2022
 *      Author: Gabriel Possamai
 */

#include "include/csv.h"


using namespace std;

//! option1 method.
/*!
    Runs the necessary logics for option 1.
    \param csv a pointer to in memory CSV.
*/
void option1(CSV* csv);

//! option2 method.
/*!
    Runs the necessary logics for option 2.
    \param csv a pointer to in memory CSV.
*/
void option2(CSV* csv);


//! main method.
/*!
    Create the CSV and shows the menu options.
    \param argc an int
    \param argv a const char *
*/
int main(int argc, const char * argv[]) {
  cout<<"Welcome to CppChallange!\nPlease wait while loading CSV file.\n\n"<<endl;

  CSV* csv = new CSV("input/SAT__College_Board__2010_School_Level_Results.csv", true);

  int opcao = -1;
  while(opcao != 3){
    system("cls");
    cout<<"CppChallange Menu\nSelect an option.\n"<<endl;
    cout<<"1-Search by name\n2-Search by DBN\n3-Exit the program\n"<<endl;
    fflush(stdin);
    cin>>opcao;

    switch(opcao){
      case 1:
        system("cls");
        option1(csv);
        break;
      case 2:
        system("cls");
        option2(csv);
        break;
      case 3:
        system("cls");
        cout<<"Goodbye\nHave a nice day.\n\n"<<endl;
        break;
    }
  }

  return 0;
}

void option2(CSV* csv){
  string DBN;
  vector<string> resultLine;
  CSV temp("temp", false);

  temp.append(csv->getHeader());

  system("cls");
  cout<<"Please type the DBN you want to search ( Case Sensitive ):\n"<<endl;
  fflush(stdin);
  cin>>DBN;

  resultLine = csv->findFirst(0, DBN);
  temp.append(resultLine);

  temp.PrintCSV();
  cout<<"\nPress Enter to continue . . ."<<endl;
  fflush(stdin);
  cin.ignore();
}

void option1(CSV* csv){
  string str;
  vector<vector<string>> result;
  CSV temp("temp", false);

  temp.append(csv->getHeader());

  system("cls");
  cout<<"Please type the Name you want to search ( Not Case Sensitive ):\n"<<endl;
  fflush(stdin);
  cin>>str;

  for (int i=0;i<str.length();i++) str[i] = toupper(str[i]);

  result = csv->find(1, str);
  temp.append(result);

  temp.sort(1);

  temp.PrintCSV();
  cout<<"\nPress Enter to continue . . ."<<endl;
  fflush(stdin);
  cin.ignore();

  int opcao = -1;
  cout<<"Save this result?\n"<<endl;
  cout<<"1-Yes\n2-No\n"<<endl;
  fflush(stdin);
  cin>>opcao;

  switch(opcao){
    case 1:
      str = "";
      cout<<"Please type the file name (do not type the file extension eg: .csv).\n"<<endl;
      cin>>str;
      temp.setFilePath("output/"+str+".csv");
      temp.save();
      break;
    default:
      break;
  }
}
