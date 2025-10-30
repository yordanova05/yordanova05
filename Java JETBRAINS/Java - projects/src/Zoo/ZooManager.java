package Zoo;
import java.util.ArrayList;
import java.util.Scanner;

public class ZooManager {
    final ArrayList<Animal> animals;

    public ZooManager() {
        animals = new ArrayList<>();
    }

    public void addAnimal(Animal a){
        try {
            if (a != null) {
                animals.add(a);
                System.out.println("Animal added to the Zoo");
            }
        }
        catch(NullPointerException e){
            System.out.println("Animal can't be null!");
        }
    }
    public void removeAnimal(Animal a) {
        if (animals.remove(a)) {
            System.out.println("Animal removed from the Zoo");
        } else {
            System.out.println("Animal doesn't exist in the Zoo!");
        }
    }
    public void feedAll(String food){
        if ( animals.isEmpty() ){
            throw new NullPointerException("No animals to feed!");
        }
        else {
            for (Animal animal : animals) {
                animal.feed(food);
            }
        }
    }
    public Animal findByName(String name) throws AnimalNotFoundException{
        for (Animal animal: animals){
            if( animal.name.equals(name)){
                System.out.println("Founded animal!");
                return animal;
            }
        }
        throw new AnimalNotFoundException("Animal not found with name: " + name);
    }
    public void feedByName(Scanner input, String name) throws AnimalNotFoundException{
        for (Animal animal: animals){
            if (animal.name.equals(name)) {
                System.out.println("What food can u give: ");
                String food = input.nextLine();
                animal.feed(food);
                return;
            }
        }
        throw new AnimalNotFoundException("Animal not found with name: " + name);
    }
}
