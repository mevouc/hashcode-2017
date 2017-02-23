#pragma once
#include <set>
#include "input.hh"

using namespace std;
struct videoscore
{
  int videoId;
  int score;
};

struct videoscore_cmp
{
  bool operator()(const videoscore& lhs, const videoscore& rhs) const
  {
    return lhs.score > rhs.score;
  }
};
vector<vector<videoscore>> compute_cachevideo(const input& in);
