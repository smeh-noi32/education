package Less23;

public class Lesson23 {
    public static void main(String[] args) {
        String x = "Hello";
        x.toUpperCase();            //Метод, возвращающий (новую) строку в верхнем регистре. Не изменяет исходную строку.
        System.out.println(x);      //Неправильный пример использования .toUpperCase
        System.out.println(x.toUpperCase());        //Правильный пример использования .toUpperCase . Либо: "x = x.toUpperCase();"

        String string1 = "Hello";
        String string2 = ", my";
        String string3 = " dear friend";
        String stringAll = string1+string2+string3;     /*Создаётся строка новая (string1+string2),
                                                        к которой потом прибавляется строка 3, создавая строку (строка1_2+строка3)
                                                        Таким образом, для создания строки из строк, создаются ещё две дополнительные
                                                        строки, не используемые в последущем.
                                                        Такой метод неразумно использует память.*/
        System.out.println();
        System.out.println(stringAll);

        StringBuilder sb = new StringBuilder("Hello");      //StringBuilder - класс, позволяющий изменение значения строки
        sb.append(", my").append(" smart friend");      //.append() - метод, обновляющий значение объекта
        System.out.println();
        System.out.println(sb.toString());
    }
}
