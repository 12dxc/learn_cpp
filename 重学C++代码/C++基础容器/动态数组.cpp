#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// vector可动态扩充数组的空间，但并非是追加一个元素就扩容一个，而是有自己的扩容逻辑
	vector<int> v = {1, 2, 3, 4, 5};
	v.push_back(6);				   // 尾插
	v.pop_back();				   // 尾删，无需参数
	v.insert(v.end()--, 100);	   // 指定位置插入
	v.erase(v.begin(), v.end()-3); // 指定位置删除
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl; // 打印总长度

	return 0;
}