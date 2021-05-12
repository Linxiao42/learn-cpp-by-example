#include <iostream>
#include <map>

using namespace std;

/**
 * 使用begin()/end()
 *
 * cbegin()/cend()、rbegin()/rend()、crbegin()/crend()等用法类似
 */
void useBeginEnd()
{
    map<int, string> myMap{{1, "a"},
                           {2, "b"},
                           {3, "c"}};
    for (auto iter = myMap.begin(); iter != myMap.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;
}

/**
 * find(key)
 * 在 map 容器中查找键为 key 的键值对，如果成功找到，则返回指向该键值对的双向迭代器
 * 反之，则返回和 end() 方法一样的迭代器
 */
void useFind()
{
    map<int, string> myMap{{1, "a"},
                           {2, "b"},
                           {3, "c"}};
    map<int, string>::iterator iter = myMap.find(2);
    for (; iter != myMap.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;
}

/**
 * lower_bound(key) 返回一个指向当前 map 容器中第一个大于或等于 key 的键值对的双向迭代器
 * upper_bound(key) 返回一个指向当前 map 容器中第一个大于 key 的键值对的迭代器
 */
void useBound()
{
    map<int, string> myMap{{1, "a"},
                           {2, "b"},
                           {3, "c"}};

    // 找到第一个键的值不小于2的迭代器
    map<int, string>::iterator iter1 = myMap.lower_bound(2);
    for (; iter1 != myMap.end(); iter1++) {
        cout << iter1->first << " " << iter1->second << endl;
    }
    cout << endl;

    // 找到第一个键的值大于2的迭代器
    map<int, string>::iterator iter2 = myMap.upper_bound(2);
    for (; iter2 != myMap.end(); iter2++) {
        cout << iter2->first << " " << iter2->second << endl;
    }
    cout << endl;
}

/**
 * equal_range(key)
 * 返回一个 pair 对象（包含 2 个双向迭代器）
 * 其中 pair.first 和 lower_bound() 方法的返回值等价
 * pair.second 和 upper_bound() 方法的返回值等价
 * 也就是说，该方法将返回一个范围，该范围中包含的键为 key 的键值对（map 容器键值对唯一，因此该范围最多包含一个键值对）
 */
void useEqualRange()
{
    map<int, string> myMap{{1, "a"},
                           {2, "b"},
                           {3, "c"}};

    // 创建一个pair对象，来接收equal_range()的返回值
    pair<map<int, string>::iterator, map<int, string>::iterator> myPair = myMap.equal_range(2);

    // 通过遍历，输出myPair指定范围内的键值对
    for (auto iter = myPair.first; iter != myPair.second; iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;
}

int main()
{
    useBeginEnd();
    useFind();
    useBound();
    useEqualRange();
}