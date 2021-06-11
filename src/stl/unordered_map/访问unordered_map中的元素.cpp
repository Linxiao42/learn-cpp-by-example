#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * unordered_map 容器类模板中，实现了对 [ ] 运算符的重载
 * 我们可以像“利用下标访问普通数组中元素”那样，通过目标键值对的键获取到该键对应的值
 *
 * 当容器中并没有存储以 [ ] 运算符内指定的元素作为键的键值对
 * 此时 [ ] 运算符的功能将转变为：向当前容器中添加以目标元素为键的键值对
 */
void useIndex()
{
    // 创建unordered_map容器
    unordered_map<int, string> myMap{
            {1, "a"},
            {2, "b"},
            {3, "c"}
    };

    string str = myMap[1];
    cout << str << endl;
}

/**
 * unordered_map 类模板中，还提供有 at() 成员方法
 * 和使用 [ ] 运算符一样，at() 成员方法也需要根据指定的键，才能从容器中找到该键对应的值
 * 不同之处在于，如果在当前容器中查找失败，该方法不会向容器中添加新的键值对，而是直接抛出out_of_range异常
 */
void useAt()
{
    unordered_map<int, string> myMap{{1, "a"},
                                     {2, "b"},
                                     {3, "c"}};
    string value = myMap.at(2);

    cout << value << endl;

    // 下面一行会引发out_of_range异常
    // cout << myMap.at(5) << endl;
}

/**
 * find(key)
 * 通过 find() 方法得到的是一个正向迭代器
 * 当 find() 方法成功找到以指定元素作为键的键值对时，其返回的迭代器就指向该键值对
 * 当 find() 方法查找失败时，其返回的迭代器和 end() 方法返回的迭代器一样，指向容器中最后一个键值对之后的位置
 */
void useFind()
{
    unordered_map<int, string> myMap{{1, "a"},
                                     {2, "b"},
                                     {3, "c"}};
    // 查找成功
    unordered_map<int, string>::iterator iter1 = myMap.find(2);
    cout << iter1->first << " " << iter1->second << endl;

    // 查找失败
    unordered_map<int, string>::iterator iter2 = myMap.find(5);
    if (iter2 == myMap.end()) {
        cout << "当前容器中没有以5为键的键值对" << endl;
    }
}

/**
 * 除了以上方法，还可通过begin()/end()或者cbegin()/cend()遍历整个容器，找到包含指定键的键值对，进而获取该键对应的值
 */
void traverse()
{
    unordered_map<int, string> myMap{{1, "a"},
                                     {2, "b"},
                                     {3, "c"}};
    for (auto iter = myMap.begin(); iter != myMap.end(); iter++) {
        if (iter->first == 2) {
            cout << iter->first << " " << iter->second << endl;
        }
    }
}

int main()
{
    useIndex();
    useAt();
    useFind();
    traverse();
}