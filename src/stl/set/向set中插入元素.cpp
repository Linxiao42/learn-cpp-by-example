#include <iostream>
#include <set>

using namespace std;

/**
 * 给定目标元素的值，insert() 方法即可将该元素添加到 set 容器中
 *
 * pair<iterator,bool> insert (const value_type& val)
 * 普通引用方式传参
 *
 * pair<iterator,bool> insert (value_type&& val)
 * 右值引用方式传参
 *
 * 其中，val 表示要添加的新元素，该方法的返回值为 pair 类型
 *
 * 以上 2 种语法格式的 insert() 方法，返回的都是 pair 类型的值，其包含 2 个数据，一个迭代器和一个 bool 值：
 * 当向 set 容器添加元素成功时，该迭代器指向 set 容器新添加的元素，bool 类型的值为 true
 * 如果添加失败，即证明原 set 容器中已存有相同的元素，此时返回的迭代器就指向容器中相同的此元素，同时 bool 类型的值为 false
 */
void useInsert1()
{
    // 创建并初始化set容器
    set<string> mySet;
    // 准备接收insert()的返回值
    pair<set<string>::iterator, bool> retPair;

    // 采用普通引用传值方式
    string str = "abc";
    retPair = mySet.insert(str);
    cout << "iter->" << *(retPair.first) << " " << "bool = " << retPair.second << endl;

    // 采用右值引用传值方式
    retPair = mySet.insert("a");
    cout << "iter->" << *(retPair.first) << " " << "bool = " << retPair.second << endl;
}

/**
 * 指定将新元素插入到set容器中的具体位置
 *
 * iterator insert (const_iterator position, const value_type& val)
 * 以普通引用的方式传递 val 值
 *
 * iterator insert (const_iterator position, value_type&& val)
 * 以右值引用的方式传递 val 值
 *
 * 以上 2 种语法格式中，insert() 函数的返回值为迭代器：
 * 当向 set 容器添加元素成功时，该迭代器指向容器中新添加的元素
 * 当添加失败时，证明原 set 容器中已有相同的元素，该迭代器就指向 set 容器中相同的这个元素
 *
 * 使用 insert() 方法将目标元素插入到 set 容器指定位置后，如果该元素破坏了容器内部的有序状态，set 容器还会自行对新元素的位置做进一步调整
 * 也就是说，insert() 方法中指定新元素插入的位置，并不一定就是该元素最终所处的位置
 */
void useInsert2()
{
    // 创建并初始化set容器
    set<string> mySet;
    // 准备接收insert()的返回值
    set<string>::iterator iter;

    // 采用普通引用传值方式
    string str = "abc";
    iter = mySet.insert(mySet.begin(), str);
    cout << "mySet size = " << mySet.size() << endl;

    // 采用右值引用传值方式
    iter = mySet.insert(mySet.end(), "cba");
    cout << "mySet size = " << mySet.size() << endl;
}

/**
 * 从已有set容器中选取指定区域元素插入到新set容器中，须保证2个set容器存储的元素类型相同
 *
 * template <class InputIterator>
 * void insert (InputIterator first, InputIterator last)
 *
 * 其中 first 和 last 都是迭代器，它们的组合 [first,last) 可以表示另一 set 容器中的一块区域
 * 该区域包括 first 迭代器指向的元素，但不包含 last 迭代器指向的元素
 */
void useInsert3()
{
    // 创建并初始化set容器
    set<string> mySet{"a", "b", "c"};
    // 创建一个同类型的空set容器
    set<string> otherSet;
    // 利用mySet初始化otherSet
    otherSet.insert(++mySet.begin(), mySet.end());
    // 输出otherSet容器中的元素
    for (auto iter = otherSet.begin(); iter != otherSet.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

/**
 * 一次向set容器中添加多个元素
 *
 * void insert ( {E1, E2,...,En} );
 * 其中，Ei 表示新添加的元素
 */
void useInsert4()
{
    // 创建并初始化set容器
    set<string> mySet;
    // 向容器中添加多个元素
    mySet.insert({"a", "b", "c"});

    for (auto iter = mySet.begin(); iter != mySet.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

/**
 * emplace() 和 emplace_hint() 是 C++ 11 标准加入到 set 类模板中的
 * 相比具有同样功能的 insert() 方法，完成同样的任务，emplace() 和 emplace_hint() 的效率会更高
 *
 * template <class... Args>
 * pair<iterator,bool> emplace (Args&&... args)
 *
 * 参数 (Args&&... args) 指的是，只需要传入构建新元素所需的数据即可，该方法可以自行利用这些数据构建出要添加的元素
 *
 * 另外，该方法的返回值类型为 pair 类型，其包含 2 个元素，一个迭代器和一个 bool 值：
 * 当该方法将目标元素成功添加到 set 容器中时，其返回的迭代器指向新插入的元素，同时 bool 值为 true；
 * 当添加失败时，则表明原 set 容器中已存在相同值的元素，此时返回的迭代器指向容器中具有相同键的这个元素，同时 bool 值为 false
 */
void useEmplace()
{
    // 创建并初始化set容器
    set<string> mySet;
    // 向容器中添加元素
    pair<set<string>::iterator, bool> ret = mySet.emplace("abc");
    cout << "mySet size = " << mySet.size() << endl;
    cout << "ret.iter = <" << *(ret.first) << ", " << ret.second << ">" << endl;
}

/**
 * template <class... Args>
 * iterator emplace_hint (const_iterator position, Args&&... args)
 *
 * 该方法需要额外传入一个迭代器，用来指明新元素添加到 set 容器的具体位置（新元素会添加到该迭代器指向元素的前面）
 * 返回值是一个迭代器，而不再是 pair 对象。当成功添加元素时，返回的迭代器指向新添加的元素
 * 反之，如果添加失败，则迭代器就指向 set 容器和要添加元素的值相同的元素
 */
void useEmplaceHint()
{
    // 创建并初始化set容器
    set<string> mySet;
    // 在set容器的指定位置添加键值对
    set<string>::iterator iter = mySet.emplace_hint(mySet.begin(), "abc");
    cout << "mySet size = " << mySet.size() << endl;
    cout << *iter << endl;
}

int main()
{
    useInsert1();
    useInsert2();
    useInsert3();
    useInsert4();
    useEmplace();
    useEmplaceHint();
}