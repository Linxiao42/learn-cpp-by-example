#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
 * 使用[]运算符
 *
 * 只有当 map 容器中确实存有包含该指定键的键值对，借助重载的 [ ] 运算符才能成功获取该键对应的值
 * 反之，若当前 map 容器中没有包含该指定键的键值对，则此时使用 [ ] 运算符将不再是访问容器中的元素，而变成了向该 map 容器中增添一个键值对
 * 其中，该键值对的键用 [ ] 运算符中指定的键，其对应的值取决于 map 容器规定键值对中值的数据类型
 * 如果是基本数据类型，则值为 0；如果是 string 类型，其值为 ""，即空字符串（即使用该类型的默认值作为键值对的值）
 */
void useIndex()
{
    map<int, string> myMap{{1, "a"},
                           {2, "b"},
                           {3, "c"}};
    string value = myMap[2];

    cout << value << endl;
}

/**
 * 使用at()成员函数
 * 和[]相比，使用at()也需要根据指定的键，才能从容器中找到该键对应的值
 * 不同之处在于，如果在当前容器中查找失败，该方法不会向容器中添加新的键值对，而是直接抛出 out_of_range 异常。
 */
void useAt()
{
    map<int, string> myMap{{1, "a"},
                           {2, "b"},
                           {3, "c"}};
    string value = myMap.at(2);

    cout << value << endl;

    // 下面一行会引发out_of_range异常
    // cout << myMap.at(5) << endl;
}

/**
 * find(key)
 * 在 map 容器中查找键为 key 的键值对，如果成功找到，则返回指向该键值对的双向迭代器
 * 反之，则指向 map 容器最后一个键值对之后的位置（和 end() 函数返回的迭代器一样）
 */
void useFind()
{
    map<int, string> myMap{{1, "a"},
                           {2, "b"},
                           {3, "c"}};
    map<int, string>::iterator iter = myMap.find(2);

    // 如果find()查找失败，则下一行代码无意义，因为此时iter指向的是容器中最后一个键值对的后一个位置
    cout << iter->first << " " << iter->second << endl;
}

/**
 * 如果以上方法不适用，还可遍历整个map容器，找到包含指定键的键值对，进而获取该键对应的值
 */
void traverse()
{
    map<int, string> myMap{{1, "a"},
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