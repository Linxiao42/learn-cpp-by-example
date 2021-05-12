/**
 * 无论是用 emplace() 还是 emplace_hint()，都比 insert() 方法的效率高
 *
 * 原因很简单，它们向 map 容器插入键值对时，底层的实现方式不同：
 *    使用 insert() 向 map 容器中插入键值对的过程是，先创建该键值对，然后再将该键值对复制或者移动到 map 容器中的指定位置
 *    使用 emplace() 或 emplace_hint() 插入键值对的过程是，直接在 map 容器中的指定位置构造该键值对
 *
 * 也就是说，向 map 容器中插入键值对时，emplace() 和 emplace_hint() 方法都省略了移动键值对的过程，因此执行效率更高
 */
#include <iostream>
#include <map>

using namespace std;

class Test
{
public:
    Test(int n) : num(n)
    {
        cout << "调用构造函数" << endl;
    }

    Test(const Test &other) : num(other.num)
    {
        cout << "调用拷贝构造函数" << endl;
    }

    Test(Test &&other) : num(other.num)
    {
        cout << "调用移动构造函数" << endl;
    }

private:
    int num;
};


int main()
{
    map<string, Test> myMap;

    cout << "insert():" << endl;
    myMap.insert({"a", Test(1)});

    /*
    insert代码其实可以分解为以下三步
    构造类对象
    Test t{1};
    构造键值对
    auto p = make_pair("a", t); // 调用1次移动构造函数
    完成插入操作
    myMap.insert(p); // 调用1次移动构造函数
    */

    cout << "emplace():" << endl;
    myMap.emplace("b", 2);

    cout << "emplace_hint():" << endl;
    myMap.emplace_hint(myMap.begin(), "c", 3);
}