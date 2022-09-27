package Less14_15_16_17;

public class ClassesAndObjects {
    public static void main(String[] args) {
        Person pers1 = new Person();                        //Less14
        pers1.Name = "Роман";
        pers1.Age = 50;
        System.out.println("Меня зовут " + pers1.Name + ", возраст: " + pers1.Age);

        Person pers2 = new Person();
        pers2.Name = "Павел";
        pers2.Age = 20;
        System.out.println("Меня зовут " + pers2.Name + ", возраст: " + pers2.Age);

        System.out.println();                               //Less15
        pers1.sayHello();
        pers1.speak();
        pers2.sayHello();
        pers2.speak();

        System.out.println();                               //Less16
        int years1 = pers1.calculateYersToRetirement();
        int years2 = pers2.calculateYersToRetirement();
        System.out.println(pers1.Name + " будет работать до пенсии " + years1 + " лет");
        System.out.println(pers2.Name + " будет работать до пенсии " + years2 + " лет");

        System.out.println();                               //less17
        pers1.setName("Пётр");
        String s1 = "Еремей";
        pers2.setName(s1);
        pers1.speak();
        pers2.speak();

        System.out.println();                               //less17
        pers1.setNameAndAge("Генадий", 51);
        String s2 = "Валерий";
        pers2.setNameAndAge(s2, 21);
        pers1.speak();
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

    int calculateYersToRetirement() {
        int years = 65 - Age;       //Количество лет, оставшихся до пенсии
        return years;
    }

    void setName(String namePerson) {
        Name = namePerson;
    }

    void setNameAndAge(String namePerson, int agePerson) {
        Name = namePerson;
        Age = agePerson;
    }
}