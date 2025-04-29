/*
    struct <ime na promenlivata>{
        <tip na pole 1> <ime na pole 1>
        <tip na pole 2> <ime na pole 2>
    };

    struct date{
        int day;
        int month;
        int year;
    };

    struct date today;
    today.day= 5;
    today.month = 5;
    today.year = 2005;

    struct date date1 = {7 ,4 , 2025};

    struct <ime na structura> < ime na masiva> [<razmer>];
    struct date days[3];
    days[0].day = 4;

    struct date days = {{1,10,2005}, {3.8.2024},{24.5.2004}};


    STRUCTURA STRUCTURA!!!!!!!!!!!

    struct Name{
        char first[30];
        char second;
        char last[30]
    };

    typedef struct Person{
        struct Name names;
        int age;
        char gender;
    }Person;

    // typedef - dava novo ime na veche sushtestvuvash tip danni , izbqgva se prezapisvane navsqkude struct

    int main(){
        struct Person person1 = {{"Yoanna, "Y", "Yordanova"}, 19, 'w'};

        printf("Names: %s %c %s \n", person1.names.first,person1.names.second,person1.names.last);
        printf("Age: %d", person1.age);
        if (person1.gender == "m" || person1.gender == 'w'){
            printf("Gender: %c", person1.gender);
        }
        else{
            printf("you need to be human!");
        }
    }



    struct date * structptr;
    structptr = (struct date*)malloc(sizeof(struct date));
    if ( structptr == NULL ){
        printf("Error!");
        exit(1);
    }

    -> OPERATOR ZA DOSTUP DO POLE S POINTER!!!

    structptr -> day = 10;
    structptr -> month = 5;
    structptr -> year = 2009;



*/
