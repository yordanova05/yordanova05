package week3;

import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int age = input.nextInt();
        String name = input.next(); // ako beshe nextLine shteshe da vzeme vsichko ot sled promenlivata za koqto e zadadeno
        int year = input.nextInt();

        System.out.println("Hello, " + name + "!" + "Age is " + age + " years old" + "Born year " + year);
    }
}
