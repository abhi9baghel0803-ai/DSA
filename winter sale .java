import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double x = sc.nextDouble();
        double p = sc.nextDouble();

        double op = (p * 100) / (100 - x);

        System.out.printf("%.2f", op);
    }
}