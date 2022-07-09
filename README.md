# C++ Challenge

AIS C++ Challenge

Hey, what's up? Are you ready to start the challenge? We would like to remember that this step will help us evaluate your performance. Take a deep breath and let’s go!
We’re rooting for you. 😁

## Some Rules

1 - **DO NOT** share your answer with others.

2 - Remember that this challenge it's meant to evaluate your skills, you don't necessarily have to finish **all** the challenge code implementation, we just want to get to know you better. 😁

## Steps

- Fork the repository.
- Create a branch (from master branch) with the following pattern:
  Use your name as branch's name, eg:
  Considering that my name is José da Silva the branch name should be: "feature/jose_silva"
- Work **only** on your branch, and after you finish, create a Pull Request targeting "master" branch on this repository.
- **DO NOT** change the reviewers of your Pull Request.

# Requirements 

* CMake installed

## Instructions
To run the project use basic `cmake` commands

*  `cmake . -B ./build`
*  `make -C ./build/ CppChallenge`
*  `./build/CppChallenge`

After setting it all up, let's go to the challenge \o/

## Challenge 

Given a CSV input file `./input/SAT__College_Board__2010_School_Level_Results.csv` what you have to do is:

Create a command-line application where you will:
* Read the CSV file and store the data in memory(data don't need to be ordered). (The read of the file can be done on a separate thread)
* After reading the file we should show the user 3 options in a menu and ask for a number where: 

1. **Search by name:** It will ask the user to input a string and it will search by **School Name** and show on the screen the results(results should be sorted by name). Asking if the user wants to save the results on a **CSV** file where if yes ask the file name(you should store it in a directory called `output`), save it into a file and return to menu.

2. **Search by DBN:** It will ask the user to input a string and it will search by **DBN** and show on the screen the result. The DBN is unique so you are allowed to create additional logic to optimize the search. After that return to the menu.

3. Exit the program.


* It is not required, unit tests using [gtest](https://github.com/google/googletest) on the 2 search methods are a bonus!


Happy Coding! 
