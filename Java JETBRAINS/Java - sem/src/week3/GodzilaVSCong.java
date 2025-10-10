package week3;

import java.util.Scanner;

public class GodzilaVSCong {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        float finalBudget = 0;

        System.out.print("Enter the number of budget: ");
        float budget = input.nextFloat();
        System.out.print("Enter the number of statists: ");
        int statists = input.nextInt();
        System.out.print("Enter the price for cloth: ");
        float price = input.nextFloat();
        finalBudget += budget*10/100;

        if ( statists >= 150 ) {
            finalBudget += price*statists- price*statists*10/100;
        }
        if ( finalBudget > budget ) {
            System.out.printf("Not enough money!\n" +
                    "Wingard needs %f leva more.\n",finalBudget-budget);
        }
        else if ( finalBudget <= budget && finalBudget >0 && budget > 0 ) {
            System.out.printf("Action!\n" +
                    "Wingard starts filming with {%.2f} leva left.\n", budget-finalBudget);
        }
    }
}
