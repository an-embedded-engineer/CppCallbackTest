#pragma once

#include "Data.h"

class Sender
{
public:
    Sender();
    void Execute();

private:
    void Send(Data& data);

private:
    Data m_data;
};

