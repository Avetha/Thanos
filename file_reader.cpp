#include "piece.cpp"
#include <stdint.h>
#include <fstream>
#include <iomanip>
#include "print.h"
#include <stdio.h>
#include <string>
#include <direct.h>
#include <iostream>
#include "file_reader.h"
#include <stdlib.h>
#include <array>

using namespace std;

array<uint64_t,64> read_file(char piecename[], char filename[])
{
    chdir(piecename);
    array<uint64_t,64> table;
    std::ifstream infile;
    infile.open(filename);
    if(infile.peek()==ifstream::traits_type::eof())
    {
        return table;
    }
    string data = "";
    int i=0;
    stringstream ss;
    while(getline(infile, data, ','))
    {
      ss << std::hex << data;
      ss >> table[i];
      i++;
    }
    infile.close();
    return table;
}

array<array<uint64_t,64>,8> read_files(char piecename[])
{
    array<array<uint64_t,64>,8> table;
    table[0] = read_file(piecename, "n_lookup_table.txt");
    table[1] = read_file(piecename, "s_lookup_table.txt");
    table[2] = read_file(piecename, "nw_lookup_table.txt");
    table[3] = read_file(piecename, "ne_lookup_table.txt");
    table[4] = read_file(piecename, "se_lookup_table.txt");
    table[5] = read_file(piecename, "sw_lookup_table.txt");
    table[6] = read_file(piecename, "e_lookup_table.txt");
    table[7] = read_file(piecename, "w_lookup_table.txt");
    return table;
}

