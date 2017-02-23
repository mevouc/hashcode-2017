#include "output.hh"

void solution::print_solution(std::ofstream& ofs)
{
  int nb_solu = 0;
  for (auto& a: data)
    if (!a.v.empty())
      nb_solu++;
  ofs << nb_solu << '\n';
  for (size_t i = 0; i < data.size(); ++i)
  {
    if (!data[i].v.empty())
    {
      ofs << i;
      for (auto video: data[i].v)
        ofs << ' ' << video;
      ofs << '\n';
    }
  }
}

bool solution::add_video(int video, int cache)
{
  if (in.video_size[video] + data[cache].used <= in.x)
  {
    data[cache].v.push_back(video);
    data[cache].used += in.video_size[video];
    return true;
  }
  return false;
}
