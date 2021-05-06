#include <iostream>
#include <array>

using namespace std;

// 检查数组元素存储方式，是否在内存中连续存储
void arrayAddr()
{
    array<int, 5> arr{1, 2, 3};
    cout << &arr[2] << " " << &arr[0] + 2 << endl;
}

// 使用array存储char* 或const char*类型的字符串
void saveStr()
{
    // array容器的大小必须保证能容纳复制进来的数据，而且如果是存储字符串的话，还要保证存储整个字符串的同时，在其最后放置一个\0作为字符串的结束符
    array<char, 50> arr{1, 2, 3};
    strcpy(&arr[0], "https://www.baidu.com");
    // 上一行中的&arr[0]还可以使用data()成员函数来替换
    // strcpy(arr.data(), "https://www.baidu.com");
    printf("%s\n", &arr[0]);
}

// 交换两个相同数组(类型相同，大小相同)中的元素
void swapArr()
{
    array<char, 50> addr1{"https://www.google.com"};
    array<char, 50> addr2{"https://www.baidu.com"};

    addr1.swap(addr2);
    printf("addr1: %s\n", addr1.data());
    printf("addr2: %s\n", addr2.data());
}

// 数组间赋值，当两个array保存的元素类型相同且大小相同时，可以直接进行赋值操作
void assignArr()
{
    array<char, 50> addr1{"https://www.google.com"};
    array<char, 50> addr2{"https://www.baidu.com"};
    addr1 = addr2;
    printf("%s\n", addr1.data());
}

// 两个array保存的元素类型相同且大小相同时，还可以进行比较操作
void compareArr()
{
    array<char, 50> addr1{"https://www.google.com"};
    array<char, 50> addr2{"https://www.baidu.com"};
    if (addr1 == addr2) {
        cout << "addr1 == addr2" << endl;
    }
    if (addr1 < addr2) {
        cout << "addr1 < addr2" << endl;
    }
    if (addr1 > addr2) {
        cout << "addr1 > addr2" << endl;
    }
}

int main()
{
    arrayAddr();
    saveStr();
    swapArr();
    assignArr();
    compareArr();
}
