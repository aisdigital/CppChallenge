# TODO

Challenge described at [README.md](README.md).

## Tasks

### Infra
 * [x] Install `C++` and `CMake`
 * [x] Install `gtest`

### Challenge
 * [x] Create Class to represent each School Level Result
 * [x] Create CSV Reader
   * [x] Create Function ReadCSV
   * [x] Create Tests using gtest
 * [x] Create Parser from CSV line format to School Model
   * [x] Create Test using gtest
   * [x] Create ToString method
 * [x] Create Parser from SchoolSatResult line format to CSV line
   * [x] Create Test using gtest
   * [x] Create ToSchoolSatResult method
 * [x] Create Parser from string list to SchoolSatResult hash list
 * [x] Create Search by DBN method
   * [x] Create UNIT Test for Search by DBN
 * [x] Create Search by School Name Method
   * [x] Create UNIT Test for Search by School
 * [x] Create CLI interface
   * [x] Create basic CLI inside main
 * [x] Create CSV File Writer
   * [x] Create FileUtils::WriterCSV
   * [x] Add option to export to file inside CLI
 * [ ] Change Search by School to return list with similar School's Names
   * [ ] Change method `Database::FindBySchoolName`
   * [ ] Add `CLI::Draw` method for list
   * [ ] Change `main.cpp`

### Code Quality
 * [ ] Add Doxygen to generate documentation
   * [ ] Create Doxyfile
   * [ ] Create CMake Custom Target `doc`
 * [ ] Create a lib
   * [ ] Split hpp into header + source
   * [ ] Change CMakeList files
 * [ ] Cmake Custom target `lint`
 * [x] Add precommit to ensure calling linters before each commit
   * [x] Add cppcheck linter
   * [x] Add clang-format
   * [ ] Add flawfinder linter
 * [ ] Add gitaction to ensure testing inside github
