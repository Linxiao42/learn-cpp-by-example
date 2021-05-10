#include <iostream>
#include <list>

using namespace std;

/**
 * 使用begin()/end()
 *
 * begin() 返回指向容器中第一个元素的双向迭代器（正向迭代器）
 * end() 返回指向容器中最后一个元素所在位置的下一个位置的双向迭代器。（正向迭代器）
 */
void traverse1(list<int> &lst)
{
    cout << "第一种遍历方法: ";
    auto first = lst.begin();
    auto last = lst.end();

    // 也可以使用全局的begin/end
    // auto first = begin(lst);
    // auto last = end(lst);

    while (first != last) {
        cout << *first << " ";
        ++first;
    }
    cout << endl;
}

/**
 * 使用cbegin()/cend()
 * cbegin() 和 begin() 功能相同，只不过在其基础上，正向迭代器增加了 const 属性，即不能用于修改元素
 * cend() 和 end() 功能相同，只不过在其基础上，正向迭代器增加了 const 属性，即不能用于修改元素
 */
void traverse2(list<int> &lst)
{
    cout << "第二种遍历方法: ";
    auto first = lst.cbegin();
    auto last = lst.cend();

    // 不能修改元素
    // *first = 10;

    while (first != last) {
        cout << *first << " ";
        ++first;
    }
    cout << endl;
}

/**
 * 使用rbegin()/rend()
 * rbegin() 返回指向最后一个元素的反向双向迭代器
 * rend() 返回指向第一个元素所在位置前一个位置的反向双向迭代器
 */
void traverse3(list<int> &lst)
{
    cout << "第三种遍历方法: ";
    auto first = lst.rbegin();
    auto last = lst.rend();

    while (first != last) {
        cout << *first << " ";
        ++first;
    }
    cout << endl;
}

/**
 * 使用crbegin/crend
 * crbegin() 和 rbegin() 功能相同，只不过在其基础上，反向迭代器增加了 const 属性，即不能用于修改元素
 * crend() 和 rend() 功能相同，只不过在其基础上，反向迭代器增加了 const 属性，即不能用于修改元素
 */
void traverse4(list<int> &lst)
{
    cout << "第四种遍历方法: ";
    // 也可以使用for循环完成遍历
    for (auto first = lst.crbegin(); first != lst.crend(); first++) {
        cout << *first << " ";
    }
    cout << endl;
}

int main()
{
    list<int> lst{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    traverse1(lst);
    traverse2(lst);
    traverse3(lst);
    traverse4(lst);
}
