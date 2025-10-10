package week3;

import java.util.Scanner;

public class Exercises {
    //exercises from one to 10
    // Exercise 1
    public static void greaterNumber(Scanner input){
        int a = input.nextInt();
        int b = input.nextInt();

        if ( a > b  ){
            System.out.println(a + " is greater ");
        }
        else{
            System.out.println(b + " is greater ");
        }
    }
    //Exercise 2
    public static void evenOrOdd(Scanner input){
        int number =  input.nextInt();
        if (number % 2 == 0){
            System.out.println("Even number" + number);
        }
        else{
            System.out.println("Odd number" + number);
        }
    }
    //Exercise 3
    public static void dayOfWeek(Scanner input) {
        int day = input.nextInt();
        switch (day) {
            case 1:
                System.out.println("Monday");
                break;
            case 2:
                System.out.println("Tuesday");
                break;
            case 3:
                System.out.println("Wednesday");
                break;
            case 4:
                System.out.println("Thursday");
                break;
            case 5:
                System.out.println("Friday");
                break;
            case 6:
                System.out.println("Saturday");
                break;
            case 7:
                System.out.println("Sunday");
                break;
            default:
                System.out.println("Invalid day");
                break;
        }
    }
    //Exercise 4
    public static void workingDays(Scanner input){
        String day = input.nextLine().toLowerCase();
        if ( day.equals("monday") || day.equals("tuesday") || day.equals("wednesday") || day.equals("thursday") || day.equals("friday")){
            System.out.println("Working day!");
        }
        else if ( day.equals("saturday") || day.equals("sunday")){
            System.out.println("Weekend!");
        }
        else{
            System.out.println("Error!");
        }
    }
    //Exercise 5
    public static void interval(Scanner input){
        int a = input.nextInt();
        if ( a >= -100 && a <= 100 && a!= 0){
            System.out.println("Correct!");
        }
    }
    //Exercisse 6
    public static void interval2(Scanner input){
        int a = input.nextInt();
        if ( a >= 100 && a <= 200){
            System.out.println("Correct!");
        }
        else{
            System.out.println("Invalid!");
        }
    }
    //Exercise 7
    public static void numbersN(Scanner input){
        int n = input.nextInt();
        for(int i = 1; i < n; i++){
            System.out.println(i);
        }
    }
    //Exercise 8
    public static void numbersN2(Scanner input){
        int n = input.nextInt();
        for(int i = n; i < 1; i--){
            System.out.println(i);
        }
    }

    //Exercise 9
    public static void numbersN37(Scanner input) {
        int n = input.nextInt();
        for (int j = 1; j < n; j++) {
            if ( n % 3 == 1 && n % 7 == 1){
                System.out.println(j);
            }
        }
    }
    //Exercise 10
    public static void numbersN57(Scanner input) {
        int n = input.nextInt();
        for (int j = 1; j < n; j++) {
            if ( n % 5 == 0 && n % 7 == 0){
                System.out.println(j);
            }
        }
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        greaterNumber(input);
        evenOrOdd(input);
        dayOfWeek(input);
        workingDays(input);
        interval(input);
        interval2(input);
        numbersN(input);
        numbersN2(input);
        numbersN37(input);
        numbersN57(input);
    }
}
