#include <iostream>
#include <vector>

using namespace std;

const int N = 10;

/**
 * 方式一：使用数组
 */
void array1()
{
    /**
     * 定义数组需先确认数组长度，即N须为常量
     * 这意味着，如果在实际应用中无法确定数组长度，那么通常会将长度设置为数组的最大值
     * 这样一来有可能造成内存浪费
     */
    int arr[N];
}

/**
 * 方式二：使用数组，重新分配内存
 */
void array2()
{
    /**
     * 在堆中动态申请内存，此时长度可以是变量
     * 这种方式可以根据变量n动态申请内存，不会存在空间浪费问题
     */
    int n = 10;
    int *arr = new int[n];

    // 但是程序执行期间若存储空间不够，则需加大存储空间
    int m = 20;
    // 1.新申请一个较大内存空间
    int *temp = new int[m];
    // 2.拷贝原数据到新内存空间
    memcpy(temp, arr, sizeof(int) * n);
    // 3.将原数据所在的堆空间释放
    delete[]arr;
    arr = temp;
}

/**
 * 方式三：使用vector取代数组，内存可在运行时调整
 */
void vector1()
{
    // 定义vector vec，此时vec的长度为0，但vec会根据存储的数量自动变长
    vector<int> vec;
    // 向vec中添加10个元素
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }

    // 可以手动调整vec的大小
    vec.resize(100);
    vec[90] = 100;

    // 还可以清空vec中所有元素
    vec.clear();

    // 重新调整vec的大小为20，并存储20个-1元素
    vec.resize(20, -1);

    for (int i = 0; i < 20; ++i) {
        cout << vec[i] << " ";
    }
}

int main()
{
    array1();
    array2();
    vector1();
}
