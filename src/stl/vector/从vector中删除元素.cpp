#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * pop_back()
 * 删除 vector 容器中最后一个元素，该容器的大小（size）会减 1，但容量（capacity）不会发生改变
 */
void usePopBack()
{
    vector<int> values{1, 2, 3, 4, 5};
    values.pop_back();

    // 输出values容器新的size
    cout << "size is: " << values.size() << endl;
    // 输出values容器新的容量
    cout << "capacity is: " << values.capacity() << endl;

    for (int i = 0; i < values.size(); i++) {
        cout << values[i] << " ";
    }
}

/**
 * iterator erase (pos);
 * 删除 vector 容器中 pos 迭代器指定位置处的元素，并返回指向被删除元素下一个位置元素的迭代器。该容器的大小（size）会减 1，但容量（capacity）不会发生改变
 */
void useErase()
{
    vector<int> values{1, 2, 3, 4, 5};
    auto iter = values.erase(values.begin() + 1); // 删除元素2
    // 输出values容器新的size
    cout << "size is:" << values.size() << endl;
    // 输入values容器新的容量
    cout << "capacity is:" << values.capacity() << endl;

    for (int i = 0; i < values.size(); i++) {
        cout << values[i] << " ";
    }
    // iter迭代器指向元素 3
    cout << endl << *iter << endl;
}

/**
 * swap() pop_back()
 * 如果不在意容器中元素的排列顺序，可以结合 swap() 和 pop_back() 函数，同样可以实现删除容器中指定位置元素的目的
 * 先调用 swap() 函数交换要删除的目标元素和容器最后一个元素的位置，然后使用 pop_back() 删除该目标元素
 */
void useSwap()
{
    vector<int> values{1, 2, 3, 4, 5};
    // 交换要删除元素和最后一个元素的位置
    swap(*(begin(values) + 1), *(end(values) - 1)); // 等同于swap(values[1], values[4])

    // 交换位置后的values容器
    for (int i = 0; i < values.size(); i++) {
        cout << values[i] << " ";
    }
    cout << endl;

    values.pop_back();
    // 输出values容器新的size
    cout << "size is:" << values.size() << endl;
    // 输入values容器新的容量
    cout << "capacity is:" << values.capacity() << endl;
    // 输出values容器中剩余的元素
    for (int i = 0; i < values.size(); i++) {
        cout << values[i] << " ";
    }
}

/**
 * iterator erase (iterator first, iterator last);
 * 删除 vector 容器中位于迭代器 [first,last)指定区域内的所有元素，并返回指向被删除区域下一个位置元素的迭代器。该容器的大小（size）会减小，但容量（capacity）不会发生改变
 */
void eraseRange()
{
    vector<int> values{1, 2, 3, 4, 5};
    // 删除2、3
    auto iter = values.erase(values.begin() + 1, values.end() - 2);
    cout << "size is:" << values.size() << endl;
    cout << "capacity is:" << values.capacity() << endl;

    for (int i = 0; i < values.size(); i++) {
        cout << values[i] << " ";
    }
}

/**
 * remove()
 * 删除容器中所有和指定元素值相等的元素，并返回指向最后一个元素下一个位置的迭代器。值得一提的是，调用该函数不会改变容器的大小和容量
 *
 * 注意，在对容器执行完 remove() 函数之后，由于该函数并没有改变容器原来的大小和容量，因此无法使用之前的方法遍历容器，而是需要向程序中那样，借助 remove() 返回的迭代器完成正确的遍历
 *
 * remove() 的实现原理是，在遍历容器中的元素时，一旦遇到目标元素，就做上标记，然后继续遍历，直到找到一个非目标元素，即用此元素将最先做标记的位置覆盖掉，同时将此非目标元素所在的位置也做上标记，等待找到新的非目标元素将其覆盖。因此，如果将上面程序中 demo 容器的元素全部输出，得到的结果为 1 4 5 4 3 5
 *
 * remove()用于删除容器中指定元素时，常和 erase() 成员函数搭配使用
 */
void useRemove()
{
    vector<int> values{1, 3, 3, 4, 3, 5};
    auto iter = remove(values.begin(), values.end(), 3);

    cout << "size is:" << values.size() << endl;
    cout << "capacity is:" << values.capacity() << endl;

    // 输出剩余的元素
    for (auto first = values.begin(); first < iter; first++) {
        cout << *first << " ";
    }
}

/**
 * clear()
 * 删除 vector 容器中所有的元素，使其变成空的 vector 容器。该函数会改变 vector 的大小（变为 0），但不是改变其容量
 */
void useClear()
{
    vector<int> values{1, 2, 3, 4, 5};
    values.clear();
    cout << "size is:" << values.size() << endl;
    cout << "capacity is:" << values.capacity() << endl;
}

int main()
{
    usePopBack();
    useErase();
    useSwap();
    eraseRange();
    useRemove();
    useClear();
}