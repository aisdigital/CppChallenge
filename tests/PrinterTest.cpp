#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

#include "Printer.h" 

class PrinterTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Redirect cout
        coutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(outputStream.rdbuf());

        // Redirect cin
        cinBuffer = std::cin.rdbuf();
        std::cin.rdbuf(inputStream.rdbuf());
    }

    void TearDown() override {
        // Restore streams
        std::cout.rdbuf(coutBuffer);
        std::cin.rdbuf(cinBuffer);
    }

    std::stringstream outputStream;
    std::streambuf* coutBuffer;
    std::stringstream inputStream;
    std::streambuf* cinBuffer;
};

TEST_F(PrinterTest, loadingTest) {
    Printer menu;
    menu.printLoading();

	const std::string output = outputStream.str();
    EXPECT_NE(output.find("Welcome"), std::string::npos);
    EXPECT_NE(output.find("load"), std::string::npos);
    EXPECT_NE(output.find("data"), std::string::npos);
}

TEST_F(PrinterTest, mainTest) {
    inputStream << "1\n";

    Printer menu;
    auto returnValue = menu.printMain();

	EXPECT_EQ(returnValue, 1);
	// Test printed output below
	auto lines = std::count(std::istreambuf_iterator<char>(outputStream), 
							std::istreambuf_iterator<char>(), '\n');
	lines += 1;

	EXPECT_GE(lines,5);

	outputStream.seekg(0);
	std::string output;
	for(int i = 0; i < lines; ++i) {
		std::getline(outputStream, output);

		if(i == 1) {
			EXPECT_NE(output.find("Select"), std::string::npos);
		} else if(i == 2) {
			EXPECT_NE(output.find("Search"), std::string::npos);
			EXPECT_NE(output.find("name"), std::string::npos);
		} else if(i == 3) {
			EXPECT_NE(output.find("Search"), std::string::npos);
			EXPECT_NE(output.find("DBN"), std::string::npos);
		} else if(i == 4) {
			EXPECT_NE(output.find("Exit"), std::string::npos);
		}
	}
}

TEST_F(PrinterTest, searchByDbnTest) {
    inputStream << "123456789\n";

    Printer menu;
    std::string dbn = menu.printSearchByDbn();

    std::string expectedOutput = "\nType DBN and press Enter: ";
    EXPECT_EQ(outputStream.str(), expectedOutput);
    EXPECT_EQ(dbn, "123456789");
}

TEST_F(PrinterTest, searchByNameTest) {
    inputStream << "Test School\n";

    Printer menu;
    std::string name = menu.printSearchByName();

    std::string expectedOutput = "\nType the school name and press Enter: ";
    EXPECT_EQ(outputStream.str(), expectedOutput);
    EXPECT_EQ(name, "Test School");
}

