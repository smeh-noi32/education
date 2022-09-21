package Less5_6;

public class ForAndIf {
    public static void main(String[] args) {
        for (int i = 0; i <= 10; i++){
            if (i == 0) {
                System.out.println(i + " это 0");
            }
            else if (i % 2 == 0){
                System.out.println(i + " четное число");
            }
            else {
                System.out.println(i + " нечетное число");
            }
        }
    }
}
