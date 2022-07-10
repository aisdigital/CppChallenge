# TODO

Challenge described at [README.md](README.md).

## Tasks

### Infra
 * [x] Install `C++` and `CMake`
 * [x] Install `gtest`

### Challenge
 * [x] Create Class to represent each School Level Result
 * [ ] Create CSV Reader
   * [x] Create Function ReadCSV
   * [x] Create Tests using gtest
 * [ ] Create Parser from CSV line format to School Model
   * [ ] Create Test using gtest
 * [ ] Create Search by DBN method
 * [ ] Create UNIT Test for Search by DBN
 * [ ] Create Search by School Name Method
 * [ ] Create UNIT Test for Search by School
 * [ ] Create CLI interface
 * [ ] Create CSV File Writer

### Code Quality
 * [ ] Create a lib
   * [ ] Split hpp into header + source
   * [ ] Change CMakeList files
 * [ ] Cmake Custom roles
   * [ ] Add cmake-format linter
   * [ ] Add cppcheck linter
   * [ ] Add flawfinder linter
 * [ ] Add precommit to ensure calling linters before each commit
 * [ ] Add gitaction to ensure testing inside github