#pragma once
#include "input.hh"
#include <fstream>

struct cache_capacity
{
  unsigned used; // used memory
  std::vector<int> v; //videos
};

struct solution
{
  solution(const input& in) : in(in), data(in.c)
  {
  }

  input in;
  std::vector<cache_capacity> data;
  int compute_score();
  void format_solution(vector<vector<videoscore>> caches);
  void print_solution(std::ofstream& ofs);

  bool add_video(int video, int cache);
};
