#include <string>

#include "Application.h"
#include "FileReader.h"
#include "FileWriter.h"

using std::string;

Application::Application(string inputFile) : m_inputFile{ inputFile } {}

void Application::execute()
{
    FileReader reader;

    interface.showMessage("Reading data from \""+m_inputFile+"\"");

    if( ! reader.openFile(m_inputFile))
    {
        interface.showError("Could not open input file");
        return;
    }

    if( ! manager.addData(reader.getLines()))
    {  
        interface.showMessage("Could not load all data from file, do you wish to continue?");
        if(interface.getUserOption({"Yes", "No"}) == 1)
            return;
    }

    runMainLoop();
}

void Application::runMainLoop()
{
    bool exit = false;
    int userOption;

    while (!exit)
    {
        interface.reset();
        printMainMenu();

        userOption = interface.getUserOption({"1", "2", "3"});

        interface.reset();
        switch(userOption)
        {
            case 0:
                searchByName();
                break; 
            case 1:
                searchByDBN();
                break;
            case 2:
                exit = true;
                break;
        }
    }
}

void Application::printMainMenu()
{
    interface.showMessage("1 - Search results by School Name");
    interface.showMessage("2 - Search results by DBN");
    interface.showMessage("3 - Exit");
}

void Application::searchByName()
{
    string name;
    list<string>::iterator it;
    list<string> results;

    interface.showMessage("Enter school name:");
    
    name = interface.getUserString();

    interface.reset();
    interface.showMessage("Results:\n");

    results = manager.findByName(name);
    for(it=results.begin() ; it!=results.end() ; it++)
        interface.showMessage(*it);

    interface.showMessage("\nDo you wish to save this result to a file?");
    if (interface.getUserOption({"Yes", "No"}) == 0)
        storeResults(name, results);
}

void Application::storeResults(string name, list<string> &results)
{
    string fileName;
    list<string>::iterator it;
    FileWriter writer;
    interface.showMessage("Enter name of file:");
    
    fileName = interface.getUserString();

    writer.openFile(fileName);
    writer.writeLine("Results for name \""+name+"\":\n");

    for(it=results.begin() ; it!=results.end() ; it++)
        writer.writeLine(*it);
}

void Application::searchByDBN()
{
    string code;
    string result;

    interface.showMessage("Enter DBN:");
    
    code = interface.getUserString();

    interface.reset();
    interface.showMessage("Result:\n");

    result = manager.findByDBN(code);
    interface.showMessage(result+"\n");

    interface.waitUser();
}