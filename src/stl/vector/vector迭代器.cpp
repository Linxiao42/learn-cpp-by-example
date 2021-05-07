#include <iostream>
#include <vector>

using namespace std;

// 使用begin()/end()
void traverse1(vector<int> &vec)
{
    cout << "第一种遍历方法: ";
    auto first = vec.begin();
    auto last = vec.end();

    // 也可以使用全局的begin/end
    // auto first = begin(vec);
    // auto last = end(vec);

    while (first != last) {
        cout << *first << " ";
        ++first;
    }
    cout << endl;
}

// 使用cbegin/cend
void traverse2(vector<int> &vec)
{
    cout << "第二种遍历方法: ";
    auto first = vec.cbegin();
    auto last = vec.cend();

    // 不能修改元素
    // *first = 10;

    while (first != last) {
        cout << *first << " ";
        ++first;
    }
    cout << endl;
}

// 使用rbegin/rend
void traverse3(vector<int> &vec)
{
    cout << "第三种遍历方法: ";
    auto first = vec.rbegin();
    auto last = vec.rend();

    while (first != last) {
        cout << *first << " ";
        ++first;
    }
    cout << endl;
}

// 使用crbegin/crend
void traverse4(vector<int> &vec)
{
    cout << "第四种遍历方法: ";
    // 也可以使用for循环完成遍历
    for (auto first = vec.crbegin(); first != vec.crend(); first++) {
        cout << *first << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    traverse1(vec);
    traverse2(vec);
    traverse3(vec);
    traverse4(vec);
}
