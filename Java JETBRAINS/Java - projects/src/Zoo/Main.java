package Zoo;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        Animal hawk1 = new Hawk(8,"Roshko","American","black",15,60,"male",true);
        Animal monkey1 = new Monkey("Maya","Babun",3,"grey",7,false,17);
        Animal tiger1 = new Tiger(11,"Sun","African kitty","orange",75,110,"female");
        Animal wolf1 = new Wolf("Snow","Wild Forest", 7,"white",59,87,42);

        ZooManager animals = new ZooManager();
        animals.addAnimal(hawk1);
        animals.addAnimal(monkey1);
        animals.addAnimal(tiger1);
        animals.addAnimal(wolf1);
        while(true){
            try{
                System.out.println("Welcome to Zoo!");
                System.out.println("To exit enter 0 otherwise enter 1");
                int choose = input.nextInt();
                input.nextLine();
                if(choose == 1){
                    animals.removeAnimal(wolf1);

                    animals.feedAll("meat");

                    Animal result = animals.findByName("Sun");
                    result.animalToString();

                    System.out.println("Enter name:");
                    String name = input.nextLine();
                    animals.feedByName(input, name);
                }
                else if(choose == 0){
                    break;
                }
                else{
                    System.out.println("Invalid choice olny 0 and 1 available!!!");
                }
            }
            catch(NumberFormatException e){
                System.out.println("Need specific type!");
            }
            catch (NullPointerException e){
                System.out.println("Null pointer!");
            }
            catch(Exception e){
                System.out.println(e.getMessage());
            }
            finally{
                System.out.println("Processes finished!");
            }
        }
    }
}
