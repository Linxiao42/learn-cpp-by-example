#include <iostream>
#include <array>

using namespace std;

// 使用begin()/end()遍历
void traverse1(array<int, 5> &arr)
{
    auto first = arr.begin();
    auto last = arr.end();

    // 与此同时，还可以使用全局的begin()和end()函数从容器中获取构造器
    // auto first = std::begin(arr);
    // auto last = std::end(arr);

    // 遍历容器中的元素
    while (first != last) {
        cout << *first << " ";
        ++first;
    }
    cout << endl;
}

// 使用cbegin()/cend()遍历,遍历过程中无法修改元素
void traverse2(array<int, 5> &arr)
{
    auto first = arr.cbegin();
    auto last = arr.cend();

    // 由于*first为const类型，所以不能用来修改元素
    // *first = 10;

    // 遍历容器中的元素
    while (first != last) {
        // 可以使用const类型迭代器访问元素
        cout << *first << " ";
        ++first;
    }
    cout << endl;
}

// 使用rbegin()/rend()遍历
void traverse3(array<int, 5> &arr)
{
    auto first = arr.rbegin();
    auto last = arr.rend();

    while (first != last) {
        cout << *first << " ";
        // 在反向迭代器上使用++递增运算符，会让迭代器进行逆向移动
        ++first;
    }
    cout << endl;
}

// 使用crbegin()/crend()遍历
// 与rbegin()/rend()唯一的区别是，前者返回的迭代器为const类型，即不能用来修改容器中的元素
void traverse4(array<int, 5> &arr)
{
    auto first = arr.crbegin();
    auto last = arr.crend();

    while (first != last) {
        cout << *first << " ";
        ++first;
    }
    cout << endl;
}

// 也可以使用for循环，完成以上几种方式的遍历
void traverse5(array<int, 5> &arr)
{
    for (auto first = arr.rbegin(); first != arr.rend(); first++) {
        cout << *first << " ";
    }
    cout << endl;
}

int main()
{
    array<int, 5> values{1, 2, 3, 4, 5};
    traverse1(values);
    traverse2(values);
    traverse3(values);
    traverse4(values);
    traverse5(values);
}
