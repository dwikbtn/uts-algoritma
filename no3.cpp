#include <iostream>
#include <stack>
using namespace std;

bool checkStackEquality(stack<int> stack1, stack<int> stack2)
{
    if (stack1.size() != stack2.size())
    {
        return false;
    }

    while (!stack1.empty())
    {
        if (stack1.top() != stack2.top())
        {
            return false;
        }
        stack1.pop();
        stack2.pop();
    }

    return true;
}

int main()
{
    stack<int> stack1, stack2;

    // Menambahkan elemen ke stack1
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);

    // Menambahkan elemen ke stack2
    stack2.push(10);
    stack2.push(20);
    stack2.push(30);
    // Memanggil fungsi untuk mengecek kesamaan stack
    bool isEqual = checkStackEquality(stack1, stack2);

    if (isEqual)
    {
        cout << "Kedua stack memiliki nilai yang sama." << endl;
    }
    else
    {
        cout << "Kedua stack memiliki nilai yang berbeda." << endl;
    }

    return 0;
}