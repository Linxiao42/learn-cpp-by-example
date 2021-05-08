#include <iostream>
#include <deque>

using namespace std;

/**
 * 通过下标访问
 * 需要注意的是，使用此方法需确保下标 n 的值不会超过容器中存储元素的个数，否则会发生越界访问的错误
 */
void useIndex()
{
    deque<int> d{1, 2, 3, 4, 5};
    cout << d[1] << endl;

    // 修改指定下标位置处的元素
    d[1] = 5;
    cout << d[1] << endl;
}

/**
 * 通过at()成员函数访问
 * 该函数会返回容器中指定位置处元素的引用形式，因此利用该函数的返回值，既可以访问指定位置处的元素，也可以对其进行修改
 * 此外，at() 成员函数会自行判定访问位置是否越界，如果越界则抛出std::out_of_range异常
 */
void useAt()
{
    deque<int> d{1, 2, 3, 4, 5};
    cout << d.at(1) << endl;
    d.at(1) = 5;
    cout << d.at(1) << endl;

    // 下面这条语句会抛出 out_of_range 异常
    // cout << d.at(10) << endl;
}

/**
 * 通过front()和back()成员函数访问
 * 分别返回 vector 容器中第一个和最后一个元素的引用，通过利用它们的返回值，可以访问（或修改）容器中的首尾元素
 */
void useFrontBack()
{
    deque<int> d{1, 2, 3, 4, 5};
    cout << "deque 首元素为：" << d.front() << endl;
    cout << "deque 尾元素为：" << d.back() << endl;
    // 修改首元素
    d.front() = 10;
    cout << "deque 新的首元素为：" << d.front() << endl;
    // 修改尾元素
    d.back() = 20;
    cout << "deque 新的尾元素为：" << d.back() << endl;
}

/**
 * 通过迭代器访问部分或多个deque中的元素
 */
void traverse()
{
    deque<int> d{1, 2, 3, 4, 5};
    // 从元素2开始遍历
    auto first = d.begin() + 1;
    // 遍历至5结束（不包括5）
    auto end = d.end() - 1;
    while (first < end) {
        cout << *first << " ";
        ++first;
    }
}

int main()
{
    useIndex();
    useAt();
    useFrontBack();
    traverse();
}