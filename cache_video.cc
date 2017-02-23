#include "cache_video.hh"
#include "users.hh"
#include <algorithm>

vector<vector<videoscore>> compute_cachevideo(const input& in)
{
  vector<vector<videoscore>> result(in.c);
  for (size_t i = 0; i < in.c; ++i)
  {
    result.resize(in.video_size.size());
    for (size_t j = 0; j < in.video_size.size(); ++j)
      result[i][j] = videoscore{int(j), 0};
  }
  auto user_diff = sortcaches(in.endpoints);
  for (auto& request: in.requests)
  {
    auto end = request.re;
    auto caches = user_diff[end];
    auto begin = caches.begin();
    if (begin != caches.end())
    {
      result[begin->c.c][request.rv].score += request.rn * begin->diff;
    }
  }
  for (auto& res: result)
    std::sort(res.begin(), res.end(), videoscore_cmp{});
  return result;
}
