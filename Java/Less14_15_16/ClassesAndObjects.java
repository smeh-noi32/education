package Less14_15_16;

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

        System.out.println();
        int years1 = pers1.calculateYersToRetirement();
        int years2 = pers2.calculateYersToRetirement();
        System.out.println(pers1.Name + " будет работать до пенсии " + years1 + " лет");
        System.out.println(pers2.Name + " будет работать до пенсии " + years2 + " лет");
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

    int calculateYersToRetirement() {
        int years = 65 - Age;       //Количество лет, оставшихся до пенсии
        return years;
    }
}