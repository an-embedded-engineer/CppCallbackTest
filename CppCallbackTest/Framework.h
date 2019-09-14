#pragma once
#include <functional>

#include "Data.h"

/* 受信側クラスの前方宣言 */
class Receiver;

/* 受信側クラスのコールバック型定義 : void(クラス名::*)(受信データ型&) */
using ReceiverCallbackType = void(Receiver::*)(Data&);

class Framework
{
public:
    /* シングルトンインスタンス取得 */
    static Framework& GetInstance()
    {
        /* 最初に呼び出されたときにのみインスタンスを生成 */
        static Framework instance;
        return instance;
    }

private:
    /* コンストラクタ/デストラクタをPrivateにして、ユーザのインスタンス生成を禁止 */
    Framework() = default;
    ~Framework() = default;

public:
    /* コピーコンストラクタ/ムーブコンストラクタを削除して、インスタンスのコピー/ムーブを禁止 */
    Framework(const Framework&) = delete;
    Framework(const Framework&&) = delete;
    Framework& operator=(const Framework&) = delete;
    Framework&& operator=(const Framework&&) = delete;

public:
    /* 送信側に公開するデータPublish関数 */
    void Publish_Data(Data& data);
    /* 受信側に公開するコールバックSubscribe関数 */
    void Subscribe_Data(ReceiverCallbackType method, Receiver instance);

private:
    /* データの受信を通知し、登録されたコールバックを呼び出す関数 */
    void Notify_DataReceived();

private:
    /* 受信したデータのバッファ */
    Data m_data;
    /* データ受信ハンドラ */
    std::function<void(Data&)> m_OnDataReceived;
};

