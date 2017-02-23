#include <iostream>
#include "genfilestream.hh"
#include "input.hh"

int main(int, char* argv[])
{
  auto outputEnv = output(argv[1]);
  auto mystream = outputEnv.getstream(0);
  mystream << "Test\n";
  mystream.close();
  std::cout << "Test.\n";

  input i;
}
