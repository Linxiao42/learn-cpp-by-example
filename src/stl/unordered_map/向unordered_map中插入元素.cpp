#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/**
 * 使用[ ]
 * unordered_map 类模板中对[ ]运算符进行了重载，即根据使用场景的不同，借助[ ]运算符可以实现不同的操作
 * 当操作对象为 unordered_map 容器中已存储的键值对时，则借助 [ ] 运算符，既可以获取指定键对应的值，还能对指定键对应的值进行修改
 * 反之，若 unordered_map 容器内部没有存储以 [ ] 运算符内指定数据为键的键值对，则使用 [ ] 运算符会向当前 unordered_map 容器中添加一个新的键值对
 */
void useIndex()
{
    unordered_map<int, string> myMap{{1, "a"}};
    // 获取已存储键值对中，指定键对应的值
    cout << myMap[1] << endl;

    // 向unordered_map容器添加新键值对
    myMap[2] = "b";

    // 修改unordered_map容器中指定键的值
    myMap[1] = "aaa";

    for (auto iter = myMap.begin(); iter != myMap.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
}

/**
 * 无需指定插入位置，直接将键值对添加到unordered_map容器中
 *
 * pair<iterator,bool> insert (const value_type& val)
 * 引用传递一个键值对
 *
 * template <class P>
 * pair<iterator,bool> insert (P&& val)
 * 以右值引用的方式传递键值对
 *
 * val 参数表示键值对变量，该方法会返回一个 pair 对象，其中 pair.first 表示一个迭代器，pair.second 为一个 bool 类型变量
 * 如果成功插入 val，则该迭代器指向新插入的 val，bool 值为 true
 * 如果插入 val 失败，则表明当前 unordered_map 容器中存有和 val 的键相同的键值对（用 p 表示），此时返回的迭代器指向 p，bool 值为 false
 *
 * 以上 2 种语法格式的区别在于传递参数的方式不同，即无论是局部定义的键值对变量还是全局定义的键值对变量，都采用普通引用传递的方式
 * 而对于临时的键值对变量，则以右值引用的方式传参
 */
void useInsert1()
{
    unordered_map<int, string> myMap;

    pair<int, string> myPair = {1, "a"};

    // 创建一个接收insert()函数返回值的pair对象
    pair<unordered_map<int, string>::iterator, bool> ret;

    // 插入myPair，由于myPair并不是临时变量，因此会以第一种方式传参
    ret = myMap.insert(myPair);
    cout << "ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;

    // 以右值引用的方式传递临时的键值对变量
    ret = myMap.insert({1, "a"});
    // 还可以使用如下2种方式创建临时键值对变量
    // ret = myMap.insert(pair<int, string>{1, "a"});
    // ret = myMap.insert(make_pair(1, "a"));
    cout << "ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
}

/**
 * 指定位置插入新键值对
 * iterator insert (const_iterator position, const value_type& val)
 * 以普通引用的方式传递 val 参数
 *
 * template <class P>
 * iterator insert (const_iterator position, P&& val)
 * 以右值引用的方式传递 val 键值对参数
 *
 * 其中 val 为要插入的键值对变量。注意，和第 1 种方式的语法格式不同，这里 insert() 方法返回的是迭代器，而不再是 pair 对象：
 * 如果插入成功，insert() 方法会返回一个指向 unordered_map 容器中已插入键值对的迭代器
 * 如果插入失败，insert() 方法同样会返回一个迭代器，该迭代器指向 unordered_map 容器中和 val 具有相同键的那个键值对
 *
 * 虽然通过 position 参数指定了新键值对添加到容器中的位置
 * 但该键值对真正存储的位置，并不是 position 参数说了算，最终的存储位置仍取决于该键值对的键的值
 */
void useInsert2()
{
    unordered_map<int, string> myMap;

    pair<int, string> myPair = {1, "a"};

    // 指定要插入的位置
    unordered_map<int, string>::iterator it = myMap.begin();

    // 向it位置以普通引用的方式插入myPair
    auto iter1 = myMap.insert(it, myPair);
    cout << iter1->first << " " << iter1->second << endl;

    // 向it位置以右值引用的方式插入临时键值对
    auto iter2 = myMap.insert(it, pair<int, string>(2, "b"));
    cout << iter2->first << " " << iter2->second << endl;

    // 插入失败样例
    auto iter3 = myMap.insert(it, pair<int, string>(1, "a"));
    cout << iter3->first << " " << iter3->second << endl;
}

/**
 * 向当前unordered_map容器中插入其他unordered_map容器指定区域内的所有键值对
 *
 * template <class InputIterator>
 * void insert (InputIterator first, InputIterator last)
 * 其中 first 和 last 都是迭代器，它们的组合<first,last>可以表示某 unordered_map 容器中的指定区域
 */
void useInsert3()
{
    unordered_map<int, string> myMap{{1, "a"},
                                              {2, "b"},
                                              {3, "c"}};

    // 创建一个空unordered_map容器
    unordered_map<int, string> copyMap;
    // 指定插入区域
    unordered_map<int, string>::iterator first = ++myMap.begin();
    unordered_map<int, string>::iterator last = myMap.end();
    // 将<first, last>区域内的键值对插入到copyMap中
    copyMap.insert(first, last);
    // 遍历输出copyMap容器中的键值对
    for (auto iter = copyMap.begin(); iter != copyMap.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
}

/**
 * 向 unordered_map 容器中插入多个键值对
 * void insert ({val1, val2, ...});
 * 其中，vali 都表示的是键值对变量
 */
void useInsert4()
{
    // 创建空的unordered_map容器
    unordered_map<int, string> myMap;
    // 向unordered_map容器中添加3个键值对
    myMap.insert({{1, "a"},
                  {2, "b"},
                  {3, "c"}});
    for (auto iter = myMap.begin(); iter != myMap.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
}

/**
 * emplace()
 * 实现相同的插入操作，无论是用 emplace() 还是 emplace_hint()，都比 insert() 方法的效率高
 *
 * template <class... Args>
 * pair<iterator,bool> emplace (Args&&... args);
 * 参数 (Args&&... args) 指的是，这里只需要将创建新键值对所需的数据作为参数直接传入即可，此方法可以自行利用这些数据构建出指定的键值对
 * 另外，该方法的返回值也是一个 pair 对象，其中 pair.first 为一个迭代器，pair.second 为一个 bool 类型变量：
 *    当该方法将键值对成功插入到 unordered_map 容器中时，其返回的迭代器指向该新插入的键值对，同时 bool 变量的值为 true；
 *    当插入失败时，则表明 unordered_map 容器中存在具有相同键的键值对，此时返回的迭代器指向此具有相同键的键值对，同时 bool 变量的值为 false。
 */
void useEmplace()
{
    // 创建一个空的unordered_map容器
    unordered_map<int, string> myMap;
    // 插入键值对
    pair<unordered_map<int, string>::iterator, bool> ret = myMap.emplace(1, "a");
    cout << "1. ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;

    // 插入键值对
    ret = myMap.emplace(2, "b");
    cout << "2. ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;

    // 插入失败样例，要插入的键值对的键和 unordered_map 容器中已存在的键值对的键相同
    ret = myMap.emplace(1, "c");
    cout << "3. ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
}

/**
 * template <class... Args>
 * iterator emplace_hint (const_iterator position, Args&&... args);
 *
 * 和 emplace() 方法相同，emplace_hint() 方法内部会自行构造新键值对
 * 因此我们只需向其传递构建该键值对所需的 2 个元素（第一个作为键，另一个作为值）即可
 *
 * emplace_hint() 方法的返回值仅是一个迭代器，而不再是 pair 类型变量
 * 当该方法将新键值对成功添加到容器中时，返回的迭代器指向新添加的键值对
 * 反之，如果添加失败，该迭代器指向的是容器中和要添加键值对键相同的那个键值对
 *
 * emplace_hint() 方法还需要传递一个迭代器作为第一个参数，该迭代器表明将新键值对添加到容器中的位置。
 * 需要注意的是，新键值对添加到容器中的位置，并不是此迭代器说了算，最终仍取决于该键值对的键的值
 *
 */
void useEmplaceHint()
{
    // 创建一个空的unordered_map容器
    unordered_map<int, string> myMap;
    // 在unordered_map容器中的指定位置插入键值对
    unordered_map<int, string>::iterator iter = myMap.emplace_hint(myMap.begin(), 1, "a");
    cout << iter->first << " " << iter->second << endl;

    iter = myMap.emplace_hint(myMap.begin(), 2, "b");
    cout << iter->first << " " << iter->second << endl;

    // 插入失败样例
    iter = myMap.emplace_hint(myMap.begin(), 1, "c");
    cout << iter->first << " " << iter->second << endl;
}

int main()
{
    useIndex();
    useInsert1();
    useInsert2();
    useInsert3();
    useInsert4();
    useEmplace();
    useEmplaceHint();
}
