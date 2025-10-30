package week5;

import java.util.Scanner;

public class StudentGrades {
    public static void validateGrade(int grade) throws InvalidGradeException{
        if (grade > 6 || grade < 2) {
            throw new InvalidGradeException("Grade must be between 2 - 6");
        }
    }
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        while(true){
            try {
                int grade = input.nextInt();
                if ( grade == 0){
                    System.out.println("Program ended!");
                    break;
                }
                validateGrade(grade);
                System.out.println("Grade: " + grade);
            }
            catch(InvalidGradeException e){
                System.out.println(e.getMessage());
            }
            catch(Exception e){
                System.out.println("Exception captured!");
            }
        }
    }
}
