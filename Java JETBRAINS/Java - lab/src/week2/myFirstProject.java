package week2;

import java.util.Scanner;

public class myFirstProject {
    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);
        String name = scanner.nextLine();
        String date = scanner.nextLine();
        int age = Integer.parseInt(scanner.nextLine());

        System.out.printf("Ime %s, %d, data na rajdane %s", name, age, date);
    }
}
