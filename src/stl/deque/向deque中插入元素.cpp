#include <iostream>
#include <deque>
#include <array>

using namespace std;

/**
 * insert() 在指定的位置直接生成一个元素。和 emplace() 不同的是，该函数添加新元素的过程是，先构造元素，然后再将该元素移动或复制到容器的指定位置
 *
 * iterator insert(pos,elem)
 * 在迭代器 pos 指定的位置之前插入一个新元素elem，并返回表示新插入元素位置的迭代器
 *
 * iterator insert(pos,n,elem)
 * 在迭代器 pos 指定的位置之前插入 n 个元素 elem，并返回表示第一个新插入元素位置的迭代器
 *
 * iterator insert(pos,first,last)
 * 在迭代器 pos 指定的位置之前，插入其他容器中位于 [first,last) 区域的所有元素，并返回表示第一个新插入元素位置的迭代器
 *
 * iterator insert(pos,initlist)
 * 在迭代器 pos 指定的位置之前，插入初始化列表（用大括号{}括起来的多个元素，中间有逗号隔开）中所有的元素，并返回表示第一个新插入元素位置的迭代器
 */
void useInsert()
{
    deque<int> d{1, 2};
    // 第一种格式用法
    d.insert(d.begin() + 1, 3); // {1,3,2}

    // 第二种格式用法
    d.insert(d.end(), 2, 5); // {1,3,2,5,5}

    // 第三种格式用法
    array<int, 3> arr{7, 8, 9};
    d.insert(d.end(), arr.begin(), arr.end()); // {1,3,2,5,5,7,8,9}

    // 第四种格式用法
    d.insert(d.end(), {10, 11}); // {1,3,2,5,5,7,8,9,10,11}

    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }
    cout << endl;
}

/**
 * emplace()
 * C++ 11 新添加的成员函数，其功能是 insert() 相同，即在指定的位置直接生成一个元素
 * 和 insert() 不同的是，emplace() 直接在容器指定位置构造元素，省去了复制或移动元素的过程
 *
 * iterator emplace (const_iterator pos, args...);
 * pos 为指定插入位置的迭代器；args... 表示与新插入元素的构造函数相对应的多个参数；该函数会返回表示新插入元素位置的迭代器
 */
void useEmplace()
{
    deque<int> d{1, 2};
    // emplace 每次只能插入一个int类型元素
    d.emplace(d.begin(), 3);
    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }
    cout << endl;
}

class Test
{
public:
    Test(int n) : num(n)
    {
        cout << "调用构造函数" << endl;
    }

    Test(const Test &other) : num(other.num)
    {
        cout << "调用拷贝构造函数" << endl;
    }

    Test(Test &&other) : num(other.num)
    {
        cout << "调用移动构造函数" << endl;
    }

    Test &operator=(const Test &other)
    {
        this->num = other.num;
        return *this;
    }

private:
    int num;
};

/**
 * insert()和emplace()区别
 *
 * 当拷贝构造函数和移动构造函数同时存在时，insert() 会优先调用移动构造函数
 * 通过 insert() 函数向 deque 容器中插入 Test 类对象，需要调用类的构造函数和移动构造函数（或拷贝构造函数）
 *
 * 通过 emplace() 函数实现同样的功能，只需要调用构造函数即可
 * 简单的理解，就是 emplace() 在插入元素时，是在容器的指定位置直接构造元素，而不是先单独生成，再将其复制（或移动）到容器中
 *
 * 实际使用中，推荐优先使用 emplace()
 *
 * insert:
 *  调用构造函数
 *  调用移动构造函数
 * emplace:
*   调用构造函数
 */
void showDifference()
{
    cout << "insert:" << endl;
    deque<Test> d1;
    d1.insert(d1.begin(), Test(1));

    cout << "emplace:" << endl;
    deque<Test> d2;
    d2.emplace(d2.begin(), 1);
}

int main()
{
    useInsert();
    useEmplace();
    showDifference();
}