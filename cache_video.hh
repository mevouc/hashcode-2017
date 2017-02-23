#pragma once
#include "input.hh"

struct videoscore
{
  int videoId;
  int score;
};

struct videoscore_cmp
{
  bool operator()(const videoscore& lhs, const videoscore& rhs) const
  {
    return lhs.diff > rhs.diff;
  }
};

vector<set<videoscore, videoscore_cmp>> compute_cachevideo(const input& in);
