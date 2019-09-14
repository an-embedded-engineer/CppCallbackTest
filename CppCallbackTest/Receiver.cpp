#include "Receiver.h"
#include "Framework.h"

#include <iostream>

using namespace std;

Receiver::Receiver()
{
    cout << "Receiver Created" << endl;

    /* Framework�̃V���O���g���C���X�^���X���擾 */
    auto& framework = Framework::GetInstance();

    /* �f�[�^��M�̃R�[���o�b�N(�����o�֐�)��Subscribe */
    framework.Subscribe_Data(&Receiver::DataReceiveCallback, *this);
}

/* �f�[�^��M���ɌĂяo�����R�[���o�b�N */
void Receiver::DataReceiveCallback(Data& data)
{
    cout << "Received Data" << endl;

    /* �����œn������M�f�[�^���g�������� */
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

