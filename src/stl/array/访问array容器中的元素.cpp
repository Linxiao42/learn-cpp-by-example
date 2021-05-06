#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 5> values{1, 2, 3, 4, 5};

    // 不做边界检查的访问
    values[4] = 100;

    // 为了避免越界访问，可使用at()函数
    // 功能与上一句代码相同，只是当传入给at()的索引是一个越界值时，程序会抛出std::out_of_range异常
    values.at(4) = 100;

    // 通过get<n>模板函数获取容器的第n个元素，需要注意的是n必须是一个在编译时可以确定的常量表达式
    cout << get<3>(values) << endl;
    // cout << get<5>(values) << endl; // 越界，会发生编译错误

    // 通过data()获得指向容器首个元素的指针，通过该指针，我们可以获得容器中的各个元素
    cout << *(values.data() + 4) << endl;

    // 通过size()函数，获取array的元素个数
    cout << "values size: " << values.size() << endl;

    // 通过empty()函数，判断array是否为空
    if (values.empty()) {
        cout << "The container has no elements.\n";
    } else {
        cout << "The container has " << values.size() << " elements.\n";
    }
}
