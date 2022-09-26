package Less13;

public class Multidimensional_arr {
    public static void main(String[] args) {
        int[] numbers = {1, 2, 3};      //Инициализация одномерного массива с заполнением элементов

        int[][] matrix = {{1, 2, 3, 4, 5},      //Инициализация двумерного массива с заполнением элементов
                          {4},
                          {7, 8, 9}};
        
        System.out.println(numbers[2]);     //Отображение одномерного массива

        System.out.println();
        System.out.println(matrix[0][4]);     //Отображение двумерного массива
        System.out.println(matrix[1][0]);
        System.out.println(matrix[2][2]);

        for ( int i = 0; i < matrix.length ; i++){
            for ( int j = 0; j < matrix[i].length; j++){
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        int[] numbers1 = new int[5];        //Инициализация одномерного массива без заполнения элементов

        String[][] strings = new String[3][4];      //Инициализация одномерного массива без заполнения элементов
        strings[0][1] = "Привет";
        System.out.println();
        System.out.println(strings[0][1]);
    }
}
