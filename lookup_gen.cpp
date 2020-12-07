#include "piece.cpp"
#include <stdint.h>
#include <fstream>
#include <iomanip>
#include "print.h"
#include <stdio.h>
#include <direct.h>
using namespace std;


void generate_files(char name[], unsigned int directed_range[8]) // n, s, ne, nw, se, sw, e, w
{

    uint64_t n, s, ne, nw, se, sw, e, w;
    uint64_t keep_files = 0ULL;
    if (_mkdir("pieces") != 0)
    {

    }
    chdir("pieces");
    if (_mkdir(name) != 0)
    {

    }

    chdir(name);

    uint64_t B_FILE[8] = {
    0x8080808080808080ULL, 0x4040404040404040ULL, 0x2020202020202020ULL,
    0x1010101010101010ULL, 0x0808080808080808ULL, 0x0404040404040404ULL,
    0x0202020202020202ULL, 0x0101010101010101ULL
    }; // Filled with ones on the corresponding file, starting with A.

    uint64_t B_RANK[8] = {
        0x00000000000000ffULL, 0x000000000000ff00ULL, 0x0000000000ff0000ULL,
        0x00000000ff000000ULL, 0x000000ff00000000ULL, 0x0000ff0000000000ULL,
        0x00ff000000000000ULL, 0xff00000000000000ULL
    }; // Filled with ones on the corresponding rank, starting with 1.

    std::ofstream n_file, s_file, ne_file, nw_file, se_file, sw_file, e_file, w_file;

    n_file.open("n_lookup_table.txt");
    s_file.open("s_lookup_table.txt");
    nw_file.open("nw_lookup_table.txt");
    ne_file.open("ne_lookup_table.txt");
    se_file.open("se_lookup_table.txt");
    sw_file.open("sw_file_lookup_table.txt");
    e_file.open("e_file_lookup_table.txt");
    w_file.open("w_file_lookup_table.txt");


    for (int i = 0; i < 64; i++) // Iterate over every field
    {
        uint64_t temp = 1ULL << i;

        if(directed_range[2])
        {
            // northeast index 2
            uint64_t base_ne = 1ULL << i;
            ne = 0x0ULL;
            if (!((i/8)%2))
            {
                for(unsigned int k = 0; k < directed_range[2] - 1; k++)
                {
                    if(k%2)
                    {
                        base_ne = base_ne << 8;
                        ne |= base_ne;
                    }
                    else
                    {
                        base_ne = base_ne << 9;
                        ne |= base_ne;
                    }
                }
            }
            else
            {
                for(unsigned int k = 0; k < directed_range[2] - 1; k++)
                {
                    if(k%2)
                    {
                        base_ne = base_ne << 9;
                        ne |= base_ne;
                    }
                    else
                    {
                        base_ne = base_ne << 8;
                        ne |= base_ne;
                    }
                }
            }
            for (int j = (7 - (i % 8)); j >= 0; j--)
            {
                keep_files |= B_FILE[j];
            }

            ne &= keep_files;
            //printbb(ne,temp);
            keep_files = 0ULL;
            ne_file << "0x" << std::setfill('0') <<
                std::setw(16) << std::hex << ne << "ULL";
            if (i != 63) ne_file << ",";
            if ((i != 0) && (((i + 1) % 3) == 0)) ne_file << std::endl;
            else if (i != 63) ne_file << " ";
        }
        if(directed_range[3])
        {

            // northwest index 3
            nw  = 0x0ULL;
            uint64_t base_nw = 1ULL << i;
            if ((0 <= i && i <= 7) || (16 <= i && i <= 23) || (32 <= i && i <= 39) || (48 <= i && i <= 55))
            {
                for(unsigned int k = 0; k < directed_range[3] - 1; k++)
                {
                    if(k%2)
                    {
                        base_nw = base_nw << 7;
                        nw |= base_nw;
                    }
                    else
                    {
                        base_nw = base_nw << 8;
                        nw |= base_nw;
                    }

                }
            }

            else
            {
                for(unsigned int k = 0; k < directed_range[3] - 1; k++)
                {
                    if(k%2)
                    {
                        base_nw = base_nw << 8;
                        nw |= base_nw;
                    }
                    else
                    {
                        base_nw = base_nw << 7;
                        nw |= base_nw;
                    }
                }
            }
            for (int j = (7 - (i % 8)); j <= 7; j++)
            {
                keep_files |= B_FILE[j];
            }

            nw &= keep_files;
            keep_files = 0ULL;
            nw_file << "0x" << std::setfill('0') <<
                std::setw(16) << std::hex << nw << "ULL";
            if (i != 63) nw_file << ",";
            if ((i != 0) && (((i + 1) % 3) == 0)) nw_file << std::endl;
            else if (i != 63) nw_file << " ";
        }
        if(directed_range[5])
        {
            // southeast index 5
            se  = 0x0ULL;
            uint64_t base_se = 1ULL << i;

            if ((0 <= i && i <= 7) || (16 <= i && i <= 23) || (32 <= i && i <= 39) || (48 <= i && i <= 55))
            {
                for(unsigned int k = 0; k < directed_range[5] - 1; k++)
                {
                    if(k%2)
                    {
                        base_se = base_se >> 8;
                        se |= base_se;
                    }
                    else
                    {
                        base_se = base_se >> 7;
                        se |= base_se;
                    }
                }
            }

            else
            {
                for(unsigned int k = 0; k < directed_range[5] - 1; k++)
                {
                    if(k%2)
                    {
                        base_se = base_se >> 7;
                        se |= base_se;
                    }
                    else
                    {
                        base_se = base_se >> 8;
                        se |= base_se;
                    }
                }
            }
            for (int j = (7 - (i % 8)); j >= 0; j--)
            {
                keep_files |= B_FILE[j];
            }

            se &= keep_files;
            //printbb(se,temp);
            keep_files = 0ULL;

            se_file << "0x" << std::setfill('0') <<
                std::setw(16) << std::hex << se << "ULL";
            if (i != 63) se_file << ",";
            if ((i != 0) && (((i + 1) % 3) == 0)) se_file << std::endl;
            else if (i != 63) se_file << " ";
        }
        if(directed_range[6])
        {

            // southwest index 6
            sw  = 0x0ULL;
            uint64_t base_sw = 1ULL << i;

            if ((0 <= i && i <= 7) || (16 <= i && i <= 23) || (32 <= i && i <= 39) || (48 <= i && i <= 55))
            {
                for(unsigned int k = 0; k < directed_range[6] - 1; k++)
                {
                    if(k%2)
                    {
                        base_sw = base_sw >> 9;
                        sw |= base_sw;
                    }
                    else
                    {
                        base_sw = base_sw >> 8;
                        sw |= base_sw;
                    }
                }
            }

            else
            {
                for(unsigned int k = 0; k < directed_range[6] - 1; k++)
                {
                    if(k%2)
                    {
                        base_sw = base_sw >> 8;
                        sw |= base_sw;
                    }
                    else
                    {
                        base_sw = base_sw >> 9;
                        sw |= base_sw;
                    }
                }
            }
            for (int j = (7 - (i % 8)); j <= 7; j++)
            {
                keep_files |= B_FILE[j];
            }

            sw &= keep_files;
            //printbb(sw,temp);
            keep_files = 0ULL;

            sw_file << "0x" << std::setfill('0') <<
                std::setw(16) << std::hex << sw << "ULL";
            if (i != 63) sw_file << ",";
            if ((i != 0) && (((i + 1) % 3) == 0)) sw_file << std::endl;
            else if (i != 63) sw_file << " ";
        }

        if(directed_range[6])
        {
            // east index 6

            uint64_t base_e = 1ULL << i;
            e = 0x0ULL;
            for(unsigned int k = 0; k < directed_range[6] - 1; k++)
            {
                base_e = base_e << 1;
                e |= base_e;
            }
            e &= B_RANK[i / 8];
            e_file << "0x" << std::setfill('0') <<
                std::setw(16) << std::hex << e << "ULL";
            if (i != 63) e_file << ",";
            if ((i != 0) && (((i + 1) % 3) == 0)) e_file << std::endl;
            else if (i != 63) e_file << " ";
        }

        if(directed_range[7])
        {
            // west index 7
            uint64_t base_w = 1ULL << i;
            w = 0x0ULL;
            for(unsigned int k = 0; k < directed_range[7] - 1; k++)
            {
                base_w = base_w >> 1;
                w |= base_w;

            }

            w &= B_RANK[i / 8];
            w_file << "0x" << std::setfill('0') <<
                std::setw(16) << std::hex << w << "ULL";
            if (i != 63) w_file << ",";
            if ((i != 0) && (((i + 1) % 3) == 0)) w_file << std::endl;
            else if (i != 63) w_file << " ";
        }

        if(directed_range[0])
        {
            // north index 0
            uint64_t base_n = 1ULL << i;
            n = 0x0ULL;
            for(unsigned int k = 0; k < directed_range[0] - 1; k++)
            {
                base_n = base_n << 8;
                n |= base_n;

            }
            n &= B_FILE[7 - (i % 8)];

            n_file << "0x" << std::setfill('0') <<
                          std::setw(16) << std::hex << n << "ULL";
            if(i != 63) n_file << ",";
            if((i != 0) && (((i + 1) % 3) == 0)) n_file << std::endl;
            else if(i != 63) n_file << " ";
        }

        // south index 1
        if(directed_range[1])
        {
            uint64_t base_s = 1ULL << i;
            s = 0x0ULL;
            for(unsigned int k = 0; k < directed_range[1] - 1; k++)
            {
                base_s = base_s << 8;
                s |= base_s;

            }
            s &= B_FILE[7 - (i % 8)];

            s_file << "0x" << std::setfill('0') <<
                          std::setw(16) << std::hex << s << "ULL";
            if(i != 63) s_file << ",";
            if((i != 0) && (((i + 1) % 3) == 0)) s_file << std::endl;
            else if(i != 63) s_file << " ";

        }


        printbb(ne,temp); //possible printing



    }
    n_file.close();
    s_file.close();
    ne_file.close();
    nw_file.close();
    se_file.close();
    sw_file.close();
    e_file.close();
    w_file.close();
}
