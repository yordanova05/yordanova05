package week2;

import java.util.Scanner;

public class BMICalculator {
    public static void printIntroduction(){
        System.out.println("Introduction BMICalculator. This is ...");
    }

    public static double getBMI(Scanner input){
        System.out.println("Inches: ");
        double inches = Double.parseDouble(input.nextLine());
        double height = inches/0.3937;
        System.out.println("Pounds: ");
        double pounds = Double.parseDouble(input.nextLine());
        double weight = pounds/2.2046;

        return bmiFor(weight, height);
    }

    public static double bmiFor(double weight, double height){
        double BMI = 703*weight/(height*height);
        System.out.println("Body mass index: ");
        return BMI;
    }

    public static String getStatus(double index){
        if ( index < 18.5 && index > 0){
            System.out.println("Underweight!");
            return "underweight";
        }
        else if (index < 25){
            System.out.println("Normal!");
            return "normal";
        }
        else if (index < 30 ){
            System.out.println("Overweight!");
            return "overweight";
        }
        else{
            System.out.println("Obese!");
            return "obese";
        }
    }

    public static void ReportResults(int numberResult, double index, String status){
        double BMI = Math.round(index * 100.0) / 100.0;
        System.out.printf("Number %d has BMI ( %.2f ) and is %s\n", numberResult, BMI, status);
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        printIntroduction();
        System.out.print("Enter number: ");
        int number = Integer.parseInt(input.nextLine());
        double index = getBMI(input);
        String status = getStatus(index);
        ReportResults(number, index, status);
    }
}
