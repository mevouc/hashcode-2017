#include <fstream>
#include <iostream>
#include <numeric>
#include <chrono>

struct output
{
  output(const std::string& env) : env(env)
  {
  }
  std::ofstream getstream(int score)
  {
    std::ofstream myfile;
    myfile.open(env + "/score:" + std::to_string(score) + "_submision:" + std::to_string(counter++));
    return myfile;
  }
  std::string env;
  int counter = 0;
};
