#include <iostream>
#include <string>
#include <set>

using namespace std;

// 定义函数对象类
class cmp1
{
public:
    // 重载 () 运算符
    bool operator()(const string &a, const string &b)
    {
        // 按照字符串的长度，做升序排序（即存储的字符串从短到长）
        return a.length() < b.length();
    }
};

// 定义函数对象模板类
template<typename T>
class cmp2
{
public:
    // 重载 () 运算符
    bool operator()(const T &a, const T &b)
    {
        // 按照值的大小，做升序排序
        // 注意，此方式必须保证 T 类型元素可以直接使用关系运算符（比如这里的 < 运算符）做比较
        return a < b;
    }
};

/**
 * 使用函数对象自定义排序规则
 *
 * 需要注意的是，此程序中创建的 mySet 容器，由于是以字符串的长度为准进行排序，因此其无法存储相同长度的多个字符串
 */
void functionObject()
{
    // 创建set容器，并使用自定义的cmp排序规则
    set<string, cmp2<string>> mySet{"ab", "abc", "a"};

    // 遍历容器中的元素
    for (auto iter = mySet.begin(); iter != mySet.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

/**
 * 在STL标准库中，存在如下排序规则
 * std::less<T> 底层采用 < 运算符实现升序排序，各关联式容器默认采用的排序规则
 * std::greater<T> 底层采用 > 运算符实现降序排序，同样适用于各个关联式容器
 * std::less_equal<T> 底层采用 <= 运算符实现升序排序，多用于 multimap 和 multiset 容器
 * std::greater_equal<T> 底层采用 >= 运算符实现降序排序，多用于 multimap 和 multiset 容器
 *
 * 当容器中存储的数据类型为自定义结构体变量或者类对象时，需要重载关系运算符，才能使排序规则发挥作用
 */
class MyString
{
public:
    explicit MyString(string s) : str(s)
    {}

    string getStr() const
    {
        return this->str;
    }

    bool operator<(const MyString &other) const
    {
        return this->str.length() < other.str.length();
    }

private:
    string str;
};

/**
 * 重载关系运算符实现自定义排序规则
 */
void relationOperator()
{
    // 创建空的set容器，仍使用默认的less<T>排序规则
    set<MyString> mySet;

    // 向set容器添加元素，这里会调用MyString类的构造函数
    mySet.emplace("ab");
    mySet.emplace("a");
    mySet.emplace("abc");

    for (auto iter = mySet.begin(); iter != mySet.end(); iter++) {
        MyString myStr = *iter;
        cout << myStr.getStr() << " ";
    }
    cout << endl;
}

int main()
{
    functionObject();
    relationOperator();
}