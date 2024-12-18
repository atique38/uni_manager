#include<stdio.h>
#include<string.h>

int main()
{
    struct admin
    {
        char username[50];
        char password[10];
    }ad;

    FILE *fp;
    fp=fopen("admin.txt","a");
    strcpy(ad.username,"abu57");
    strcpy(ad.password,"1245");
    fwrite(&ad,sizeof(ad),1,fp);

    strcpy(ad.username,"atique38");
    strcpy(ad.password,"5647");
    fwrite(&ad,sizeof(ad),1,fp);
    fclose(fp);
}
