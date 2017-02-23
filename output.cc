#include "output.hh"

solution::print_solution(std::ofstream& ofs)
{
  int nb_solu = 0;
  for (auto& a: data)
    if (!a.is_empty())
      nb_solu++;
  ofs << nb_solu << '\n';
  for (size_t i = 0; i < data.size(); ++i)
  {
    if (!data[i].is_empty())
    {
      ofs << i;
      for (auto video: data[i])
        ofs << ' ' << video;
      ofs << '\n';
    }
  }
}
