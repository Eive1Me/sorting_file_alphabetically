#include "text_processor.h"

int main(const int argc, const char* argv[]) 
{
    char filename[] = "";

    read_filename(filename);
    sort_file(filename);
    output_file(filename);

    return 0;
}
