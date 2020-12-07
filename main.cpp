#include <iostream>
#include <stdint.h>
#include "defs.h"
#include "print.h"
#include "lookup_tables.h"
#include "move_gen.h"
#include "lookup_gen.h"
#include "file_reader.h"

using namespace std;

int main()
{
    unsigned int directed_range[8] = {8,8,8,8,8,8,8,8}; //n, s, ne, nw, se, sw, e, w
    generate_files("my_piece", directed_range);


   // char piecename[] = "my_piece";

  //  std::array<array<uint64_t,64>,8> mypiece;

//    mypiece = read_files(piecename);
    uint64_t black_bb = 0x800ULL;
    uint64_t white_bb = 0x4200ULL;
    uint64_t bishop_bb = 0x4200LL;
    uint64_t lookup[64];


/*
    for(unsigned int i = 0; i < 8; i++)
    {
            for (unsigned int j = 0; j < 64; j++)
            {
                lookup[j]=mypiece[i][j];

            }
        printbb(lookup);
        //gen_side_moves(bishop_bb, WHITE, white_bb, black_bb,lookup);
    }

    //print_lookup(KING_LT);
*/
	printbb(white_bb, black_bb);
	print_empty_bb();

    cout<<"all east moves:"<<endl;
    gen_east_moves(bishop_bb, WHITE, white_bb, black_bb);

    cout<<"all west moves:"<<endl;
    gen_west_moves(bishop_bb, WHITE, white_bb, black_bb);

    cout<<"all north east moves:"<<endl;
    gen_north_east_moves(bishop_bb, WHITE, white_bb, black_bb);

    cout<<"all north west moves:"<<endl;
    gen_north_west_moves(bishop_bb, WHITE, white_bb, black_bb);

    cout<<"all south east moves:"<<endl;
    gen_south_east_moves(bishop_bb, WHITE, white_bb, black_bb);

    cout<<"all south west moves:"<<endl;
    gen_south_west_moves(bishop_bb, WHITE, white_bb, black_bb);


    cout<<"all east jumps:"<<endl;
    gen_east_jumps(bishop_bb, WHITE, white_bb, black_bb);

    cout<<"all west jumps:"<<endl;
    gen_west_jumps(bishop_bb, WHITE, white_bb, black_bb);



    return 0;
}
