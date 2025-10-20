package week4.exerciseOne;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Shape circle1 = new Circle("blue", 3);
        Shape rectangle1 = new Rectangle("red", 4, 5.2);
        Shape[] shapes = {circle1,rectangle1};

        for (Shape shape: shapes){
            shape.displayColor();
            System.out.printf("Shape: %s, Area: %.2f, Parameter: %.2f\n", shape.name(), shape.area(), shape.perimeter());
        }
    }
}
