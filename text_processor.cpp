/**
 * @file text_processor.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <fstream>

int file_exists(char filename[]);
size_t length(char * str);
int strcpy(char * from, char * to);

/**
 * @brief 
 * Scanning the name of the file to process
 * @param filename name of the file
 * @return int 0 in case of success, -1 otherwise
 */
int read_filename(char filename[])
{
    while (-1 == file_exists(filename))
    {
        printf("Введите имя файла.\n");
        scanf("%s", filename);
    }
    
    return 0;
}

/**
 * @brief 
 * Reading the contents of the file
 * @param filename name of the file
 * @param input contents of the file 
 * @return int 
 */
int read_file(char filename[], char * input[])
{
    FILE *file = fopen(filename, "r");
    char line[255] = "";
    int i = 0;
    while (file && (NULL != fgets(line, 255, file))){
        input[i] = (char *) calloc(length(line), sizeof(char)); //strdup();
        strcpy(line, input[i]);
        printf("%s", input[i]);
        i++;
    }
    fclose(file);
    return 0;
}

/**
 * @brief 
 * Copies the string
 * @note size_of(to)>=len(from)
 * @param from string to copy from
 * @param to sring to copy to
 * @return int 0 in case of success, -1 otherwise
 */
int strcpy(char * from, char * to)
{
    if (nullptr == from || nullptr == to){
        return -1;
    }
    size_t n = length(from);
    for (size_t i = 0; i < n; i++){
        to[i] = from[i];
    }
    return 0;
}

/**
 * @brief 
 * returns length of the string
 * @param str string
 * @return size_t length
 */
size_t length(char * str)
{
    if (nullptr == str){
        return -1;
    }
    size_t i = 0;
    while ('\0' != str[i]){
        i++;
    }
    return i;
}

/**
 * @brief 
 * Sorting the file's lines alphabetically
 * @param input file contents
 * @param output the result of sorting the file contents
 * @return int 0 in case of success, -1 otherwise
 */
int sort_input(char * input[], char * output[])
{

    return 0;
}

/**
 * @brief 
 * Outputting the result of the sort
 * @param filename name of the file
 * @param output the result of sorting the file contents
 * @return int 0 in case of success, -1 otherwise
 */
int output_file(char filename[], char * output[])
{

    return 0;
}

/**
 * @brief 
 * Checks if file exists
 * @param filename name of the file
 * @return int 0 in case of success, -1 otherwise
 */
int file_exists(char filename[])
{
    std::ifstream f(filename);
    if (f.good()){
        return 0;
    }
    return -1;
}
