import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
 
        int n = sc.nextInt();
 
        int years = n / 365;
        n = n % 365;
 
        int months = n / 30;
        int days = n % 30;
 
        System.out.println(years + " years");
        System.out.println(months + " months");
        System.out.println(days + " days");
    }
}
