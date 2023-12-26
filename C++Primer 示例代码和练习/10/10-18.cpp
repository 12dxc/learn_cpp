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
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words); // ��word���ֵ�����ɾ���ظ�����
    // ����������
    stable_sort(words.begin(), words.end(),
                [](const string &a, const string &b)
                { return a.size() < b.size(); });
    // ��ȡһ����������ָ���һ������size()>=sz��Ԫ��
    auto wc = partition(words.begin(), words.end(),
                        [sz](const string &a)
                        { return a.size() >= sz; });
    // ѭ����ӡ
    for_each(words.begin(), wc,
             [](const string &s)
             { std::cout << s << " "; });
}

int main()
{
    vector<string> v{
        "1234", "1234", "1234", "hi~", "alan", "alan", "cp"};
    cout << "���ڵ���3�ķ��ظ��ַ���: ";
    biggies(v, 3);
    cout << endl;

    return 0;
}