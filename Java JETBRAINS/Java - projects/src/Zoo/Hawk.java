package Zoo;

public class Hawk extends Animal{
    protected int wingsWidth;
    protected String gender;
    protected boolean isTrained;

    public Hawk(int age, String name, String breed, String color, int weight, int wingsWidth, String gender, boolean isTrained) {
        super(name, breed,age,color,weight);
        this.wingsWidth = wingsWidth;
        this.gender = gender;
        this.isTrained = isTrained;
    }
    public int getWingsWidth(int wingsWidth){
        return wingsWidth;
    }
    public int setWingsWidth(int wingsWidth){
        this.wingsWidth = wingsWidth;
        return wingsWidth;
    }
    public String getGender(String gender){
        return gender;
    }
    public String setGender(String gender){
        this.gender = gender;
        return gender;
    }
    public boolean getIsTrained(boolean isTrained){
        return isTrained;
    }
    public boolean setIsTrained(boolean isTrained){
        this.isTrained = isTrained;
        return isTrained;
    }
    @Override
    public void animalToString(){
        System.out.printf("Animal: Hawk {%s} Name: {%s} Age: {%d} Color: {%s} Weight: {%d} kg\n", name, breed, age, color, weight);
    }
    @Override
    public void name(String name){
        System.out.println("Hawk name is "+name);
    }
    @Override
    public void age(int age){
        System.out.println("Hawk age is "+age);
    }
    @Override
    public void breed(String breed){
        System.out.println("Hawk breed is "+breed);
    }
    @Override
    public void weight(int weight) {
        System.out.println("Hawk weight is " + weight);
    }
    @Override
    public void makeSound() {
        System.out.printf("Hawk {%s} crows!", name);
    }
    public void feed(String food){
        if (food.equals("meat") || food.equals("fish") || food.equals("berries")) {
            System.out.printf("Hawk {%s} crows after you fed it!\n", name);
        }
        else{
            System.out.printf("Hawk {%s} can't be fed with {%s}!\n", name, food);
        }
    }
}
