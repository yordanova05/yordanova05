package Zoo;

public class Wolf extends Animal{
    protected int height;
    protected int speed;
    public Wolf(String name, String breed, int age, String color,  int weight, int height, int speed){
        super(name, breed, age, color, weight);
        this.height = height;
        this.speed = speed;
    }
    public int getHeight(int height){
        return height;
    }
    public int setHeight(int height){
        this.height = height;
        return height;
    }
    public int getSpeed(int speed){
        return speed;
    }
    public int setSpeed(int speed){
        this.speed = speed;
        return speed;
    }
    @Override
    public void animalToString(){
        System.out.printf("Animal: Wolf {%s} Name: {%s} Age: {%d} Color: {%s} Weight: {%d} kg\n", name, breed, age, color, weight);
    }
    @Override
    public void name(String name){
        System.out.println("Wolf name is "+name);
    }
    @Override
    public void age(int age){
        System.out.println("Wolf age is "+age);
    }
    @Override
    public void breed(String breed){
        System.out.println("Wolf breed is "+breed);
    }
    @Override
    public void weight(int weight) {
        System.out.println("Wolf weight is " + weight);
    }
    @Override
    public void makeSound() {
        System.out.printf("Wolf {%s} howls!", name);
    }
    public void feed(String food){
        if (food.equals("meat")) {
            System.out.printf("Wolf {%s} howls after you fed it!\n", name);
        }
        else{
            System.out.printf("Wolf {%s} can't be fed with {%s}!\n", name,food);
        }
    }
}
