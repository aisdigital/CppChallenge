#include <bits/stdc++.h>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;


vector<vector<string> > store_csv() {
  fstream fin;
	fin.open("./build/CppChallenge/input/SAT__College_Board__2010_School_Level_Results.csv", ios::in);

  string line;
  vector<string> v1;
  vector<vector<string> > v2;

  while(getline(fin, line)) {
      stringstream ss(line);
      string word;

      v1.clear();

      while (getline(ss, word, ',')) {
        v1.push_back(word);
      }

      v2.push_back(v1);
  }
  return v2;
}

int user_options() {
  int opc;

  cout << "-=-=-=-MENU-=-=-=-" <<  endl;
  cout << "1- Search by name" << endl;
  cout << "2- Search by DBN" << endl;
  cout << "3- Exit program" << endl;

  cin >> opc;

  return opc;
}

vector<string> search_by(vector<vector<string> > v, string &ss, string opc) {
  vector<string> ans = {"Empty results!"};

  if (opc.compare("school_name") == 0)
    for (auto y: v)
      for (auto x: y)
        if (x.compare(ss) == 0) {
          vector<string> tempaux = y;
          sort(tempaux.begin(), tempaux.end());
          return tempaux;
        }

  if (opc.compare("dbn") == 0)
    for (auto y: v)
        if (y[0].compare(ss) == 0)
          return y;

  return ans;
}

void create_csv(string ans, vector<string> vect) {
  mkdir("output", 0777);

  string filename;
  filename = "./output/" + ans + ".csv";

  ofstream fout(filename);

  for (auto x: vect)
    fout << x << ", ";
  fout << "\n";

  fout.close();
}

void show_result(vector<string> vect) {
  for (auto x: vect)
    cout << x << " ";
  cout << endl;
}

void save_results(vector<string> vect) {
  string ans;
  cout << "Want to save result? [Y/N] " << endl;
  cin >> ans;

  if (ans.compare("Y") == 0 || ans.compare("y") == 0) {
    cout << "Filename, without extension: " << endl;
    cin >> ans;

    create_csv(ans, vect);

  }
  else if (ans.compare("N") == 0 || ans.compare("n") == 0){
    cout << "Ok! Results were printed above. \n" << endl;
  }
}

void search_name(vector<vector<string> > v) {
  string ss;

  // Temp_string created to deal with '\n' bug
  string temp_string;

  getline(cin, temp_string);
  cout << "Input a string to search by School Name:" << endl;
  getline(cin, ss);

  vector<string> vect = search_by(v, ss, "school_name");

  show_result(vect);

  if (vect.size() > 1) {
    save_results(vect);
  }
}

void search_dbn(vector<vector<string> > v) {
  string ss;

  cout << "Input a string to search by DBN: " << endl;
  cin >> ss;

  vector<string> vect = search_by(v, ss, "dbn");

  show_result(vect);
}

int main(int argc, const char * argv[]) {
  vector<vector<string> > v = store_csv();
  int choice;

  while (choice = user_options(), choice != 3)
  {
    switch (choice)
    {
      case 1:
        search_name(v);
        break;
      case 2:
        search_dbn(v);
        break;
      case 3:
        cout << "Exiting..." << endl;
        break;
      default:
        break;
    }
  }
  return 0;
}
