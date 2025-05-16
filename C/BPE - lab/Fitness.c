#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Member{
    char names[56];
    char number[7];
    float subs;
    int code;
};

struct Member *AddMember(struct Member **members);
void UnderSubs(struct Member *members);
void ReturnMembers(char numberNew[7]);

int count = 0;

int main(){
    FILE *fp;

    fp = fopen("members.txt","w");
    fclose(fp);

    struct Member *members = NULL;

    AddMember(&members);

    UnderSubs(members);

    ReturnMembers("AA1234");
}

struct Member *AddMember(struct Member** members){
    count++;
    FILE *fp;
    struct Member *temp = realloc(*members,count*sizeof(struct Member));

    if ( temp == NULL ){
        printf("ERROR!");
        exit(1);
    }
    else{
        printf("Imena na member: ");
        fgets(temp[count-1].names, sizeof(temp[count-1].names), stdin);

        printf("Nomer: ");
        fgets(temp[count-1].number, sizeof(temp[count-1].number), stdin);

        printf("Subscription plan: ");
        scanf("%f",&temp[count-1].subs);

        printf("Code: ");
        scanf("%d",&temp[count-1].code);

        fp = fopen("members.txt", "a");

        if ( fp == NULL ){
            printf("ERROR!");
            exit(2);
        }

        fprintf(fp, "%d;%s;%s;%f;%d\n",strlen(temp[count-1].names),
                                    temp[count-1].names,
                                    temp[count-1].number,
                                    temp[count-1].subs,
                                    temp[count-1].code);
        fclose(fp);

        *members = temp;

        return *members;
    }
}

void UnderSubs(struct Member *members){
    float result = 0.0;
    int truee = 0;

    for ( int i = 0; i < count; i++ ){
        result += members[i].subs;
    }

    float average = result/count;

    for ( int y = 0; y < count; y++ ){
        if ( members[y].subs < average ){
                truee++;
            printf("%s - %s - %f\n", members[y].names, members[y].number, members[y].subs);
        }
    }
    if ( truee == 0 ){
        printf("Nqma abonamenti pod average subs!");
    }
}

void ReturnMembers(char numberNew[7]){
    FILE * file;

    file = fopen("members.bin","rb");

    if ( file == NULL ){
        printf("ERROR!");
        exit(3);
    }

    struct Member memberss;
    int Sizename = 0;

    while ( fread(&Sizename, sizeof(int), 1, file) ){
        fread(&memberss.names, sizeof(Sizename), 1, file);
        fread(&memberss.number, sizeof(char)*7, 1, file);
        fread(&memberss.subs, sizeof(float), 1, file);
        fread(&memberss.code, sizeof(int), 1, file);

        if ( strcmp(numberNew, memberss.number) == 0 ){
            printf("Bin Names: %s\nBin ID: %s\nBin M_Price: %f\nBin Locker: %d",memberss.names,
                                                                                memberss.number,
                                                                                memberss.subs,
                                                                                memberss.code);
            break;
        }
    }

    fclose(file);
}


