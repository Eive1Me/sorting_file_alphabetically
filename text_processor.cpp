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
int compare(const void * a, const void * b);
int arrcpy(char * from[], char * to[]);
size_t arrlen(char * arr[]);
int strconcat(char * str1, char * str2, char * res);

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
        char tmp[20] = "";
        printf("Введите имя файла.\n");
        scanf("%s", tmp);
        if ('.' == tmp[0]){
            strcpy("Onegin.txt", filename);
        } else {
            strcpy(tmp, filename);
        }
    }
    printf("no %s\n", filename);
    
    return 0;
}

/**
 * @brief 
 * Reading the contents of the file
 * @param filename name of the file
 * @param input contents of the file 
 * @return int 0 in case of success, -1 otherwise
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
    arrcpy(input, output);
    size_t n = arrlen(output);
    qsort(output, n, sizeof(char *), compare);
    return 0;
}

/**
 * @brief 
 * Copies one arr to another
 * @param from arr to copy from
 * @param to arr to copy to
 * @return int 0 in case of success, -1 otherwise
 */
int arrcpy(char * from[], char * to[])
{
    if (nullptr == from || nullptr == to){
        return -1;
    }
    size_t n = arrlen(from);
    for (size_t i = 0; i < n; i++){
        to[i] = (char *) calloc(length(from[i]), sizeof(char));
        strcpy(from[i], to[i]);
    }
    return 0;
}

/**
 * @brief 
 * returns the length of an array
 * @param arr array
 * @return size_t length
 */
size_t arrlen(char * arr[])
{
    if (nullptr == arr){
        return -1;
    }
    size_t i = 0;
    while (nullptr != arr[i]){
        i++;
    }
    return i;
}

/**
 * @brief 
 * Compare two lines
 * @param a first arg
 * @param b second arg
 * @return int 0 if a is equal or greater than b, -1 otherwise
 */
int compare(const void * a, const void * b)
{
    if (nullptr == a || nullptr == b){
        return -1;
    }
    char * ch_a = (*(char **) a);
    char * ch_b = (*(char **) b);
    while ((*ch_a == *ch_b) && (ch_a != 0)){
        *ch_a++;
        *ch_b++;
    }
    return *ch_a - *ch_b;
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
    size_t n = arrlen(output);
    size_t m = 4 + length(filename);
    
    char resfilename[m] = {};
    char prefix[] = "Res_";
    strconcat(prefix, filename, resfilename);

    FILE *file = fopen(resfilename, "w");
    printf("~~~~~ Sorted ~~~~~\n");
    for (size_t i = 0; i < n; i++){
        fprintf(file, output[i]);
        printf("%s", output[i]);
    }
    fclose(file);

    return 0;
}

/**
 * @brief 
 * Concatination of 2 strings
 * @param str1 1st str
 * @param str2 2nd str
 * @param res result string
 * @return int 0 in case of success, -1 otherwise
 */
int strconcat(char * str1, char * str2, char * res)
{
    if (nullptr == str1 || nullptr == str2){
        return -1;
    }
    int i = 0, j = 0;
    while ('\0' != str1[j]){
        res[i] = str1[j]; 
        i++; j++;
    }
    j = 0;
    while ('\0' != str2[j]){
        res[i] = str2[j];
        i++; j++;
    }
    res[i] = '\0';
    
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
    FILE * file;
    if((file = fopen(filename,"r"))!=NULL){
        fclose(file);
        return 0;
    }
    return -1;
}
