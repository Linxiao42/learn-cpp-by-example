#include <iostream>
#include <vector>

using namespace std;

// 使用索引访问单个元素
void useIndex()
{
    vector<int> values{1, 2, 3, 4, 5};
    // 获取容器中首个元素
    // 采用索引获取元素，须确保索引的值不会超过容器的容量（可通过capacity()函数获取）
    cout << values[0] << endl;
    // 修改容器中下标为0的元素的值
    values[0] = 100;
    cout << values[0] << endl;
}

// 使用at()函数访问单个元素（越界会抛出异常）
void useAt()
{
    vector<int> values{1, 2, 3, 4, 5};
    // 获取容器中首个元素
    cout << values.at(0) << endl;
    values.at(0) = 100;

    // 当传给at()的索引越界时，会抛出std::out_of_range异常，如下一行语句
    // cout << values.at(5) << endl;
}

// 使用front()/back()访问首元素和尾元素(获取首元素和尾元素的引用）
void useFrontBack()
{
    vector<int> values{1, 2, 3, 4, 5};
    cout << "values 首元素为： " << values.front() << endl;
    cout << "values 尾元素为： " << values.back() << endl;

    // 修改首元素
    values.front() = 10;
    cout << "values 新的首元素为： " << values.front() << endl;

    // 修改尾元素
    values.back() = 20;
    cout << "values 新的尾元素为： " << values.back() << endl;
}

// 使用data()函数获取容器中首个元素的指针
void useData()
{
    vector<int> values{1, 2, 3, 4, 5};
    // 输出容器中第3个元素的值
    cout << *(values.data() + 2) << endl;
    // 修改容器中第3个元素的值
    *(values.data() + 2) = 30;
    // 输出容器中第3个元素的值
    cout << *(values.data() + 2) << endl;
}

// 使用size()访问vector中的多个元素
void useSize()
{
    vector<int> values{1, 2, 3, 4, 5};
    // 从下标0一直遍历到size()-1处
    for (int i = 0; i < values.size(); i++) {
        cout << values[i] << " ";
    }
    cout << endl;
}

// 使用基于range的循环访问vector中的多个元素
void useRange()
{
    vector<int> values{1, 2, 3, 4, 5};
    for (auto v: values) {
        cout << v << " ";
    }
    cout << endl;
}

int main()
{
    useIndex();
    useAt();
    useFrontBack();
    useData();
    useSize();
    useRange();
}