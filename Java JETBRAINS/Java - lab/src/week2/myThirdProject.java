package week2;

import java.util.Scanner;

public class myThirdProject{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        String niz = input.nextLine();
        String[] nizove = niz.split(" ");

        for (String s : nizove){
            System.out.println(s);
        }

//        Scanner scanner = new Scanner(System.in);
//
//        String nizove = scanner.nextLine();
//        String[] nizovete = nizove.split(" ");
//
//        for( int i=0; i < nizovete.length; i++){
//            System.out.println(nizovete[i]);
//        }
    }
}
