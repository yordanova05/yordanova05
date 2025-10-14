package week3.exerciseTwo;
import java.util.*;

public class Car {
    private String brand;
    private String model;
    private String color;
    private int power;
    private String typeEngine;
    private String typeGearBox;
    private int year;

    public Car(){

    }
    public Car(String brand, String model, String color, int power, String typeEngine, String typeGearBox, int year){
        this.brand = brand;
        this.model = model;
        this.color = color;
        this.power = power;
        this.typeEngine = typeEngine;
        this.typeGearBox = typeGearBox;
        this.year = year;
    }
    public String getBrand(String brand){
        return brand;
    }
    public String getModel(String model){
        return model;
    }
    public String getColor(String color){
        return color;
    }
    public int getPower(int power){
        return power;
    }
    public String getTypeEngineBox(String typeEngine){
        return typeEngine;
    }
    public String getTypeGearBox(String typeGearBox){
        return typeGearBox;
    }
    public int getYear(int year){
        return year;
    }

    public String setBrand(String brand){
        this.brand = brand;
        return brand;
    }
    public String setModel(String model){
        this.model = model;
        return model;
    }
    public String setColor(String color){
        this.color = color;
        return color;
    }
    public int setPower(int power){
        this.power = power;
        return power;
    }
    public String setTypeEngine(String typeEngine){
        this.typeEngine = typeEngine;
        return typeEngine;
    }
    public String setTypeGearBox(String typeGearBox){
        this.typeGearBox = typeGearBox;
        return typeGearBox;
    }
    public int setYear(int year){
        this.year = year;
        return year;
    }

    public String[] sortedByChar( String[] cars, char a){
        int count = 0;
        for ( String car:cars){
            if (car.charAt(0) == a){
                count++;
            }
        }
        String[] sortedCars = new String[count];
        count = 0;
        for (String car: cars){
            if ( car.charAt(0) == a){
                sortedCars[count++] = car;
            }
        }
        return sortedCars;
    }

    public String[] sortedByType( String[] cars, String type){
        List<String> carsList = Arrays.asList(cars);
        if ( type.equalsIgnoreCase("ascending")){
             Collections.sort(carsList);
        }
        else if( type.equalsIgnoreCase("descending")){
             Collections.sort(carsList, Collections.reverseOrder());
        }
        return carsList.toArray(new String[0]);
    }
    public String[] existedCarsList( String[] cars){
        int countUnique = 0;
        for ( int i = 0; i  < cars.length; i++){
            for ( int j = 0; j < i; j++){
                if ( cars[i].equals(cars[j])) {
                    break;
                }
                else{
                    countUnique++;
                }
            }
        }
        String[] newCars = new String[countUnique];
        countUnique = 0;

        for ( int i = 0; i  < cars.length; i++){
            boolean isDuplicated = false;
            for ( int j = 0; j < i; j++){
                if ( cars[i].equals(cars[j]) ){
                    isDuplicated = true;
                    break;
                }
            }
            if(!isDuplicated){
                newCars[countUnique] = cars[i];
                countUnique++;
            }
        }
        return newCars;
    }
    public static void main(String [] args){
        Car car1 = new Car();

        String[] cars = {"Toyota", "BMW", "Audi","Peugeot", "Renault", "Fiat", "Ferrary"};

        String[] sortedByChar = car1.sortedByChar(cars, 'F');
        String[] sortedAscending = car1.sortedByType(cars, "ascending");
        String[] sortedDescending = car1.sortedByType(cars, "descending");
        String[] uniqueCars = car1.existedCarsList(cars);

        System.out.println("Колите, започващи с 'F': " + Arrays.toString(sortedByChar));
        System.out.println("Сортирани възходящо: " + Arrays.toString(sortedAscending));
        System.out.println("Сортирани низходящо: " + Arrays.toString(sortedDescending));
        System.out.println("Без повтарящи се коли: " + Arrays.toString(uniqueCars));
    }
}
