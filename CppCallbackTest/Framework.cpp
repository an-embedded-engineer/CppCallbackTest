#include "Framework.h"
#include "Receiver.h"

#include <functional>
#include <iostream>

using namespace std;

/* ���M���ɂ��f�[�^��Publish */
void Framework::Publish_Data(Data& data)
{
    cout << "Published Data" << endl;

    /* �f�[�^���o�b�t�@�����O */
    this->m_data = data;

    /* �f�[�^�̎�M��ʒm */
    this->Notify_DataReceived();
}

/* ��M���ɂ��R�[���o�b�N��Subscribe */
void Framework::Subscribe_Data(ReceiverCallbackType method, Receiver instance)
{
    cout << "Subscribed Callback" << endl;

    /* �f�[�^��M�n���h���Ɏw�肳�ꂽ�R�[���o�b�N(�N���X�̃����o�֐�)��o�^ */
    this->m_OnDataReceived = std::bind(method, std::ref(instance), std::placeholders::_1);
}

/* �f�[�^��M�̒ʒm(�o�^���ꂽ�R�[���o�b�N�̌Ăяo��) */
void Framework::Notify_DataReceived()
{
    cout << "Notified Data Received" << endl;

    /* �f�[�^��M�n���h���ɐݒ肳�ꂽ�R�[���o�b�N���Ăяo���A�o�b�t�@������M�f�[�^���󂯓n�� */
    this->m_OnDataReceived(this->m_data);
}
