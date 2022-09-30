package Less24;

public class classObject {
    public static void main(String[] args) {
        Human h1 = new Human ("Harry", 17);
        System.out.println(h1);
    }
}

class Human {
    private String name;
    private int age;

    public Human (String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String toString() {          //Переопределяем встроенный метод toString для требуемого отображения объекта
        return name + ", " + age;
    }
}