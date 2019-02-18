/*
 *Documentation
 */

/*
 *Lis un premiere fois le fichier, ajoute \n
 *recherche les """ <div class="_41ud"> """ correspondant au debut d'un bloc de msg
 *envoyé par une personne
 *la ligne apres sera tjrs: """ <h5 aria-label="Max" """ plus quelque chose
 *utilisation de strtok pour decouper le nom entre les guillemets
 *un message commencera toujours par """ <div class="_aok" tabindex="0" """
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"

#define BUFFER_SIZE 1000
#define TOKEN_SIZE 100

int main(int argc, char *argv[]){
    if(argc!=2) exit(-1);
    
    FILE *fp = fopen(argv[1], "r");
    char *CopyName = "Copy.copy";
    FILE *fpCopy = fopen(CopyName, "w");
    int car = fgetc(fp);
    int caractere = 60; // correspond au caractere "<" en ascii et 62 corr a ">"
    while(car != EOF){
//        printf("%d\n", car);
        if(car == caractere) fputs("\n", fpCopy);
        fputc(car, fpCopy);
        if(car == caractere+2) fputs("\n", fpCopy);
        car = fgetc(fp);
    }
    fclose(fp);
    fclose(fpCopy);

    fpCopy = fopen(CopyName,"r");
    Dict *d = dictCreate();
    const char *USER_TAG = "<div class=\"_41ud\">\n";
    const char *FALSE_USER_TAG = "clearfix _o46 _3erg _29_7 direction_ltr text_align_ltr";
    const char *MSG_TAG1 = "<div class=";
    const char *MSG_TAG2 = "_aok";
    const char *MSG_TAG3 = " tabindex=";
    char c = '"';
    char buffer[BUFFER_SIZE];
    char *token;
    char username[TOKEN_SIZE];
    int i=0;
    while(fgets(buffer, BUFFER_SIZE, fpCopy)){
//        fprintf(stderr,"%d\n",i);
        if(strcmp(buffer, USER_TAG) == 0){
            fgets(buffer, BUFFER_SIZE, fpCopy);
            fgets(buffer, BUFFER_SIZE, fpCopy);
//            fprintf(stderr,"%s",buffer);
            token = strtok(buffer, &c);
            token = strtok(NULL, &c);
            if(strcmp(token, FALSE_USER_TAG) == 0) break;
            strcpy(username, token);
//            printf("Username %s\n", username);
//            printf("%s\n", buffer);
        }else if(strcmp(token = strtok(buffer, &c), MSG_TAG1) == 0){
//            printf("%s ", token);
            token = strtok(NULL, &c);
//            printf("%s ", token);
            if(strcmp(token, MSG_TAG2) == 0 && strcmp(strtok(NULL, &c), MSG_TAG3) == 0){
//                printf("%s \n", token);
                dictAdd(d, username, 1);
//                fprintf(stderr,"added to %s \n", username);
            }
        }
        i++;
    }
    dictPrint(d);
    return 0;
}
