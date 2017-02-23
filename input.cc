#include <iostream>
#include "input.hh"

using namespace std;

input parse_input()
{
  input in;
  unsigned v, e, r;
  cin >> v;
  cin >> e;
  cin >> r;
  cin >> in.c;
  cin >> in.x;

  unsigned size;
  for (size_t i = 0; i < v; ++i)
  {
    cin >> size;
    in.video_size.push_back(size);
  }
  for (size_t i = 0; i < e; ++i)
  {
    endpoint e;
    unsigned k;
    cin >> e.ld;
    cin >> k;
    for (size_t j = 0; j < k; ++j)
    {
      cache c;
      cin >> c.c;
      cin >> c.lc;
      e.cache_servers.push_back(c);
    }
  }
  for (size_t i = 0; i < r; ++i)
  {
    request r;
    cin >> r.rv;
    cin >> r.re;
    cin >> r.rn;
    in.requests.push_back(r);
  }
  return in;
}
