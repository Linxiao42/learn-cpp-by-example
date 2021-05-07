#include <iostream>
#include <vector>

using namespace std;

// 第一种遍历方法，使用size判断结束条件
void traverse1(vector<int> &vec)
{
    cout << "第一种遍历方法: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// 第二种遍历方法， 使用!=判断结束条件
void traverse2(vector<int> &vec)
{
    cout << "第二种遍历方法: ";
    vector<int>::iterator iter;
    // 用!=比较两个迭代器
    for (iter = vec.begin(); iter != vec.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

// 第三种遍历方法，使用<判断结束条件
void traverse3(vector<int> &vec)
{
    cout << "第三种遍历方法: ";
    vector<int>::iterator iter;
    // 用!=比较两个迭代器
    for (iter = vec.begin(); iter < vec.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

// 第四种遍历方法，使用while循环
void traverse4(vector<int> &vec)
{
    cout << "第四种遍历方法: ";
    vector<int>::iterator iter = vec.begin();
    while (iter < vec.end()) {
        cout << *iter << " ";
        iter += 2;
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
