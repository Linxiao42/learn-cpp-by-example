#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * 使用begin()/end()
 *
 * cbegin()/cend()、rbegin()/rend()、crbegin()/crend()等用法类似
 */
void useBeginEnd()
{
    unordered_map<int, string> myMap{{1, "a"},
                                   {2, "b"},
                                   {3, "c"}};
    for (auto iter = myMap.begin(); iter != myMap.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;
}

/**
 * find(key)
 * 在 unordered_map 容器中查找键为 key 的键值对，如果成功找到，则返回指向该键值对的双向迭代器
 * 反之，则返回和 end() 方法一样的迭代器
 */
void useFind()
{
    unordered_map<int, string> myMap{{1, "a"},
                                   {2, "b"},
                                   {3, "c"}};
    unordered_map<int, string>::iterator iter = myMap.find(2);
    for (; iter != myMap.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;
}

int main()
{
    useBeginEnd();
    useFind();
}