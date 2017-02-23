#include <set>
#include <vector>

#include "input.hh"
#include "users.hh"

using namespace std;

vector<set<cachediff, cachediff_cmp>> sortcaches(vector<endpoint> endpoints)
{
  auto sorted = vector<set<cachediff, cachediff_cmp>>(endpoints.size());

  for (auto& endpoint : endpoints)
  {
    auto cachemap = set<cachediff, cachediff_cmp>(cachediff_cmp());

    for (auto& cache_server : endpoint.cache_servers)
    {
      cachediff cd;
      cd.c = cache_server;
      cd.diff = endpoint.ld - cache_server.lc;
    }

    sorted.push_back(cachemap);
  }

  return sorted;
}
