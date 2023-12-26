#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void ReadFileToVec(const string &fileName, vector<string> &v)
{
     ifstream ifs(fileName);
     while (ifs)
     {
          string buf;
          while (ifs >> buf)
          {
               v.push_back(buf);
          }
     }
}

int main()
{

     return 0;
}