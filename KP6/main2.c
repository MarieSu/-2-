#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "com.h"
// Если argc возвращает значение, не равное 3 (программа, входной файл, выходной файл), то вызовем функцию void usage(), выводящую подсказку по использованию программы.
void usage(){
    printf("Usage: program input_filename output_filename\n");
}
//считываем данные
int readcom(FILE *in, com *p){
    return fscanf(in, "%[^\t]\t%[^\t]\t%d\t%d\t%[^\t]\t%d\t%d\t%d\n", p->surname, p->tproc, &p->nproc, &p->sram, p->tdisk, &p->ndisk, &p->cdisk, &p->ndev) == 8;
}


int main(int argc, char* argv[]){
    if (argc != 3){
        usage();
        return 1;
    }
    com p;
    FILE *out = fopen(argv[2], "w"); //имя выходного файла
    FILE *in = fopen(argv[1], "r"); //имя входного файла
    if (!(out&&in)){
        perror("Can't open file"); // завершить программу, если не удалось открыть хотя бы один из файлов
        return 2;
    }
    while (readcom(in, &p)){
        fwrite(&p, sizeof (p), 1, out);
    }
    return 0;
}
