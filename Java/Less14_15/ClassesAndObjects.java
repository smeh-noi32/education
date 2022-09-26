package Less14_15;

public class ClassesAndObjects {
    public static void main(String[] args) {
        Person pers1 = new Person();
        pers1.Name = "Роман";
        pers1.Age = 50;
        System.out.println("Меня зовут " + pers1.Name + ", возраст: " + pers1.Age);

        Person pers2 = new Person();
        pers2.Name = "Павел";
        pers2.Age = 20;
        System.out.println("Меня зовут " + pers2.Name + ", возраст: " + pers2.Age);

        System.out.println();
        pers1.sayHello();
        pers1.speak();
        pers2.sayHello();
        pers2.speak();
    }
}

class Person{
    String Name;
    int Age;

    void speak(){
        System.out.println("Меня зовут " + Name + ", возраст: " + Age);
    }

    void sayHello(){
        System.out.println("Привет, ");
    }
}