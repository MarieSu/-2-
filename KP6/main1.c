#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "com.h"

void usage() {
    printf("Usage: program [-key] filename\nKeys: -f xor -p\n");
}

int main(int argc, char *argv[]) {
    FILE *in;
    int f = 0, p = 0;
    if (argc != 3) {
        usage();
        return 1;
    } //выводим подсказку по использованию программы
    //переменные f и p принимают 1, если задан соответствующий ключ, и 0 в противном случае. Функция strcmp сравнивает строки (возвращает 0, если строки одинаковые, и 1, если разные).
    if (strcmp(argv[1], "-f") == 0) {
        f = 1;
        in = fopen(argv[2], "r");
    } else if (strcmp(argv[1], "-p") == 0) {
        p = 1;
        in = fopen(argv[2], "r");
    } else {
        usage();
        return 2;
    }
    com cp;
    if (!in) {
        perror("Can not open file\n");
        return 3;
    } //выводим ошибку, если файл невозможно открыть
    if (f) {
        printf("=========================================================================================================================\n");
        printf("||      SURNAME      |n proc|      type proc     |   size ram   |    type  disk   | num disk | cap disk |   num dev    ||\n");
        printf("=========================================================================================================================\n");
    } // шапка таблицы
    while (fread(&cp, sizeof(cp), 1, in) == 1) {
        if (f) {
            printf("||\t%-13s|\t%-4d|%-20s|\t%-8d|\t%-10s|\t%-5d|%6d\t|\t%-7d||\n", cp.surname, cp.nproc, cp.tproc, cp.sram,
                   cp.tdisk, cp.ndisk, cp.cdisk, cp.ndev);
            printf("__________________________________________________________________________________________________________________________\n");
        } // данные о компьтерах
    }
    if (f) {
        return 0;
    }
    fseek(in, 0, SEEK_SET);
    printf("\t\t\t\t\t\t\t\tANSWER\n"); // выводим заголовок ответа
        printf("=========================================================================================================================\n");
        printf("||      SURNAME      |n proc|      type proc     |   size ram   |    type  disk   | num disk | cap disk |   num dev    ||\n");
        printf("=========================================================================================================================\n");
    while (fread(&cp, sizeof(cp), 1, in) == 1) {
        if (cp.ndisk == 1 && cp.nproc < 9 && cp.ndev == 2) {
            printf("||\t%-13s|\t%-4d|%-20s|\t%-8d|\t%-10s|\t%-5d|%6d\t|\t%-7d||\n", cp.surname, cp.nproc, cp.tproc, cp.sram, cp.tdisk, 
            cp.ndisk, cp.cdisk, cp.ndev);
            printf("______________________________________________________________________________________________________________________\n");
        } // выводим отфильрованные данные(по числу дисков, по ядрам процессора и по переферийным устройствам)
    }
    return 0;
}
