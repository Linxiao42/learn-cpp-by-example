/**
 * 考虑到“键值对”并不是普通类型数据，C++ STL 标准库提供了 pair 类模板
 * 其专门用来将 2 个普通元素 first 和 second（可以是 C++ 基本数据类型、结构体、类自定的类型）创建成一个新元素<first, second>
 *
 * pair 类模板定义在<utility>头文件中，所以在使用该类模板之前，需引入此头文件
 */

#include <iostream>
#include <string>
#include <utility>

using namespace std;

/**
 * pair构造
 *
 * C++ 11 标准之前，pair 类模板中提供了以下 3 种构造函数
 * #1) 默认构造函数，即创建空的 pair 对象
 *     pair();
 * #2) 直接使用 2 个元素初始化成 pair 对象
 *     pair (const first_type& a, const second_type& b);
 * #3) 拷贝（复制）构造函数，即借助另一个 pair 对象，创建新的 pair 对象
 *     template<class U, class V> pair (const pair<U,V>& pr);
 *
 * 在 C++ 11 标准中，在引入右值引用的基础上，pair 类模板中又增添了如下 2 个构造函数
 * #4) 移动构造函数
 *     template<class U, class V> pair (pair<U,V>&& pr);
 * #5) 使用右值引用参数，创建 pair 对象
 *     template<class U, class V> pair (U&& a, V&& b);
 */
void create()
{
    // 调用默认构造函数
    pair<int, string> pair1;

    // 调用带参构造函数
    pair<int, string> pair2(1, "abc");

    // 调用拷贝构造函数
    pair<int, string> pair3(pair2);

    // 调用移动构造函数
    pair<int, string> pair4(make_pair(1, "abc"));

    // 调用第 5 种构造函数
    pair<int, string> pair5(1, string("abc"));

    cout << "pair1: " << pair1.first << " " << pair1.second << endl;
    cout << "pair2: " << pair2.first << " " << pair2.second << endl;
    cout << "pair3: " << pair3.first << " " << pair3.second << endl;
    cout << "pair4: " << pair4.first << " " << pair4.second << endl;
    cout << "pair5: " << pair5.first << " " << pair5.second << endl;

    // c++11允许手动为pair对象赋值
    pair1.first = 1;
    pair1.second = "abc";
    cout << "pair1: " << pair1.first << " " << pair1.second << endl;

    // pair4 对象的创建过程，还可以写入如下形式
    pair<int, string> pair6 = make_pair(1, "abc");
    cout << "pair6: " << pair6.first << " " << pair6.second << endl;
}

/**
 * pair 比较
 * pair 对象重载了 <、<=、>、>=、==、!= 这 6 的运算符
 * 其运算规则是：对于进行比较的 2 个 pair 对象，先比较 pair.first 元素的大小，如果相等则继续比较 pair.second 元素的大小
 */
void compare()
{
    pair<int, string> pair1(1, "abc");
    pair<int, string> pair2(2, "abc");
    pair<int, string> pair3(2, "bcd");

    if (pair1 < pair2) {
        cout << "pair1 < pair2" << endl;
    }

    if (pair2 != pair3) {
        cout << "pair2 != pair3" << endl;
    }
}

/**
 * swap() 交换 2 个 pair 对象的键值对，前提是2个pair对象的键和值的类型要相同
 */
void swap() {
    pair<int, string> pair1(123, "abc");
    pair<int, string> pair2(321, "cba");

    cout << "pair1: " << pair1.first << " " << pair1.second << endl;
    cout << "pair2: " << pair2.first << " " << pair2.second << endl;

    pair1.swap(pair2);
    cout << "pair1: " << pair1.first << " " << pair1.second << endl;
    cout << "pair2: " << pair2.first << " " << pair2.second << endl;
}

int main()
{
    create();
    compare();
    swap();
}