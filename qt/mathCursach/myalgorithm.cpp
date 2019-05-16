#include <iostream>
#include "myalgorithm.h"


namespace stu
{
void correct_conditions(int it, int that)
{
    if(it != that)
    {
        throw std::invalid_argument("uncorrect conditions");
    }
}

int pow(int a, int times)
{
    int b = a;
    for(int i = 0; i < times + 1; i++)
    {
        a *= b;
    }
    return a;
}

void matrix_jumping(int& i, int& j, int that)
{
    if(i < that)
    {
        if(j == that - 1)
        {
            j = 0;
            i++;
        }
        else
        {
            j++;
        }
    }
}
int find_min(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}

void check_replace(int& a, int& b)
{
    if(a < b)
    {
        a = b;
    }
}

}
