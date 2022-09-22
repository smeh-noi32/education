package Less8;

import java.util.Scanner;
public class DoWhile {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int value;
        do {
            System.out.println("Введите число 5");
            value = s.nextInt();
        } while (value != 5);
        System.out.println("Вы ввели 5");
    }
}