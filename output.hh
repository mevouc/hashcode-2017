#pragma once

struct solution
{
  solution(const intput& in) : in(in), datas(in.C, {})
  {
  }

  input in;
  std::vector<std::vector<int>> data;
  int compute_score();
  void print_solution();
}
