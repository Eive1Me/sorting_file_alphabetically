/**
 * @file onegin.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "text_processor.h"
#include <stdio.h>

int main(const int argc, const char* argv[]) 
{
    char filename[20] = "Onegin.txt"; 
    char * input[20] = {};
    char * output[20] = {};

    // read_filename(filename);
    read_file(filename, input);
    sort_input(input, output);
    output_file(filename, output);

    return 0;
}
