/**
 * 和 map 容器不同，C++ STL 中的 set 容器类模板中未提供 at() 成员函数，也未对 [] 运算符进行重载
 * 因此，要想访问 set 容器中存储的元素，只能借助 set 容器的迭代器
 */

#include <iostream>
#include <set>

using namespace std;

/**
 * 使用begin()/end()
 *
 * cbegin()/cend()、rbegin()/rend()、crbegin()/crend()等用法类似
 */
void traverse()
{
    set<char> mySet{'a', 'b', 'c'};

    for (auto iter = mySet.begin(); iter != mySet.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

/**
 * find(val)
 * 在 set 容器中查找值为 val 的元素，如果成功找到，则返回指向该元素的双向迭代器
 * 反之，则返回和 end() 方法一样的迭代器。另外，如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器
 */
void find()
{
    set<char> mySet{'a', 'b', 'c'};

    set<char>::iterator iter = mySet.find('b');

    for (; iter != mySet.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

/**
 * lower_bound(val) 返回一个指向当前 set 容器中第一个大于或等于 val 的元素的双向迭代器
 * upper_bound(val) 返回一个指向当前 set 容器中第一个大于 val 的元素的迭代器
 */
void useBound()
{
    set<char> mySet{'a', 'b', 'c'};

    // 找到第一个键的值不小于'b'的迭代器
    set<char>::iterator iter1 = mySet.lower_bound('b');
    for (; iter1 != mySet.end(); iter1++) {
        cout << *iter1 << " ";
    }
    cout << endl;

    // 找到第一个键的值大于'b'的迭代器
    set<char>::iterator iter2 = mySet.upper_bound('b');
    for (; iter2 != mySet.end(); iter2++) {
        cout << *iter2 << " ";
    }
    cout << endl;
}

/**
 * equal_range(key)
 * 返回一个 pair 对象（包含 2 个双向迭代器）
 * 其中 pair.first 和 lower_bound() 方法的返回值等价
 * pair.second 和 upper_bound() 方法的返回值等价
 * 也就是说，该方法将返回一个范围，该范围中包含的值为 val 的元素（set 容器中各个元素是唯一的，因此该范围最多包含一个元素)
 */
void useEqualRange()
{
    set<char> mySet{'a', 'b', 'c'};

    // 创建一个pair对象，来接收equal_range()的返回值
    pair<set<char>::iterator, set<char>::iterator> myPair = mySet.equal_range('b');

    // 通过遍历，输出myPair指定范围内的键值对
    for (auto iter = myPair.first; iter != myPair.second; iter++) {
        cout << *iter << " " << *iter << endl;
    }
}

int main()
{
    traverse();
    find();
    useBound();
    useEqualRange();
}
