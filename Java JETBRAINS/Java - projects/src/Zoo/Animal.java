package Zoo;

public abstract class Animal implements Feedable{
    protected String name;
    protected int age;
    protected int weight;
    protected String breed;
    protected String color;

    public Animal(String name, String breed, int age, String color,  int weight) {
        this.weight = weight;
        this.name = name;
        this.breed = breed;
        this.age = age;
        this.color = color;
    }

    public abstract void animalToString();
    public abstract void name(String name);
    public abstract void age(int age);
    public abstract void breed(String breed);
    public abstract void weight(int weight);
    public abstract void makeSound();

}
