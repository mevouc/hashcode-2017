#pragma once

#include <map>
#include <vector>

#include "input.hh"

using namespace std;

struct cachediff
{
  cache c;
  int diff;
};

vector<set<cachediff>> sortcaches(vector<endpoint> endpoints);
