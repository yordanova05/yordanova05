package Zoo;

public class Monkey extends Animal{
    protected boolean isPlayful;
    protected int tailLong;

    public Monkey(String name, String breed, int age, String color,  int weight, boolean isPlayful, int tailLong){
        super(name, breed, age, color, weight);
        this.isPlayful = isPlayful;
        this.tailLong = tailLong;
    }
    public boolean getisPlayful(boolean isPlayful){
        return isPlayful;
    }
    public boolean setisPlayful(boolean isPlayful){
        this.isPlayful = isPlayful;
        return isPlayful;
    }
    public int getSpeed(int tailLong){
        return tailLong;
    }
    public int setSpeed(int tailLong){
        this.tailLong = tailLong;
        return tailLong;
    }
    @Override
    public void animalToString(){
        System.out.printf("Animal: Monkey {%s} Name: {%s} Age: {%d} Color: {%s} Weight: {%d} kg\n", name, breed, age, color, weight);
    }
    @Override
    public void name(String name){
        System.out.println("Monkey name is "+name);
    }
    @Override
    public void age(int age){
        System.out.println("Monkey age is "+age);
    }
    @Override
    public void breed(String breed){
        System.out.println("Monkey breed is "+breed);
    }
    @Override
    public void weight(int weight) {
        System.out.println("Monkey weight is " + weight);
    }
    @Override
    public void makeSound() {
        System.out.printf("Monkey {%s} uhu-haha!", name);
    }
    public void feed(String food){
        if (food.equals("banana") || food.equals("vegetables") || food.equals("nuts") || food.equals("seeds") || food.equals("leaves")) {
            System.out.printf("Monkey {%s} crows after you fed it!\n", name);
        }
        else{
            System.out.printf("Monkey {%s} can't be fed with {%s}!\n", name, food);
        }
    }
}
