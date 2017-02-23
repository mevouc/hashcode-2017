#pragma once

#include <set>
#include <vector>

#include "input.hh"

using namespace std;

struct cachediff
{
  cache c;
  int diff;
};

struct cachediff_cmp
{
  bool operator()(const cachediff& lhs, const cachediff& rhs) const
  {
    return lhs.diff > rhs.diff;
  }
};

vector<set<cachediff, cachediff_cmp>> sortcaches(vector<endpoint> endpoints);
