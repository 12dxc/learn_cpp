#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void elimDups(vector<string> &vs)
{
    std::sort(vs.begin(), vs.end());
    auto new_end = std::unique(vs.begin(), vs.end());
    vs.erase(new_end, vs.end());
}

void biggies_stable_partition(std::vector<std::string> &vs, std::size_t sz)
{
    elimDups(vs);

    auto pivot = stable_partition(vs.begin(), vs.end(), [sz](const std::string &s)
                                  { return s.size() >= sz; });

    for (auto it = vs.cbegin(); it != pivot; ++it)
        std::cout << *it << " ";
}
int main()
{
    vector<string> v{
        "1234", "1234", "1234", "hi~", "alan", "alan", "cp"};
    cout << "大于等于3的非重复字符串: ";
    biggies_stable_partition(v, 3);
    cout << endl;

    return 0;
}