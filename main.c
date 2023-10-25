#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void programDesc(){
    printf("Akasztofa v1.0.1 made by: Adam Szabo\n\n");
}

int main(){

    //deklarációk

    char bemenetszo[1000];
    char kimenetszo[1000];
    int length = 0;
    char aktualisBetu;
    int hiba = 0;
    char igenvagynem;
    kezdet:
//alapkiírás
    programDesc();
    printf("Irj be egy szot.\n");
//bekérés

    scanf("%s",bemenetszo);

//output clear

    system("cls");

//szöveg hosszúsága

    while (bemenetszo[length] != '\0'){
        length++;
    }
//beteszi az underscoreokat

    for (int i = 0; i < length; ++i) {

         kimenetszo[i] = '_';
    }
//lezárja a tömböt

    kimenetszo[length] = '\0';

//első betűkérés és kiírás
    programDesc();
    printf("Irj be egy betut.\n");
    printf("%s\n",kimenetszo);

// do-while ciklus

    do{

        scanf(" %c", &aktualisBetu);
        //kicsi lesz a betű

        aktualisBetu = (char)tolower(aktualisBetu);
        //ha nincs meg a teljes szó akkor mindig törölje az outputot

        if (strcmp(kimenetszo,strlwr(bemenetszo)) != 0) {

            system("cls");

        }

        //deklarálás

        int talalt = 0;

        // for ciklus végigmegy a szöveg végéig

        for (int i = 0; i < length; ++i) {
        //kicsivé teszi a bemenet valamelyik betűjét és megnézi hogy egyenlő-e az adott betűvel

            if(tolower(bemenetszo[i]) == aktualisBetu){

                kimenetszo[i] = aktualisBetu;
                //ha egyenlő akkor a talalt 1, ha nem akkor marad 0

                talalt = 1;
            }
        }
        // ha a talalt 0, szóval nem egyenlő a betű a bemenet valemelyik betűjével, akkor levon hiba mennyiséget a 10-ből

        if (talalt == 0) {

            hiba++;
            if (hiba < 10) {
                programDesc();
                printf("Rossz karakter! Most lehet leesett a feje a palcikaembernek, vagy a laba, szegeny palcikaember! Testreszek szama: %d\n", 10 - hiba);
                system("pause");
                system("cls");
            }
        // ha a hiba nagyobb vagy egyenlő mint 10, akkor vége van a mókának

            if (hiba >= 10) {
                programDesc();
                printf("Ezt kellett volna kitalalni: %s\n",strlwr(bemenetszo));
                //leállítja a futást

                system("pause");
                return 0;
            }
        }
        // ezek felelősek azért, hogy bizonyos sorok csak akkor jelenjenek meg, ha nem végeztünk
        if (strcmp(kimenetszo, strlwr(bemenetszo)) != 0) {
            programDesc();
            printf("Irj be egy betut.\n");
        }

        if (strcmp(kimenetszo, strlwr(bemenetszo)) != 0) {
            printf("%s\n", kimenetszo);
        }
    }while(strcmp(kimenetszo,bemenetszo) != 0);

    // vég
    programDesc();
    printf("Sikerult kitalalnod a szot! Gratulalok!\nA szo ez volt: %s\n\n",kimenetszo);
    //ujrajatek
    printf("Szeretnel meg egyet jatszani? y/n ");
    scanf(" %c",&igenvagynem);

    if(igenvagynem == 'y'){
        //resetelesek a kovi roundhoz
            kimenetszo[0] = '\0';
            bemenetszo[0] = '\0';
            igenvagynem = '\0';
            aktualisBetu = '\0';
            length = 0;
        system("cls");

        goto kezdet;
    }
    else{
        //leállítja a futást
        system("pause");
    }

    return 0;
}