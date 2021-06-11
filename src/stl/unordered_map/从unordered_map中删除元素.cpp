#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * iterator erase ( const_iterator position )
 * 接受一个正向迭代器，并删除该迭代器指向的键值对
 * position 为指向容器中某个键值对的迭代器，该方法会返回一个指向被删除键值对之后位置的迭代器
 */
void useErase1()
{
    unordered_map<int, string> myMap{{1, "a"},
                                     {2, "b"},
                                     {3, "c"}};
    // 输出容器中第一个键值对
    cout << myMap.begin()->first << " " << myMap.begin()->second << endl;

    // 定义一个接收erase()方法的迭代器
    unordered_map<int, string>::iterator ret;

    // 删除容器中第一个键值对
    ret = myMap.erase(myMap.begin());

    // 输出容器中存储的键值对
    for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
}

/**
 * size_type erase ( const key_type& k )
 * 直接将要删除键值对的键作为参数直接传给 erase() 方法，该方法会自行去 unordered_map 容器中找和给定键相同的键值对，将其删除
 * k 表示目标键值对的键的值；该方法会返回一个整数，其表示成功删除的键值对的数量
 */
void useErase2()
{
    unordered_map<int, string> myMap{{1, "a"},
                                     {2, "b"},
                                     {3, "c"}};
    myMap.erase(1);

    // 输出容器中存储的键值对
    for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
}

/**
 * iterator erase ( const_iterator first, const_iterator last )
 * 删除指定范围内的所有键值对
 * 其中 first 和 last 都是正向迭代器，[first, last) 范围内的所有键值对都会被 erase() 方法删除
 * 同时，该方法会返回一个指向被删除的最后一个键值对之后一个位置的迭代器
 */
void useErase3()
{
    unordered_map<int, string> myMap{{1, "a"},
                                     {2, "b"},
                                     {3, "c"}};
    // first 指向第一个键值对
    unordered_map<int, string>::iterator first = myMap.begin();
    // last 指向最后一个键值对
    unordered_map<int, string>::iterator last = myMap.end();

    auto ret = myMap.erase(first, last);

    // 输出容器中存储的键值对，为空
    for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
}

/**
 * void clear()
 * 一次性删除 unordered_map 容器中存储的所有键值对
 */
void useClear()
{
    unordered_map<int, string> myMap{{1, "a"},
                                     {2, "b"},
                                     {3, "c"}};
    myMap.clear();
    cout << "myMap size = " << myMap.size() << endl;
}

int main()
{
    useErase1();
    useErase2();
    useErase3();
    useClear();
}