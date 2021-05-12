/**
 * multimap 容器具有和 map 相同的特性，即 multimap 容器也用于存储 pair<const K, T> 类型的键值对（ K 表示键的类型，T 表示值的类型）
 * 其中各个键值对的键的值不能做修改，并且，该容器也会自行根据键的大小对存储的所有键值对做排序操作
 * 和 map 容器的区别在于，multimap 容器中可以同时存储多（≥2）个键相同的键值对
 */
#include <iostream>
#include <map>

using namespace std;

// 创建一个会返回临时multimap对象的函数
multimap<int, string> disMultimap()
{
    multimap<int, string> temp{{1, "a"},
                               {2, "b"},
                               {3, "c"}};
    return temp;
}

/**
 * 创建multimap容器
 */
void create()
{
    // 方式一：
    // 通过调用multimap类模板的默认构造函数，可以创建一个空的multimap容器
    multimap<int, string> map1;

    // 方式二：
    // 创建multimap容器同时，进行初始化操作
    // 使用此方式初始化 multimap 容器时，其底层会先将每一个{key, value}创建成 pair 类型的键值对
    // 然后再用已建好的各个键值对初始化 multimap 容器
    multimap<int, string> map2{{1, "a"},
                               {2, "b"},
                               {3, "c"}};

    // 也可以先手动创建好键值对，然后再对其初始化multimap容器
    // 借助pair类模板的构造函数来生成各个pair类型的键值对
    multimap<int, string> map3{
            pair<int, string>{1, "a"},
            pair<int, string>{2, "b"},
            pair<int, string>{2, "c"}
    };
    //通过make_pair()函数生成键值对，然后创建并初始化multimap容器
    multimap<int, string> map4{
            make_pair(1, "a"),
            make_pair(2, "b"),
            make_pair(3, "c")
    };

    // 方式三：
    // 通过调用multimap类模板的拷贝构造函数，创建新的multimap容器
    multimap<int, string> map5(map4);

    // 在 C++ 11 标准中，还为 multimap 类增添了移动构造函数
    // 即当有临时的 multimap 容器作为参数初始化新 multimap 容器时，其底层就会调用移动构造函数来实现初始化操作
    // 无论是调用拷贝构造函数还是移动构造函数，都必须保证这 2 个容器的类型完全一致
    multimap<int, string> map6(disMultimap());

    // 方式四：
    // 从已有multimap容器中选定范围，创建并初始化新的multimap容器
    multimap<int, string> map7(++map6.begin(), map6.end());

    // 方式五：
    // 创建multimap时指定排序规则
    multimap<int, string, less<int>> map8;
    multimap<int, string, greater<int>> map9;
}

/**
 * 获取multimap容器大小
 */
void size()
{
    multimap<int, string> myMap{{1, "a"},
                                {2, "b"},
                                {2, "bb"},
                                {3, "c"}};

    // 输出容器内键值对数量
    cout << myMap.size() << endl;
    // 输出容器内键为2的键值对数量
    cout << myMap.count(2) << endl;
}

/**
 * 遍历multimap容器
 */
void traverse()
{
    multimap<int, string> myMap{{1, "a"},
                                {2, "b"},
                                {2, "bb"},
                                {3, "c"}};
    for (auto iter = myMap.begin(); iter != myMap.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
}

int main()
{
    create();
    size();
    traverse();
}