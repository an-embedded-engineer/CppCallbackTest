#pragma once

#include "Data.h"

class Receiver
{
public:
    Receiver();

private:
    void DataReceiveCallback(Data& data);
    void DumpData(Data& data);

private:
    Data m_data;
};

