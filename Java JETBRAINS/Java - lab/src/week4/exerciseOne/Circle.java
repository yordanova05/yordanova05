package week4.exerciseOne;

public class Circle extends Shape {
    private double radius;

    public Circle(){

    }

    public Circle(String color, double radius){
        super(color);
        this.radius = radius;
    }
    public double getRadius(double radius){
        return radius;
    }
    public double setRadius(double radius){
        this.radius = radius;
        return radius;
    }
    @Override
    public double area(){
        return Math.PI*radius*radius;
    }
    @Override
    public double perimeter(){
        return Math.PI*2*radius;
    }
    @Override
    public String name(){
        return "Circle";

    }
}
