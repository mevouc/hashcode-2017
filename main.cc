#include <iostream>
#include "genfilestream.hh"
#include "input.hh"
#include "output.hh"

int main(int, char* argv[])
{
  auto i = parse_input();
  auto o = output(argv[1]);
  auto ofs = o.getstream(sol.compute_score());

  auto sol = solution(i);
  sol.format_solution(compute_cachevideo(i));
  sol.print_solution(ofs);
}
