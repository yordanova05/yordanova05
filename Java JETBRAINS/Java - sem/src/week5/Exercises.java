package week5;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Scanner;
public class Exercises {

    public static ArrayList addElemArray() {
        ArrayList<Integer> numbers = new ArrayList<Integer>();
        for (int i = 0; i < 5; i++) {
            numbers.add(i);
        }
        return numbers;
    }

    public static double avarigeArray(Scanner input) {
        ArrayList<Integer> numbers = new ArrayList<>();
        double sum = 0;
        for (int i = 0; i < 5; i++) {
            int a = input.nextInt();
            numbers.add(a);
            sum += a;
        }
        return (double) (sum / numbers.size());
    }

    public static double maxNumber(ArrayList<Integer> numbers) {
        int maxNumber = numbers.get(0);
        for (Integer number : numbers) {
            if (maxNumber < number) {
                maxNumber = number;
            }
        }
        return maxNumber;
    }

    public static int sumArray(ArrayList<Integer> numbers) {
        int sum = 0;
        for (Integer number : numbers) {
            sum += number;
        }
        return sum;
    }

    public static void sortingStringsLength(int n, Scanner input) {
        String[] strings = new String[n];
        for (int i = 0; i < n; i++) {
            String string = input.nextLine();
            strings[i] = string;
        }
        Arrays.sort(strings);

        for (String string : strings) {
            System.out.println(string);
        }
    }

    public static void arrayIndexOf(int[] numbers, int number) {
        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] == number) {
                System.out.println("Number found on : " + i);
            }
        }
    }

    public static void posNegNumbers(int[] numbers) {
        int positive = 0;
        int negative = 0;
        for (int number : numbers) {
            if (number > 0) {
                positive++;
            } else if (number < 0) {
                negative++;
            }
        }
        System.out.println(positive + " " + negative);
    }

    public static void matchNumbers(int[] numbers1, int[] numbers2) {
        for (int i = 0; i < numbers1.length; i++) {
            for (int j = 0; j < numbers2.length; j++) {
                if (numbers1[i] == numbers2[j]) {
                    System.out.println("Founded in all masives" + numbers1[i]);
                }
            }
        }
    }

    public static void reverseArray(int[] numbers) {
        for (int i = numbers.length; i > numbers.length / 2; i--) {
            int n = numbers[i - 1];
            numbers[i - 1] = numbers[numbers.length - i];
            numbers[numbers.length - i] = n;
        }
        for (Integer n : numbers) {
            System.out.println(n);
        }
    }

    public static int[] deletingNumber(int[] numbers, int number) {
        int count = numbers.length;
        for (int i = 0; i < numbers.length; i++) {
            if (number == numbers[i]) {
                count--;
            }
        }
        int[] newNumbers = new int[count];
        for (int i = 0; i < newNumbers.length; i++) {
            if (number != numbers[i]) {
                newNumbers[i] = numbers[i];
            }
        }
        return newNumbers;
    }

    public static void sortArray(int[] numbers) {
        int n = numbers.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (numbers[j] < numbers[i]) {
                    // разменяме
                    int temp = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = temp;
                }
            }
        }
        for (Integer m : numbers) {
            System.out.println(m);
        }
    }

    public static void duplicatesList(String[] strings) {
        for (int i = 0; i < strings.length; i++) {
            for (int j = i + 1; j <= strings.length - 1; j++) {
                if (strings[i].equals(strings[j])) {
                    System.out.println("Founded duplicate " + strings[i]);
                    break;
                }
            }
        }
    }

    public static void isPalindrom(int[] numbers) {
        int count = 0;
        for (int i = 0; i < numbers.length / 2; i++) {
            if (numbers[i] == numbers[numbers.length - i - 1]) {
                count++;
            }
        }
        if (count == numbers.length / 2) {
            System.out.println("The array is a palindrom");
        }
    }

    public static void reverseKPositions(int[] numbers, int k) {
        int[] newArray = new int[numbers.length];
        if (k > numbers.length) {
            System.out.println("The k is bigger then array length");
        }

        for (int i = 0; i < k; i++) {
            newArray[i] = numbers[numbers.length - k + i];
        }
        for (int i = 0; i < numbers.length - k; i++) {
            newArray[k + i] = numbers[i];
        }

        System.out.println("Завъртян масив: " + Arrays.toString(newArray));

    }

    public static int secondMaxNumber(int[] numbers) {
        int maxNumber = numbers[0];
        int secMaxNumber = numbers[1];
        for (int number : numbers) {
            if (number > maxNumber) {
                secMaxNumber = maxNumber;
                maxNumber = number;
            } else if (number > secMaxNumber && number != maxNumber) {
                secMaxNumber = number;
            }
        }
        return secMaxNumber;
    }
    public static void unionIntersection(ArrayList<Integer> n1, ArrayList<Integer> n2) {
        ArrayList <Integer> union1= n1;
        ArrayList<Integer> intersection = new ArrayList<Integer>();
        ArrayList<Integer> union2= n2;

        for(Integer n:n1){
            for(Integer m: n2){
                if(m.equals(n)){
                    intersection.add(n);
                }
            }
        }
        union1.removeAll(intersection);
        union2.removeAll(intersection);

        System.out.println("union1:"+ union1);
        System.out.println("intersection1:"+ intersection);
        System.out.println("union2:"+ union2);
    }

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        ArrayList<Integer> numbers = addElemArray();
        System.out.println("Average:" + avarigeArray(input));
        System.out.println("Max number:" + maxNumber(numbers));
        System.out.println("Sum of n elements: " + sumArray(numbers));
        sortingStringsLength(5, input);
        arrayIndexOf(new int[]{3,6,-7,8,9,-23}, 8);
        posNegNumbers(new int[]{3,6,-7,8,9,-23});
        matchNumbers(new int[]{3,6,-7,8,9,-23}, new int[]{3,16,-17,8,19,-23});
        reverseArray(new int[]{23,6,2,5,9,0,-1});
        int[] numbers3 = deletingNumber(new int[]{23,6,2,2,2,5,9,0,-1}, 2);
        sortArray(new int[] {2,6,4,8,1,3,5,7,9});
        duplicatesList(new String[] {"a","b","c","b","e","a","a"});
        isPalindrom( new int[] {1,2,3,2,1});
        reverseKPositions(new int[] {1,2,3,4,5}, 2);
        System.out.println(secondMaxNumber(new int[] {5,4,3,1,2}));
        ArrayList<Integer> list1 = new ArrayList<>(Arrays.asList(2, 4, 5, 6));
        ArrayList<Integer> list2 = new ArrayList<>(Arrays.asList(1, 4, 2, 3));
        unionIntersection( list1, list2);
    }
}
