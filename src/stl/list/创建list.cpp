#include <iostream>
#include <array>
#include <list>

using namespace std;

int main()
{
    // 创建一个没有任何元素的空list容器
    list<int> values1;

    // 创建一个包含n个元素的list容器
    list<int> values2(10); // 包含10个元素，默认值为0

    // 创建一个包含n个元素的list容器，并为每个元素指定初始值
    list<int> values3(10, 5); // 包含10个元素，默认值为5

    // 在已有list容器的情况下，通过拷贝该容器可以创建新的list容器，须保证新旧容器元素类型一致
    list<int> values4(10);
    list<int> values5(values4);

    // 通过拷贝其他类型容器（或者普通数组）中指定区域内的元素，可以创建新的list容器
    // 拷贝普通数组，创建list容器
    int a[] = {1, 2, 3, 4, 5};
    list<int> values6(a, a + 5);

    // 拷贝其他类型的容器，创建list容器
    array<int, 5> arr{11, 12, 13, 14, 15};
    list<int> values7(arr.begin() + 2, arr.end()); // 拷贝arr容器中的{13,14,15}
}