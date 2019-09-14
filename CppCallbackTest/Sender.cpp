#include "Sender.h"
#include "Framework.h"

#include <iostream>

using namespace std;

Sender::Sender() : m_data()
{
    cout << "Sender Created" << endl;

    this->m_data.m_int_data = 10;
    this->m_data.m_double_data = 3.14;

    for (auto i = 0; i < 10; i++)
    {
        this->m_data.m_int_array.push_back(i);
    }

    for (auto i = 0; i < 10; i++)
    {
        SubData sub_data;
        sub_data.m_int_data = i * i;
        sub_data.m_short_data = i;
        sub_data.m_string_data = "Test";
        this->m_data.m_sub_data_map[i] = sub_data;
    }
}

void Sender::Execute()
{
    this->Send(this->m_data);
}

void Sender::Send(Data& data)
{
    cout << "Sent Data" << endl;

    /* Frameworkのシングルトンインスタンスを取得 */
    auto& framework = Framework::GetInstance();

    /* データをPublish */
    framework.Publish_Data(data);
}

