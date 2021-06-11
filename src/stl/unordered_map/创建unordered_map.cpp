/**
 * unordered_map 容器，直译过来就是"无序 map 容器"的意思。
 * 所谓“无序”，指的是 unordered_map 容器不会像 map 容器那样对存储的数据进行排序。
 * 换句话说，unordered_map 容器和 map 容器仅有一点不同，即 map 容器中存储的数据是有序的，而 unordered_map 容器中是无序的
*/

#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, string> getMap()
{
    unordered_map<int, string> tempMap{
            {1, "a"},
            {2, "b"},
            {3, "c"}
    };
    return tempMap;
}

int main()
{
    // 调用默认构造函数，创建空的unordered_map容器
    unordered_map<int, string> map1;

    // 创建容器的同时进行初始化
    unordered_map<int, string> map2{
            {1, "a"},
            {2, "b"},
            {3, "c"}
    };

    // 通过调用unordered_map模板中的拷贝构造函数
    // 将现有unordered_map中存储的键值对复制给新的容器
    unordered_map<int, string> map3(map2);

    // 通过移动构造函数，即以右值引用的方式将临时unordered_map容器中存储的所有键值对，全部复制给新建容器
    unordered_map<int, string> map4(getMap());

    // 从现有容器中选择部分区域内的键值对，为新容器初始化
    unordered_map<int, string> map5(++map2.begin(), map2.end());

}