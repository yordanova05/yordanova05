package week4.exerciseOne;

abstract class Shape {
    private String color;
    public Shape(){

    }
    public Shape(String color){
        this.color = color;
    }
    public String getColor(String color){
        return color;
    }
    public String setColor(String color){
        this.color = color;
        return color;
    }
    public abstract String name();
    public abstract double area();
    public abstract double perimeter();
    public void displayColor(){
        System.out.println("Color: "+ color);
    }
}
