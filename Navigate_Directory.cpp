#include <stdio.h>
#include<time.h>
#include<algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string.h>
#include <iterator>
#include <dirent.h>
#include <ctime>
#include <sys/stat.h>
using namespace std;
struct TFile {string name;time_t time;};
bool pred_time(const TFile& x, const TFile& y)
{
  return x.time < y.time;
}
int main()
{
  struct dirent *dirp;
  string filepath = "";
  string line     = "";
  vector< vector< vector<string> > > Data;
  vector<TFile> v;
  string dir = "./TestDir";
  DIR* dp    = opendir( dir.c_str() );
  if (dp != NULL)
  {
    while((dirp = readdir(dp)))
    {
      struct TFile filedata;
      struct stat filestat;

      filedata.name = dir + "/" + dirp->d_name;
      if(S_ISDIR(filestat.st_mode))
	continue;
      if (stat(filedata.name.c_str(), &filestat) >= 0 && strcmp(dirp->d_name, ".") != 0 && strcmp(dirp->d_name, "..") != 0)
      {
	filedata.time = filestat.st_mtime;
	v.push_back(filedata);
      }
    }
    closedir(dp);
  }
  sort(v.begin(),v.end(),pred_time);
  vector<TFile>::iterator it;
  for (it = v.begin(); it != v.end(); it++)
  {
    char datestring[256];
    time_t rawtime;
    time_t time = it->time;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    //strftime(datestring, sizeof(datestring), nl_langinfo(D_T_FMT), tm);
    //printf("%s %s\n", it->name, datestring);
  }
  return 0;
}
