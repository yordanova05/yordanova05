#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Course{
    char name[51];
    char date[11];
    int lectures;
    float price;
};

void ReducedCourse(struct Course *courses, int n, int index);
int WrittenValues(struct Course *courses, int n, float min, float max);
struct Course* NewCourses(struct Course **courses, int *n, char name1[51], char date1[11]);

int main(){
    FILE *fp;

    fp = fopen("courses.bin","rb");

    if ( fp == NULL ){
        printf("ERROR WHILE OPENING THE FILE!");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int bytes = ftell(fp);
    rewind(fp);
    int n = bytes/sizeof(struct Course);

    struct Course *courses = (struct Course*)calloc(n, sizeof(struct Course));
    if (courses == NULL){
        printf("ERROR WHYLE SETTING DINAMIC MEMORY!");
        exit(3);
    }

    fread( courses, sizeof(struct Course), n, fp);

    for( int i = 0; i < n; i++ ){
        printf("%s\n", courses[i].name);
        printf("%s\n", courses[i].date);
        printf("%d\n", courses[i].lectures);
        printf("%f\n", courses[i].price);
    }

    fclose(fp);

    for ( int i = 0; i < n - 1; i++ ){
        for ( int y = i + 1; y < n; y++ ){
            if ( strcmp(courses[i].name, courses[y].name) == 0 && strcmp(courses[i].date, courses[y].date)){
                printf("DOUBLE COURSE!");
            }
        }
    }

    ReducedCourse(courses, n, 3);

    int count = WrittenValues(courses, n, 400.0, 1000.0);
    printf("Courses: %d\n", count);

    struct Course* newcourses = NewCourses(&courses, &n, "BPE", "2025.10.24");
}

void ReducedCourse(struct Course *courses, int n, int index){

    if ( index >= n || index < 0 ) {
        printf("INDEX OUT OF RANGE!");
        return;
    }
    for ( int i = 0; i < n; i++ ){
        if ( i == index ){
            courses[i].price = courses[i].price*10/100;
            printf("%.2fleva. - %s - %s\n", courses[i].price, courses[i].name, courses[i].date);
            break;
        }
    }
}

int WrittenValues(struct Course *courses, int n, float min, float max){
    if ( min < 0 || max < 0){
        printf("VALUE UNDER 0!");
        exit(1);
    }

    FILE *file;
    int count = 0;

    file = fopen("offer.txt","w");
    if ( file == NULL ){
        printf("ERROR WHILE OPENING THE FILE!");
        exit(2);
    }

    for ( int i = 0; i < n; i++ ){
        if ( courses[i].price >= min && courses[i].price <= max ){
            count++;
            fprintf(file, "%s \n%s \n%d lectures \n%.2flv.\n\n", courses[i].name,
                                                            courses[i].date,
                                                            courses[i].lectures,
                                                            courses[i].price);

        }
    }

    fclose(file);

    if ( !count ){
        printf("COURSES NOT FOUND!");
        return 0;
    }
    else{
        return count;
    }
}

struct Course* NewCourses(struct Course **courses, int *n, char name1[51], char date1[11]){
    int newcount = *n;

    for ( int i = 0; i < *n; i++ ){
        if ( strcmp(courses[i]->name, name1) == 0 && strcmp(courses[i]->date, date1) == 0){
            for ( int y = i; y < newcount; y++ ){
                (*courses)[y] = (*courses)[y+1];
            }
            newcount--;
            break;
        }
    }

    if ( newcount < *n ){
        struct Course *temp = (struct Course*)malloc(newcount*sizeof(struct Course));
        if ( temp == NULL ){
            printf("ERROR WHILE SETTING DINAMIC MEMORY!");
            return NULL;
        }

        free(*courses);

       *courses = temp;
       *n = newcount;
       return *courses;
    }
    else{
        return NULL;
    }
}

