// CppCallbackTest.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <functional>

#include "Sender.h"
#include "Receiver.h"

using namespace std;

void callback_func(int a)
{
    cout << a << endl;
}

class TestClass
{
public:
    void Callback(int a)
    {
        cout << a << endl;
    }

};

int main()
{
#if 0
    TestClass test_class_obj;

    std::function<void(int)> f;

    f = callback_func;

    f(1);

    f = std::bind(&TestClass::Callback, std::ref(test_class_obj), std::placeholders::_1);

    f(2);
#endif

    Sender sender;
    Receiver receiver;

    sender.Execute();
}
