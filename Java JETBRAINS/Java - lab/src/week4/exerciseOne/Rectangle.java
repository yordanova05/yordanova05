package week4.exerciseOne;

public class Rectangle extends Shape {
    private double width;
    private double height;
    public Rectangle(){

    }
    public Rectangle(String color,double width, double height){
        super(color);
        this.width = width;
        this.height = height;
    }
    public double getWidth(double width){
        return width;
    }
    public double getHeight(double height){
        return height;
    }
    public double setWidth(double width){
        this.width = width;
        return width;
    }
    public double setHeight(double height){
        this.height = height;
        return height;
    }

    @Override
    public double area(){
        return width*height;
    }
    @Override
    public double perimeter(){
        return 2*width + 2*height;
    }
    @Override
    public String name(){
        return "Rectangle";
    }
}
