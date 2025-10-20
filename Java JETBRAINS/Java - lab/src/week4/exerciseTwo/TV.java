package week4.exerciseTwo;

public class TV implements Switchable, Describable{
    private boolean isOn;
    public TV(){};
    public TV(boolean isOn){
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
        System.out.println("TV On");
    }
    @Override
    public void turnOff(){
        this.isOn = false;
        System.out.println("TV Off");
    }
    @Override
    public void describe(){
        System.out.println("This is a TV");
    }
}
