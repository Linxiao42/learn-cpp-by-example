#include <iostream>
#include <deque>
#include <array>

using namespace std;

int main()
{
    // 创建一个没有任何元素的空deque容器
    deque<int> d1;

    // 创建一个具有n个元素的deque容器，其中每个元素都采用对应类型的默认值
    // 此行代码创建一个具有10个元素（默认都是0）的deque容器
    deque<int> d2(10);

    // 创建一个具有n个元素的deque容器，并为每个元素都指定初始值
    // 此行代码创建一个具有10个元素（默认都是5）的deque容器
    deque<int> d3(10, 5);

    // 在已有deque容器的情况下，可以通过拷贝该容器创建一个新的deque容器
    // 注意，新旧容器存储的元素类型须一致
    deque<int> d4(5);
    deque<int> d5(d4);

    // 通过拷贝其他类型容器中指定区域内的元素（也可以是普通数组），创建一个新容器
    // 拷贝普通数组，创建deque容器
    int a[] = {1, 2, 3, 4, 5};
    deque<int> d6(a, a + 5);
    // 适用于所有类型的容器
    array<int, 5> arr{1, 2, 3, 4, 5};
    deque<int> d7(arr.begin() + 2, arr.end()); // 拷贝arr容器中的{13,14,15}

}