#include "output.hh"
#include "cache_video.hh"
#include <algorithm>

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

int solution::compute_score()
{
    unsigned long long num;
    unsigned long long denum;
    for (auto request : in.requests)
    {
        denum += request.rn;
        unsigned gain = 0;
        for (auto cache : in.endpoints[request.re].cache_servers)
        {
            auto vid_in_cache = std::find(data[cache.c].v.begin(),
                    data[cache.c].v.end(), request.rv);
            if (vid_in_cache != data[cache.c].v.end())
            {
                unsigned diff = (in.endpoints[request.re].ld - cache.lc);
                gain = gain < diff ? gain : diff;
            }
        }
        num += gain;
    }
    return (num / denum * 1000);  
}

void solution::format_solution(vector<vector<videoscore>> caches)
{
  for (unsigned i = 0; i < data.size(); ++i)
  {
    for (auto& videoscore : caches.at(i))
    {
      if (videoscore.score == 0)
        break;
      else
        add_video(videoscore.videoId, i);
    }
  }
}
