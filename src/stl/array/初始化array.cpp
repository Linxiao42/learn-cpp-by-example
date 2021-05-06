#include <iostream>
#include <array>

using namespace std;

/**
 * 初始化array
 */
void initArray()
{
    // 所有元素初始化为0.0
    array<double, 10> values1{};

    // 也可以像创建常规数组那样对元素进行初始化
    // 只初始化前四个元素，剩余的元素都会被初始化为0.0
    array<double, 10> values2{0.5, 1.0, 1.5, 2.0};

    // 循环初始化array
    array<int, 5> values;
    int h = 1;
    auto first = values.begin();
    auto last = values.end();
    // 初始化values容器为{1,2,3,4,5}
    while (first != last) {
        *first = h;
        ++first;
        h++;
    }
}

/**
 * 遍历array
 */
void traverse()
{
    array<int, 4> values{};
    // 初始化values容器为{0,1,2,3}
    for (int i = 0; i < values.size(); i++) {
        values.at(i) = i;
    }

    // 使用get()重载函数输出指定位置的元素
    cout << get<3>(values) << endl;


    // 如果容器不为空，则输出容器中所有的元素
    if (!values.empty()) {
        for (auto val = values.begin(); val < values.end();val++) {
            cout << *val << " ";
        }
        cout << endl;
    }
}

int main()
{
    initArray();
    traverse();
}