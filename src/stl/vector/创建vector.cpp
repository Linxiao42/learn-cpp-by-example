#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 创建一个元素为double类型的vector容器，此时容器并没有分配空间
    vector<double> values1;

    // 在创建好的容器上，使用reserve()来增加容器的容量
    values1.reserve(20);

    // 创建容器时，指定初始值以及元素个数
    vector<int> values2{1, 2, 3, 4, 5};

    // 创建容器时，指定元素个数，此时默认值都为0
    vector<double> values3(20);

    // 创建容器时，指定元素个数和默认值，此时默认值都为1
    vector<int> values4(20, 1);

    // 使用变量创建vector
    int num = 20;
    int value = 10;
    vector<int> values5(num, value);

    // 通过存储元素类型相同的其他vector容器来创建新的vector容器
    vector<char> values6(5, 'c');
    vector<char> values7(values6);

    // 通过数组创建vector容器，使用指针指定范围
    int array[] = {1, 2, 3};
    vector<int> values8(array, array + 2);

    // 通过vector创建vector容器，使用指针或迭代器来指定范围
    vector<int> values9{1, 2, 3, 4, 5};
    vector<int> values10(begin(values8), begin(values8) + 3);
}
