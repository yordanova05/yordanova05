package week2;

import java.util.Scanner;

public class mySecondProject {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = Integer.parseInt(scanner.nextLine());
        int b = Integer.parseInt(scanner.nextLine());

        int s = a*b;
        System.out.println("Lice: "+s);
    }
}
