package Zoo;

public class Tiger extends Animal{
    protected int height;
    protected String gender;

    public Tiger(int age, String name, String breed, String color, int weight, int height, String gender) {
        super(name, breed,age,color,weight);
        this.height = height;
        this.gender = gender;
    }
    public int getHeight(int height){
        return height;
    }
    public int setHeight(int height){
        this.height = height;
        return height;
    }
    public String getGender(String gender){
        return gender;
    }
    public String setGender(String gender){
        this.gender = gender;
        return gender;
    }
    @Override
    public void animalToString(){
        System.out.printf("Animal: Tiger {%s} Name: {%s} Age: {%d} Color: {%s} Weight: {%d} kg\n", name, breed, age, color, weight);
    }
    @Override
    public void name(String name){
        System.out.println("Tiger name is "+name);
    }
    @Override
    public void age(int age){
        System.out.println("Tiger age is "+age);
    }
    @Override
    public void breed(String breed){
        System.out.println("Tiger breed is "+breed);
    }
    @Override
    public void weight(int weight) {
        System.out.println("Tiger weight is " + weight);
    }
    @Override
    public void makeSound() {
        System.out.printf("Tiger {%s} growls!", name);
    }
    public void feed(String food){
        if (food.equals("meat")) {
            System.out.printf("Tiger {%s} growls after you fed it!\n", name);
        }
        else{
            System.out.printf("Tiger {%s} can't be fed with {%s}!\n", name, food);
        }
    }
}
