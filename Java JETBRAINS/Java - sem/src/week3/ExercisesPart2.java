package week3;
import java.util.ArrayList;
import java.util.Scanner;
public class ExercisesPart2 {
    // Exercises from 11 to 20
    // Exercise 11
    public static void higherLower(Scanner input ){
        System.out.print("Enter number higher than 2: ");
        int n = input.nextInt();
        int maxNumber = 0; int minNumber = 0;

        for( int i=0; i<n; i++) {
           int number = input.nextInt();
           if ( i == 0 ){
               maxNumber = number;
           }
           else if ( i == 1 ){
               minNumber = number;
           }
           else{
               if ( maxNumber < number){
                   maxNumber = number;
               } else if ( minNumber > number) {
                   minNumber = number;
               }
           }
       }
//        int[] numbers = new int[n];
//        for( int i=0; i<n; i++) {
//            int number = input.nextInt();
//            numbers[i] = number;
//        }
//        int max = numbers[0];
//        int min = numbers[1];
//        for ( int j=1; j<n; j++){
//            if (numbers[j]>max){
//                max = numbers[j];
//            }
//            else if (numbers[j] < min){
//                min = numbers[j];
//            }
//        }
        System.out.printf("Max: %d, Min: %d", maxNumber,minNumber);
    }
    //Exercise 12
    public static int sum(Scanner input){
        int n = input.nextInt();
        int sum = 0;
        for ( int i =0;i <n ;i++ ){
            int number = input.nextInt();
            sum+=number;
        }
        return sum;
    }
    //Exercise 13
    public static void writingStop(Scanner input){
        while(true) {
            String niz = input.next();
            if (niz.equalsIgnoreCase("stop")) {
                break;
            }
            else{
                System.out.println(niz);
            }
        }
    }
    //Exercise 14
    public static void dividedBy10(Scanner input){
        while(true) {
            int number = input.nextInt();
            if (number%10 == 0) {
                break;
            }
            else{
                System.out.printf("(%d) cannot be divided by 10!, enter another number which can be divided by 10!\n", number);
            }
        }
    }
    //Exercise 15
    public static void timeNow(Scanner input){
        String date = input.next();
        String[] values = date.split(":");
        int minutes = Integer.parseInt(values[1]);
        int hours = Integer.parseInt(values[0]);

        if (hours == 23 && minutes + 15 >= 60){
            hours = 0;
            minutes= minutes + 15 - 60;
        }
        else if (minutes + 15 >= 60){
            hours++;
            minutes= minutes + 15 - 60;
        }
        else {
            minutes+=15;
        }
        System.out.printf("%02d:%02d", hours, minutes);
    }
    //Exervise 16
    public static void isValid(Scanner input){
        int n = input.nextInt();
        if (n >= 1 && n % 5 == 0) {
            System.out.print("Valid number!");
        }
        else{
            System.out.print("Invalid number!");
        }
    }
    //Exervise 17
    public static double facturiel(Scanner input){
        int n = input.nextInt();
        int k = input.nextInt();
        int sumN = 1;
        int sumK = 1;
        if ( n > k && k > 1) {
            for (int i = n; i >= 1; i--) {
                if ( k == i ){
                    sumK = sumK * i;
                    k--;
                }
                sumN = sumN * i;
            }
        }
        return ((double) sumN /sumK);
    }

    //Exervise 18
    public static double facturiel2(Scanner input){
        int n = input.nextInt();
        int k = input.nextInt();
        int sumN = 1;
        int sumK = 1;
        int sumNK = 1;

        int m = n-k;
        if ( n > k && k > 1) {
            for (int i = n; i >= 1; i--) {
                sumN = sumN * i;
                if ( m == i ){
                    m--;
                    sumNK = sumNK * i;
                }
            }
            for (int j = k; j >= 1; j--) {
                sumK = sumK * j;
            }
        }
        return ((double) sumN*sumK)/sumNK;
    }
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        higherLower(input);
        int sum  = sum(input);
        System.out.println("The sum is " + sum);
        writingStop(input);
        dividedBy10(input);
        timeNow(input);
        isValid(input);
        System.out.println(facturiel(input));
        System.out.println(facturiel2(input));

    }
}
