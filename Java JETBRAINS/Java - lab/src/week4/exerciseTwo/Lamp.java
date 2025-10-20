package week4.exerciseTwo;

public class Lamp implements Switchable, Describable {
    private boolean isOn;
    public Lamp(){};
    public Lamp(boolean isOn) {
        this.isOn = isOn;
    }
    public boolean getisOn(boolean isOn){
        return isOn;
    }
    public boolean setisOn(boolean isOn){
        this.isOn = isOn;
        return isOn;
    }

    @Override
    public void turnOn(){
        this.isOn = true;
        System.out.println("Lampa On");
    }
    @Override
    public void turnOff(){
        this.isOn = false;
        System.out.println("Lampa Off");
    }
    @Override
    public void describe(){
        System.out.println("This is nastolna lampa!");
    }

}
