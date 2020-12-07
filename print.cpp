#include <iostream>
#include <vector>
#include "defs.h"
using namespace std;

vector<int> bb_to_vec (uint64_t pieces_bb)
{
    unsigned int uint_1, bit_cnt;
    vector<int> result;
    bit_cnt = CNT_BITS(pieces_bb);
    for(unsigned int i=0; i < bit_cnt; i++)
    {
        uint_1 = POP_BIT(pieces_bb);
        result.push_back(uint_1);
    }
    return result;
}
void printbb(uint64_t white_pieces, uint64_t black_pieces)
{
	vector<int> w = bb_to_vec(white_pieces);
    vector<int> b = bb_to_vec(black_pieces);
	char board[64] = {};
	for (int i = 0; i < 64; i++)
	{
		board[i] = '0';
	}
	for (int i = 0; i < w.size(); i++)
	{
		board[w[i]] = 'W';
	}
	for (int i = 0; i < b.size(); i++)
	{
		board[b[i]] = 'B';
	}

	for (int i = 7; i >= 0; i--)
	{
		if (i % 2 == 0)
			cout << ' ';
		for (int j = 0; j < 8; j++)
		{
			cout << ' ' << board[8 * i + j];
		}
		cout << '\n';
	}
	cout<<endl;
}
void print_empty_bb()
{

	for (int i = 7; i >= 0; i--)
	{
		if (i % 2 == 0)
			cout << ' ';
		for (int j = 0; j < 8; j++)
		{
			if(8 * i + j >= 10)
                cout << ' ' << 8 * i + j;
            else
                cout << ' ' << '0' << 8 * i + j;

		}
		cout << '\n';
	}
}
void print_lookup(const uint64_t lookup[64])
{
    for(unsigned int i = 0; i < 64; i++)
    {
        cout << "Board position:" << i << endl;
        printbb(lookup[i],0x1ULL<<i);
        cout << endl;
    }
}


