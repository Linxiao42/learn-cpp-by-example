#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    // 创建空的容器
    unordered_map<int, string> map;

    cout << "map 初始桶数：" << map.bucket_count() << endl;
    cout << "map 初始负载因子：" << map.load_factor() << endl;
    cout << "map 最大负载因子：" << map.max_load_factor() << endl;

    // 设置map使用最适合存储9个键值对的桶数
    map.reserve(9);
    cout << "map 新桶数：" << map.bucket_count() << endl;
    cout << "map 新负载因子：" << map.load_factor() << endl;

    // 向map容器添加3个键值对
    map[1] = "a";
    map[2] = "b";
    map[3] = "c";

    // 调用bucket()获取指定键值对位于桶的编号
    cout << "以1为键的键值对，位于桶的编号为：" << map.bucket(1) << endl;

    // 自行计算某键值对位于哪个桶
    auto fn = map.hash_function();
    cout << "计算以1为键的键值对，位于桶的编号为：" << fn(1) % map.bucket_count() << endl;
}