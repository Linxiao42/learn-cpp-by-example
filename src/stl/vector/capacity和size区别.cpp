/**
* vector 容器的容量（用 capacity 表示），指的是在不分配更多内存的情况下，容器可以保存的最多元素个数
* vector 容器的大小（用 size 表示），指的是它实际所包含的元素个数
*/

#include <iostream>
#include <vector>

using namespace std;

// 通过capacity()和size()展示容量和大小
void showCapacitySize()
{
    vector<int> values{1, 2, 3, 4, 5};
    // 使用reserve()函数可以增加容器的容量
    values.reserve(20);
    cout << "values的容量： " << values.capacity() << endl;
    cout << "values的大小： " << values.size() << endl;
}

/**
 * 展示容量自动增长
 * vector容器的大小不能超出它的容量，在大小等于容量的基础上，只要增加一个元素，就必须分配更多的内存，这里的更多不仅仅是一个
 * 一旦vector容器的内存被重新分配，则和vector容器中元素相关的所有引用、指针以及迭代器，都可能会失效，最稳妥的方法就是重新生成
 */
void showCapacityIncrease()
{
    vector<int> values{1, 2, 3, 4, 5};
    cout << "values的容量： " << values.capacity() << endl;
    cout << "values的大小： " << values.size() << endl;
    cout << "values的首地址： " << values.data() << endl;

    values.push_back(6);
    cout << "values的容量： " << values.capacity() << endl;
    cout << "values的大小： " << values.size() << endl;
    cout << "values的首地址： " << values.data() << endl;
}

/**
 * 修改vector容器的容量和大小
 * 通过 reserve() 成员函数增加容器的容量，其大小并没有改变
 * 通过 resize() 成员函数改变容器的大小，它的容量可能会发生改变
 * 需要注意的是，通过 resize() 成员函数减少容器的大小（多余的元素会直接被删除），不会影响容器的容量
 */
void changeCapacitySize()
{
    vector<int> values{1, 2, 3, 4, 5};
    cout << "values的容量(1)： " << values.capacity() << endl;
    cout << "values的大小(1)： " << values.size() << endl;

    values.reserve(20);
    cout << "values的容量(2)： " << values.capacity() << endl;
    cout << "values的大小(2)： " << values.size() << endl;

    // 将元素个数改变为21个，所以会增加16个默认初始化的元素
    values.resize(21);
    // 将元素个数改变为21个，新增加的16个元素默认值为99
    // values.resize(21, 99);
    // 当需要减小容器的大小时，会移除多余的元素
    // values.resize(20);
    cout << "values的容量(3)： " << values.capacity() << endl;
    cout << "values的大小(3)： " << values.size() << endl;
}

/**
 * vector容器容量和大小的数据类型
 * vector<T> 对象的容量和大小类型都是 vector<T>::size_type 类型
 * 它表示的真实类型和操作系统有关，在 32 位架构下普遍表示的是 unsigned int 类型，而在 64 位架构下普通表示 unsigned long 类型
 */
void showSizeType()
{
    vector<int> values{1, 2, 3, 4, 5};
    vector<int>::size_type cap = values.capacity();
    vector<int>::size_type size = values.size();

    // 也可以使用 auto 关键字代替 vector<int>::size_type
    // auto cap = values.capacity();
    // auto size = values.size();

    cout << "cap: " << cap << endl;
    cout << "size: " << size << endl;
}

int main()
{
    showCapacitySize();
    showCapacityIncrease();
    changeCapacitySize();
    showSizeType();
}