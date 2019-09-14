#include "Receiver.h"
#include "Framework.h"

#include <iostream>

using namespace std;

Receiver::Receiver()
{
    cout << "Receiver Created" << endl;

    /* Frameworkのシングルトンインスタンスを取得 */
    auto& framework = Framework::GetInstance();

    /* データ受信のコールバック(メンバ関数)をSubscribe */
    framework.Subscribe_Data(&Receiver::DataReceiveCallback, *this);
}

/* データ受信時に呼び出されるコールバック */
void Receiver::DataReceiveCallback(Data& data)
{
    cout << "Received Data" << endl;

    /* 引数で渡される受信データを使った処理 */
    this->DumpData(data);
}

void Receiver::DumpData(Data& data)
{
    cout << "Dump Data" << endl;

    cout << "int data:" << data.m_int_data << endl;
    cout << "double data:" << data.m_double_data << endl;

    cout << "int vector:" << endl;
    auto i = 0;
    for (auto& item : data.m_int_array)
    {
        cout << "  [" << i << "]" << item << endl;
        i++;
    }

    cout << "SubData map:" << endl;
    for (auto& item : data.m_sub_data_map)
    {
        cout << "  Key:" << item.first << endl;
    }
}

