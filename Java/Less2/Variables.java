package Less2;

public class Variables {
    public static void main(String[] args) {
        int myInt = 2147483647;
        short myShort = 32767;
        long myLong = 922337203685477580l;

        float myFloat = 3.4f;
        double myDouble = 1.7000000;

        char c = 'X';

        boolean b = true;

        byte myByte = 127;      // Диапазон чисел [-128; 127]

        System.out.println("int содержит числа от -2147483648 до " + myInt);
        System.out.println("short содержит числа от -32768 до " + myShort);
        System.out.println("long содержит числа от -9 223 372 036 854 775 808 до " + myLong);
        System.out.println();
        System.out.println("float содержит числа от -3.4E+38 до "+myFloat+"E+38");
        System.out.println("double содержит числа двойной точности от -1.7E+308 до "+myDouble+"E+308");
        System.out.println();
        System.out.println("char хранит одиночный символ в кодировке UTF-16 и занимает 2 байта. Например: "+ c);
        System.out.println();
        System.out.println("boolean содержит логические " + b + " или false");
        System.out.println();
        System.out.println("byte содержит числа от -128 до " + myByte);
        System.out.println();
    }
}