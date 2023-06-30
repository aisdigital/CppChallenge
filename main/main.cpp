// Challenge C++ AISDigital
#include <iostream>
#include "application.hpp"

int main(int argc, const char *argv[])
{
  static constexpr auto ARG_POS = 1;


  if (argc < 2)
  {
    // No filepath inputed
    std::cout << "File path not found. Did you input the file path?" << std::endl;
    return EXIT_FAILURE;
  }

  Application app;

  if (app.setup(argv[ARG_POS]))
  {
    app.run();
  }
  else
  {
    std::cout << "Failed to load file " << argv[1] << ". Verify if the file exists or is in the correct CSV format." << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
