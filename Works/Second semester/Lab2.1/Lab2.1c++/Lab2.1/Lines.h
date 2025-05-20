#pragma once
#include <string>
#include <algorithm>

using std::string;

class Base
{
public:
    string line;
    int i = 0;

    Base()
    {

    }


    Base(string line)
    {
        LineLength(line);
    }

    int LineLength(std::string UIline)
    {

        i = UIline.length();
        return i;
    }

};


class Inherited : public Base
{
public:

    Inherited()
    {
        line = "5423412sdfasfasfasgrvsrvrgr53g5rg4grdgdfg3";
    }

    void SortingBy()
    {
        std::sort(line.begin(), line.end());
    }

};

