package Less9;

public class Break_Continue {
    public static void main(String[] args) {
        
        int i = 0;

        while (true) {      //Условие бесконечного цикла
            i++;
            System.out.println("Строка "+i);
            if (i == 10){
                break;
            }
        }

        for ( i = 0; i <= 15; i++){
            if ( i%2 == 0){
                continue;
            }
            System.out.println(i+" число нечетное");
        }
    }
}
