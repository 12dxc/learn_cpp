#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
     vector<string> score = {"F", "D", "C", "B", "A", "A++"};
     string letter;

     for (int i; cin >> i;)
     {
          i < 60 ? letter = score[0] : letter = score[(i - 50) / 10];

          cout << letter << endl;
     }

     system("pause");
     return 0;
}
