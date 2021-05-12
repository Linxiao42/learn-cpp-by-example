/**
 * 作为关联式容器的一种，map 容器存储的都是 pair 对象，也就是用 pair 类模板创建的键值对
 * 其中，各个键值对的键和值可以是任意数据类型，包括 C++ 基本数据类型（int、double 等）、使用结构体或类自定义的类型
 *
 * 与此同时，在使用 map 容器存储多个键值对时，该容器会自动根据各键值对的键的大小，按照既定的规则进行排序
 * 默认情况下，map 容器选用std::less<T>排序规则（其中 T 表示键的数据类型），其会根据键的大小对所有键值对做升序排序
 * 当然，根据实际情况的需要，我们可以手动指定 map 容器的排序规则，既可以选用 STL 标准库中提供的其它排序规则（比如std::greater<T>），也可以自定义排序规则
 *
 * 使用 map 容器存储的各个键值对，键的值既不能重复也不能被修改
 * 换句话说，map 容器中存储的各个键值对不仅键的值独一无二，键的类型也会用 const 修饰，这意味着只要键值对被存储到 map 容器中，其键的值将不能再做任何修改
 *
 * map 容器存储的都是 pair 类型的键值对元素，更确切的说，该容器存储的都是 pair<const K, T> 类型（其中 K 和 T 分别表示键和值的数据类型）的键值对元素
 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

// 创建一个会返回临时 map 对象的函数
map<int, string> disMap()
{
    map<int, string> tempMap{{1, "a"},
                             {2, "b"}};
    return tempMap;
}

int main()
{
    // 调用默认构造函数，创建一个空的map容器
    map<int, string> map1;

    // 创建map的同时进行初始化
    map<int, string> map2{make_pair(1, "a"), make_pair(2, "b")};

    // 利用已有的map，创建新的map，新旧map类型须一致
    // 此过程将调用map的拷贝构造函数
    map<int, string> map3(map2);

    // 调用 map 类模板的移动构造函数创建新map容器，新旧map类型须一致
    // C++11标准中，当有临时的 map 对象作为参数，传递给要初始化的 map 容器时，此时就会调用移动构造函数
    map<int, string> map4(disMap());

    // 取已有map容器中指定区域的键值对，创建并初始化新的map容器
    map<int, string> map5(++map2.begin(), map2.end()); // {{2, "b"}}

    // 创建map容器时修改排序规则
    map<int, string, std::greater<int>> map6{{1, "a"},
                                             {2, "b"},
                                             {3, "c"}};

    for (map<int, string>::iterator iter = map6.begin(); iter != map6.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
}