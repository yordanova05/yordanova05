package week3.exerciseOne;

public class Company {
    private String nameCompany;
    private String date;
    private String bullstat;

    public Company(){

    }

    public Company(String nameCompany, String date, String bullstat){
        this.nameCompany = nameCompany;
        this.date = date;
        this.bullstat = bullstat;
    }

    public String getNameCompany(){
        return nameCompany;
    }
    public String getDate(){
        return date;
    }
    public String getBullstat(){
        return bullstat;
    }
    public String setNameCompany(String nameCompany){
        this.nameCompany = nameCompany;
        return nameCompany;
    }
    public String setDate(String date){
        this.date = date;
        return date;
    }
    public String setBullstat(String bullstat){
        if ( bullstat.length() == 10){
            this.bullstat = bullstat;
            return bullstat;
        }
        else{
            return "The length needs to be 10 characters!!!";
        }

    }
}
