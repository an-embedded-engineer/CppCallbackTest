#pragma once
#include <functional>

#include "Data.h"

/* ��M���N���X�̑O���錾 */
class Receiver;

/* ��M���N���X�̃R�[���o�b�N�^��` : void(�N���X��::*)(��M�f�[�^�^&) */
using ReceiverCallbackType = void(Receiver::*)(Data&);

class Framework
{
public:
    /* �V���O���g���C���X�^���X�擾 */
    static Framework& GetInstance()
    {
        /* �ŏ��ɌĂяo���ꂽ�Ƃ��ɂ̂݃C���X�^���X�𐶐� */
        static Framework instance;
        return instance;
    }

private:
    /* �R���X�g���N�^/�f�X�g���N�^��Private�ɂ��āA���[�U�̃C���X�^���X�������֎~ */
    Framework() = default;
    ~Framework() = default;

public:
    /* �R�s�[�R���X�g���N�^/���[�u�R���X�g���N�^���폜���āA�C���X�^���X�̃R�s�[/���[�u���֎~ */
    Framework(const Framework&) = delete;
    Framework(const Framework&&) = delete;
    Framework& operator=(const Framework&) = delete;
    Framework&& operator=(const Framework&&) = delete;

public:
    /* ���M���Ɍ��J����f�[�^Publish�֐� */
    void Publish_Data(Data& data);
    /* ��M���Ɍ��J����R�[���o�b�NSubscribe�֐� */
    void Subscribe_Data(ReceiverCallbackType method, Receiver instance);

private:
    /* �f�[�^�̎�M��ʒm���A�o�^���ꂽ�R�[���o�b�N���Ăяo���֐� */
    void Notify_DataReceived();

private:
    /* ��M�����f�[�^�̃o�b�t�@ */
    Data m_data;
    /* �f�[�^��M�n���h�� */
    std::function<void(Data&)> m_OnDataReceived;
};

