/**
 * forward_list 容器具有和 list 容器相同的特性，即擅长在序列的任何位置进行插入元素或删除元素的操作
 * 但对于访问存储的元素，没有其它容器（如 array、vector）的效率高
 *
 * 由于单链表没有双向链表那样灵活，因此相比 list 容器，forward_list 容器的功能受到了很多限制
 * 比如，由于单链表只能从前向后遍历，而不支持反向遍历，因此 forward_list 容器只提供前向迭代器，而不是双向迭代器
 * 这意味着，forward_list 容器不具有 rbegin()、rend() 之类的成员函数
 *
 * 由于forward_list 容器底层使用单链表，存储相同个数的同类型元素，单链表耗用的内存空间更少，空间利用率更高，并且对于实现某些操作单链表的执行效率也更高
*/

#include <iostream>
#include <array>
#include <iterator>
#include <forward_list>

using namespace std;

/**
 * 创建forward_list
 */
void initList()
{
    // 创建一个没有任何元素的空forward_list容器
    forward_list<int> values1;

    // 创建一个包含n个元素的forward_list容器
    forward_list<int> values2(10); // 包含10个元素，默认值为0

    // 创建一个包含n个元素的forward_list容器，并为每个元素指定初始值
    forward_list<int> values3(10, 5); // 包含10个元素，默认值为5

    // 在已有forward_list容器的情况下，通过拷贝该容器可以创建新的forward_list容器，须保证新旧容器元素类型一致
    forward_list<int> values4(10);
    forward_list<int> values5(values4);

    // 通过拷贝其他类型容器（或者普通数组）中指定区域内的元素，可以创建新的forward_list容器
    // 拷贝普通数组，创建forward_list容器
    int a[] = {1, 2, 3, 4, 5};
    forward_list<int> values6(a, a + 5);

    // 拷贝其他类型的容器，创建forward_list容器
    array<int, 5> arr{11, 12, 13, 14, 15};
    forward_list<int> values7(arr.begin() + 2, arr.end()); // 拷贝arr容器中的{13,14,15}
}

/**
 * 向forward_list中添加元素
 * before_begin() 返回一个前向迭代器，其指向容器中第一个元素之前的位置
 */
void add()
{
    forward_list<int> values{1, 2, 3};
    values.emplace_front(0); // {0,1,2,3}
    values.emplace_after(values.before_begin(), -1); // // {-1,0,1,2,3}

    for (auto it = values.begin(); it != values.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

/**
 * 获取forward_list的容量
 * forward_list 容器中是不提供 size() 函数的，但如果想要获取 forward_list 容器中存储元素的个数，可以使用头文件 <iterator> 中的 distance() 函数
 */
void size()
{
    forward_list<int> values{1, 2, 3, 4, 5};
    int count = distance(begin(values), end(values));
    cout << count << endl;
}

/**
 * advance() 移动迭代器
 * forward_list 容器迭代器的移动除了使用 ++ 运算符单步移动，还能使用 advance() 函数
 */
void move()
{
    forward_list<int> values{1, 2, 3, 4};
    auto it = values.begin();
    advance(it, 2);
    while (it != values.end()) {
        cout << *it << " ";
        it++;
    }
}

int main()
{
    add();
    size();
    move();
}