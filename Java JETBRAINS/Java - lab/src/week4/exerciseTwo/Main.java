package week4.exerciseTwo;

public class Main {
    public static void main(String[] args){
        Lamp lamp1 = new Lamp();
        TV tv1 = new TV();
        Lamp lamp2 = new Lamp();
        TV tv2 = new TV();
        Switchable[] objects = {lamp1, tv1, lamp2, tv2};

        for ( Switchable object : objects ) {
            object.turnOn();
            ((Describable)object).describe();
        }
    }
}
