#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

struct SubData
{
    int m_int_data;
    short m_short_data;
    string m_string_data;

    SubData()
        : m_int_data(0)
        , m_short_data(0)
        , m_string_data()
    {
    }
};

struct Data
{
    int m_int_data;
    double m_double_data;
    vector<int> m_int_array;
    map<int, SubData> m_sub_data_map;

    Data()
        : m_int_data(0)
        , m_double_data(0.0)
        , m_int_array()
        , m_sub_data_map()
    {
    }
};

