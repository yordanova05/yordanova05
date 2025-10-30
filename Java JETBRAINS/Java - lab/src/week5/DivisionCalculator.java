package week5;
import java.util.InputMismatchException;
import java.util.Scanner;

import java.util.Scanner;

public class DivisionCalculator {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while(true) {

            try {

                System.out.print("Enter a number a: ");
                int a = input.nextInt();
                System.out.print("Enter a number b ( -1 to end the program ): ");
                int b = input.nextInt();

                if (b == -1) {
                    System.out.println("The program has ended!");
                    break;
                }
                System.out.println("Division:" + a / b);

            } catch (ArithmeticException e) {
                System.out.println("You can't divide by 0!");
            } catch (InputMismatchException e) {
                System.out.println("You must enter number!");
                input.nextLine();
            } finally {
                System.out.println("The operation has ended!");
            }
        }
    }
}
