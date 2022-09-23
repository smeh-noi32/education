package Less12;

public class ForEach {
    public static void main(String[] args) {
        String[] strngs = new String[3];
        strngs[0] = "Привет";
        strngs[1] = "этому";
        strngs[2] = "уроку!";
        for (int i = 0; i < strngs.length; i++) {
            System.out.println(strngs[i]);
        }

        System.out.println();

        for (String strBuf : strngs) {
            System.out.println(strBuf);
        }

        int[] values = {2, 4, 16};
        int sum = 0;
        for (int i : values) {
            sum += i;
        }
        System.out.println();
        System.out.println(sum);
    }
}
