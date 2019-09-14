#include "Framework.h"
#include "Receiver.h"

#include <functional>
#include <iostream>

using namespace std;

/* 送信側によるデータのPublish */
void Framework::Publish_Data(Data& data)
{
    cout << "Published Data" << endl;

    /* データをバッファリング */
    this->m_data = data;

    /* データの受信を通知 */
    this->Notify_DataReceived();
}

/* 受信側によるコールバックのSubscribe */
void Framework::Subscribe_Data(ReceiverCallbackType method, Receiver instance)
{
    cout << "Subscribed Callback" << endl;

    /* データ受信ハンドラに指定されたコールバック(クラスのメンバ関数)を登録 */
    this->m_OnDataReceived = std::bind(method, std::ref(instance), std::placeholders::_1);
}

/* データ受信の通知(登録されたコールバックの呼び出し) */
void Framework::Notify_DataReceived()
{
    cout << "Notified Data Received" << endl;

    /* データ受信ハンドラに設定されたコールバックを呼び出し、バッファした受信データを受け渡す */
    this->m_OnDataReceived(this->m_data);
}
