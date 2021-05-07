#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 初始化一个空的vector容器
    vector<char> values;
    // 向values容器尾部依次添加数据
    values.push_back('S');
    values.push_back('T');
    values.push_back('L');

    // 查看容量
    cout << "元素个数为: " << values.size() << endl;

    // 遍历容器
    for (auto i = values.begin(); i < values.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    // 向容器开头插入字符
    values.insert(values.begin(), 'C');
    cout << "首个元素为: " << values.at(0) << endl;
}