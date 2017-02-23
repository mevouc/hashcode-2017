#include <iostream>
#include "genfilestream.hh"
#include "input.hh"
#include "output.hh"
#include "cache_video.hh"

int main(int, char* argv[])
{
  auto i = parse_input();

  auto sol = solution(i);
  sol.format_solution(compute_cachevideo(i));

  auto o = output(argv[1]);
  auto ofs = o.getstream(sol.compute_score());

  sol.print_solution(ofs);
}
