#include <iostream>
#include <set>
#include <string>

using namespace std;

// 定义函数对象类
class cmp1
{
public:
    // 重载 () 运算符
    bool operator()(const string &a, const string &b)
    {
        // 按照字符串的长度，做升序排序（即存储的字符串从短到长）
        return a.length() < b.length();
    }
};

// 定义函数对象模板类
template <typename T>
class cmp2 {
public:
    // 重载 () 运算符
    bool operator()(const T &a, const T &b) {
        // 按照值的大小，做升序排序
        // 注意，此方式必须保证 T 类型元素可以直接使用关系运算符（比如这里的 < 运算符）做比较
        return a < b;
    }
};

/**
 * 使用函数对象自定义排序规则
 *
 * 需要注意的是，此程序中创建的 mySet 容器，由于是以字符串的长度为准进行排序，因此其无法存储相同长度的多个字符串
 */
void functionObject()
{
    // 创建set容器，并使用自定义的cmp排序规则
    set<string, cmp2<string>> mySet{"ab", "abc", "a"};

    // 遍历容器中的元素
    for (auto iter = mySet.begin(); iter != mySet.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main()
{
    functionObject();
}