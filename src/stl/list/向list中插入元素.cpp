#include <iostream>
#include <list>
#include <array>

using namespace std;

/**
 * insert() 函数的功能是在 list 容器的指定位置插入一个或多个元素
 *
 * iterator insert(pos,elem)
 * 在迭代器 pos 指定的位置之前插入一个新元素elem，并返回表示新插入元素位置的迭代器
 *
 * iterator insert(pos,n,elem)
 * 在迭代器 pos 指定的位置之前插入 n 个元素 elem，并返回表示第一个新插入元素位置的迭代器
 *
 * iterator insert(pos,first,last)
 * 在迭代器 pos 指定的位置之前，插入其他容器（例如array、list、deque等）中位于 [first,last) 区域的所有元素，并返回表示第一个新插入元素位置的迭代器
 *
 * iterator insert(pos,initlist)
 * 在迭代器 pos 指定的位置之前，插入初始化列表（用大括号{}括起来的多个元素，中间有逗号隔开）中所有的元素，并返回表示第一个新插入元素位置的迭代器
 */
void useInsert()
{
    list<int> values{1, 2};
    // 第一种格式用法
    values.insert(values.begin(), 3); // {3,1,2}

    // 第二种格式用法
    values.insert(values.end(), 2, 5); // {3,1,2,5,5}

    // 第三种格式用法
    array<int, 3> arr{7, 8, 9};
    values.insert(values.end(), arr.begin(), arr.end()); // {3,1,2,5,5,7,8,9}

    // 第四种格式用法
    values.insert(values.end(), {10, 11}); // {3,1,2,5,5,7,8,9,10,11}

    for (auto it = values.begin(); it != values.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

/**
 * emplace()
 * C++ 11 标准新增加的成员函数，用于在 list 容器指定位置之前插入一个新的元素
 * emplace() 每次只能插入一个元素，而不是多个
 *
 * iterator emplace (const_iterator pos, args...);
 * pos 为指定插入位置的迭代器；args... 表示与新插入元素的构造函数相对应的多个参数；该函数会返回表示新插入元素位置的迭代器
 */
void useEmplace()
{
    list<int> values{1, 2};
    // emplace 每次只能插入一个int类型元素
    values.emplace(values.begin(), 3);
    for (auto it = values.begin(); it != values.end(); it++) {
        cout << *it << " ";
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
 * 通过 insert() 函数向 list 容器中插入 Test 类对象，需要调用类的构造函数和移动构造函数（或拷贝构造函数）
 *
 * 通过 emplace() 函数实现同样的功能，只需要调用构造函数即可。
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
    list<Test> vec1;
    vec1.insert(vec1.begin(), Test(1));

    cout << "emplace:" << endl;
    list<Test> vec2;
    vec2.emplace(vec2.begin(), 1);
}

/**
 * 和 insert() 成员方法相比，splice() 成员方法的作用对象是其它 list 容器，其功能是将其它 list 容器中的元素添加到当前 list 容器中指定位置处
 *
 * void splice (iterator position, list& x)
 * position 为迭代器，用于指明插入位置；x 为另一个 list 容器
 * 此格式的 splice() 方法的功能是，将 x 容器中存储的所有元素全部移动当前 list 容器中 position 指明的位置处
 *
 * void splice (iterator position, list& x, iterator i)
 * position 为迭代器，用于指明插入位置；x 为另一个 list 容器；i 也是一个迭代器，用于指向 x 容器中某个元素
 * 此格式的 splice() 方法的功能是将 x 容器中 i 指向的元素移动到当前容器中 position 指明的位置处
 *
 * void splice (iterator position, list& x, iterator first, iterator last)
 * position 为迭代器，用于指明插入位置；x 为另一个 list 容器；first 和 last 都是迭代器，[fist,last) 用于指定 x 容器中的某个区域
 * 此格式的 splice() 方法的功能是将 x 容器 [first, last) 范围内所有的元素移动到当前容器 position 指明的位置处
 *
 * list 容器底层使用的是链表存储结构，splice() 成员方法移动元素的方式是，将存储该元素的节点从 list 容器底层的链表中摘除，然后再链接到当前 list 容器底层的链表中
 * 这意味着，当使用 splice() 成员方法将 x 容器中的元素添加到当前容器的同时，该元素会从 x 容器中删除
 *
 */
void useSplice()
{
    // 创建并初始化2个list容器
    list<int> lst1{1, 2, 3, 4}, lst2{10, 20, 30};
    list<int>::iterator it = ++lst1.begin(); // 指向lst1容器中的元素2

    /**
     * 调用第一种语法格式
     * lst1: 1 10 20 30 2 3 4
     * lst2:
     * it 迭代器仍然指向元素2，只不过容器变为了lst1
     */
    lst1.splice(it, lst2);

    /**
     * 调用第二种语法格式，将it指向的元素2移动熬lst2.begin()位置处
     * lst1: 1 10 20 30 3 4
     * lst2: 2
     * it 仍然指向元素2
     */
    lst2.splice(lst2.begin(), lst1, it);

    /**
     * 调用第三种语法格式，将 [lst1.begin(),lst2.end())范围内的元素移动到 lst2.begin() 位置处
     * lst1:
     * lst2: 1 10 20 30 3 4 2
     */
    lst2.splice(lst2.begin(), lst1, lst1.begin(), lst1.end());

    cout << "lst1 包含 " << lst1.size() << "个元素" << endl;
    cout << "lst2 包含 " << lst2.size() << "个元素" << endl;

    // 输出lst2容器中存储的数据
    cout << "lst2:";
    for (auto it = lst2.begin(); it != lst2.end(); it++) {
        cout << *it << " ";
    }
}

int main()
{
    useInsert();
    useEmplace();
    showDifference();
    useSplice();
}