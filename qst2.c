#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int Compresser(char src_path[50],char dst_path[50])
{
    FILE * fpt;
    fpt = fopen(src_path, "r");
    int Arr[80];
    int i = 0;

    while(!feof(fpt))
    {
        fscanf(fpt, "%i", &Arr[i]);
        if(Arr[i] != 0)
        {
            i++;
        }
    }
    fclose(fpt);

    int lenArr = i;
    int arrCmp[lenArr][2];
    arrCmp[0][0] = Arr[0];
    arrCmp[0][1] = 0;
    int indArr = 0;

    for(i=1; i<=lenArr; i++)
    {

        if(arrCmp[indArr][0] == Arr[i-1])
        {
            arrCmp[indArr][1] += 1;
        }
        else
        {
            indArr++;
            arrCmp[indArr][1] = 1;
            arrCmp[indArr][0] = Arr[i-1];
        }
        
    }

fpt = fopen(dst_path, "w");

for(i=0; i<= indArr; i++)
{
    fprintf(fpt, "%i %i\n", arrCmp[i][0], arrCmp[i][1]);

}

    fclose(fpt);

    return 0;
}


int main()
{


    Compresser("F.txt", "G.txt");


    FILE * fpt = fopen("G.txt", "r");
    int lngSec, Sec, blnk, line, lngPos, Sec1;
    int tot[20];

    fscanf(fpt, "%i %i",&blnk , &lngSec);
    line = 1;
    tot[0]=lngSec;
    Sec1 = lngSec;

    while(!feof(fpt))
    {
        fscanf(fpt, "%i %i",&blnk , &Sec);
        line++;
        tot[line-1] = Sec + tot[line-2];

        if(Sec > lngSec)
        {
            lngSec = Sec;
            lngPos = line;
        }

    }
    fclose(fpt);

    int pos;

    if(Sec1==lngSec)
    {
        pos = 1;
    }else
    {
        pos = tot[lngPos-2] + lngPos;
    }

    printf("\nla position de la plus longue sequence en F est: POS = %i.", pos);

    return 0;

}
