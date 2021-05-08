#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

/**
 * pop_back()
 * 移除容器尾部的一个元素
 */
void usePopBack()
{
    deque<int> d{1, 2, 3, 4, 5};
    d.pop_back();

    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }
}

/**
 * iterator erase (pos);
 * 移除一个元素或某一区域内的多个元素
 */
void useErase()
{
    deque<int> d{1, 2, 3, 4, 5};
    auto iter = d.erase(d.begin() + 1); // 删除元素2

    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }
    // iter迭代器指向元素 3
    cout << endl << *iter << endl;
}

/**
 * iterator erase (iterator first, iterator last);
 * 删除 deque 容器中位于迭代器 [first,last)指定区域内的所有元素，并返回指向被删除区域下一个位置元素的迭代器
 */
void eraseRange()
{
    deque<int> d{1, 2, 3, 4, 5};
    // 删除2、3
    auto iter = d.erase(d.begin() + 1, d.end() - 2);

    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }

    cout << endl;
}

/**
 * swap() pop_back()
 * 如果不在意容器中元素的排列顺序，可以结合 swap() 和 pop_back() 函数，同样可以实现删除容器中指定位置元素的目的
 * 先调用 swap() 函数交换要删除的目标元素和容器最后一个元素的位置，然后使用 pop_back() 删除该目标元素
 */
void useSwap()
{
    deque<int> d{1, 2, 3, 4, 5};
    // 交换要删除元素和最后一个元素的位置
    swap(*(begin(d) + 1), *(end(d) - 1)); // 等同于swap(d[1], d[4])

    // 交换位置后的d容器
    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }
    cout << endl;

    d.pop_back();
    // 输出d容器中剩余的元素
    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }
    cout << endl;
}

/**
 * remove()
 * 删除容器中所有和指定元素值相等的元素，并返回指向最后一个元素下一个位置的迭代器
 *
 * 注意，在对容器执行完 remove() 函数之后，由于该函数并没有改变容器原来的大小和容量，因此无法使用之前的方法遍历容器，而是需要向程序中那样，借助 remove() 返回的迭代器完成正确的遍历
 *
 * remove() 的实现原理是，在遍历容器中的元素时，一旦遇到目标元素，就做上标记，然后继续遍历，直到找到一个非目标元素，即用此元素将最先做标记的位置覆盖掉，同时将此非目标元素所在的位置也做上标记，等待找到新的非目标元素将其覆盖。因此，如果将上面程序中 demo 容器的元素全部输出，得到的结果为 1 4 5 4 3 5
 *
 * remove()用于删除容器中指定元素时，常和 erase() 成员函数搭配使用
 */
void useRemove()
{
    deque<int> d{1, 3, 3, 4, 3, 5};
    auto iter = remove(d.begin(), d.end(), 3);

    // 输出剩余的元素
    for (auto first = d.begin(); first < iter; first++) {
        cout << *first << " ";
    }
}

/**
 * clear()
 * 删除 deque 容器中所有的元素，使其变成空的 deque 容器
 */
void useClear()
{
    deque<int> d{1, 2, 3, 4, 5};
    d.clear();
}

int main()
{
    usePopBack();
    useErase();
    eraseRange();
    useSwap();
    useRemove();
    useClear();
}