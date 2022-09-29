package Less22;

public class Lesson22 {
    public static void main(String[] args) {
        System.out.println(Test.CONSTANT);
        //Test.CONSTANT = 20;           //В данной строке кода возникает ошибка, т.к. переменные "final" изменению не подлежат
    }
}

class Test {
    public static final int CONSTANT = 10;
}

// final - не можем изменит значение или преусвоить другое значение (констант) это последнее значение
// константы все с большой буквы 
// Сеттеры мы не можем создать в константе(final)