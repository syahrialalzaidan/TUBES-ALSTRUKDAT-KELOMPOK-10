#include <stdio.h>
#include <stdlib.h>
#include "mesinkar.h"

// ASLINYA "mesinkarakter.h"

char currentChar;
boolean EOP;
boolean isFile = false;
char* filepath;

static FILE *pita;
static int retval;

void LoadPita(char* filename, boolean isF) {
    filepath = filename;
    isFile = isF;
}

void StopLoadPita() {
    isFile = false;
}

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
    if (isFile) {
        pita = fopen(filepath, "r");
        if (pita == NULL) {
            printf("File tidak ditemukan\n");
        } else {
            ADV();
        }
    } else {
        pita = stdin;
        ADV();
    }
}

void ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
    retval = fscanf(pita,"%c",&currentChar);
    EOP = IsEOP();
    if (EOP && isFile) {
        fclose(pita);
    }
}

char GetCC() {
/* Mengirimkan currentChar */
    return currentChar;
}

boolean IsEOP() {
/* Mengirimkan true jika currentChar = MARK */
    //check if currentChar is blank and the next character is blank  too
    if (isFile) {
        // if (currentChar == BLANK) {
        //     char nextChar;
        //     retval = fscanf(pita,"%c",&nextChar);
        //     if (nextChar == BLANK) {
        //         return true;
        //     } else {
        //         ungetc(nextChar,pita);
        //         return false;
        //     }
        // } else {
        //     return (currentChar == MARK);
        // }
        return (currentChar == EOF || retval == EOF);
    } else {
        return (currentChar == MARK);
    }
}

