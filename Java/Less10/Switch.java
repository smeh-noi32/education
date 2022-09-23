package Less10;

import java.util.Scanner;

public class Switch {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        boolean b = true;

        do {
            System.out.println("Ввыедите ваш возраст:");
            String age = s.nextLine();
            switch (age) {
                case "0":
                    System.out.println("Поздравляю с рождением!");
                    b = false;
                    break;
                case "7":
                    System.out.println("Вы пошли в школу!");
                    b = false;
                    break;

                case "18":
                    System.out.println("Вы закончили школу!");
                    b = false;
                    break;

                default:
                    System.out.println("Я не знаю такой возраст");
                    break;
            }
        } while (b == true);
    }
}
