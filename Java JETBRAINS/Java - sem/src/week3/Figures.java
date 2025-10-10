package week3;
import java.util.Scanner;
public class Figures {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        System.out.print("Enter figure name: ");
        String figureName = input.nextLine().toLowerCase();
        switch(figureName){
            case "square":
                System.out.print("Enter a: ");
                int a = input.nextInt();
                System.out.println("Area:" + a*a);
                break;
            case "rectangle":
                System.out.print("Enter n: ");
                int n = input.nextInt();
                System.out.print("Enter b: ");
                int m = input.nextInt();
                System.out.println("Area:" + n*m);
                break;
            case "circle":
                System.out.print("Enter r: ");
                int r = input.nextInt();
                System.out.println("Area:" + 2*Math.PI*Math.pow(r,2));
                break;
            case "triangle":
                System.out.print("Enter r: ");
                int c = input.nextInt();
                System.out.print("Enter h: ");
                int h = input.nextInt();
                System.out.println("Area:" + (c*h)/2);
                break;
        }
    }
}
