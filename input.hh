#pragma once

#include <vector>

using namespace std;

struct cache
{
  unsigned c; // id
  unsigned lc; // endpoint -> cache latency
};

struct endpoint
{
  unsigned ld; // datacenter -> endpoint latency
  vector<cache> cache_servers;
};

struct request
{
  unsigned rv;
  unsigned re;
  unsigned rn; // nb of requests
};

struct input
{
  unsigned c; // nb of cache servers
  unsigned x; // capacity of cache server

  vector<unsigned> video_size;
  vector<endpoint> endpoints;
  vector<request> requests;
};
