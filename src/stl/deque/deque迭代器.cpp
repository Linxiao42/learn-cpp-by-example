#include <iostream>
#include <deque>

using namespace std;

/**
 * 使用begin()/end()
 */
void traverse1(deque<int> d)
{
    // 使用容器的成员函数begin()/end()
    for (auto i = d.begin(); i < d.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    // 也可以使用全局的begin()和end()函数
    for (auto i = begin(d); i < end(d); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

/**
 * 使用cbegin()/cend()
 * cbegin()/cend() 成员函数和 begin()/end() 唯一不同的是，前者返回的是 const 类型的正向迭代器
 * 这就意味着，由 cbegin() 和 cend() 成员函数返回的迭代器，可以用来遍历容器内的元素，也可以访问元素，但是不能对所存储的元素进行修改
 */
void traverse2(deque<int> d)
{
    auto first = d.cbegin();
    auto end = d.cend();
    // 常量迭代器不能用来修改容器中的元素值
    // *(first + 1) = 6; // 尝试修改容器中元素2的值
    // *(end -1) = 10; // 尝试修改容器中元素5的值

    // 常量迭代器可以用来遍历容器、访问容器中的元素
    while (first < end) {
        cout << *first << " ";
        ++first;
    }
    cout << endl;
}

/**
 * 使用rbegin()和rend()
 * 分别表示指向最后一个元素和第一个元素前一个位置的随机访问迭代器，又常称为反向迭代器
 * 需要注意的是，在使用反向迭代器进行 ++ 或 -- 运算时，++ 指的是迭代器向左移动一位，-- 指的是迭代器向右移动一位，即这两个运算符的功能也“互换”了
 */
void traverse3(deque<int> d)
{
    for (auto i = d.rbegin(); i < d.rend(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

/**
* 使用crbegin()/crend()
* crbegin()/crend() 成员函数和 rbegin()/rend() 唯一不同的是，前者返回的是 const 类型的反向迭代器
* 这就意味着，由 crbegin() 和 crend() 成员函数返回的迭代器，可以用来遍历容器内的元素，也可以访问元素，但是不能对所存储的元素进行修改
*/
void traverse4(deque<int> d)
{
    auto first = d.crbegin();
    auto end = d.crend();

    while (first < end) {
        cout << *first << " ";
        ++first;
    }
    cout << endl;
}

int main()
{
    deque<int> d{1, 2, 3, 4, 5};

    traverse1(d);
    traverse2(d);
    traverse3(d);
    traverse4(d);
}
