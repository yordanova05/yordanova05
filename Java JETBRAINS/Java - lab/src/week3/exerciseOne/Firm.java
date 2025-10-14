package week3.exerciseOne;

public class Firm extends Company{
    private String companyOwner;
    private double startCapital;
    private double currentCapital;

    public Firm(){

    }
    public Firm( String nameCompany, String date, String bullstat, String companyOwner, double startCapital, double currentCapital){
        super(nameCompany,date,bullstat); // vika contructora na roditelskiq
        this.companyOwner = companyOwner;
        this.startCapital = startCapital;
        this.currentCapital = currentCapital;
    }

    public String getCompanyOwner() {
        return companyOwner;
    }
    public Double getStartCapital(){
        return startCapital;
    }
    public Double getCurrentCapital(){
        return currentCapital;
    }

    public String setCompanyOwner(String companyOwner){
        this.companyOwner = companyOwner;
        return companyOwner;
    }
    public Double setStartCapital( Double startCapital){
        this.startCapital = startCapital;
        return startCapital;
    }
    public Double setCurrentCapital(Double currentCapital){
        this.currentCapital = currentCapital;
        return currentCapital;
    }

    public double getStatus(){
        return currentCapital - startCapital;
    }

//    public static void main(String[] args){
//        Firm firm = new Firm();
//    }
}
