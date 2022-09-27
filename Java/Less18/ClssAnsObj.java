package Less18;

//import java.util.jar.Attributes.Name;

public class ClssAnsObj {
    public static void main(String[] args) {
        Person pers1 = new Person();

        pers1.setName("");
        pers1.setAge(12);

        System.out.println("Выводим значение в main методе: " + pers1.getName() + ", " + pers1.getAge());

        pers1.speak();
    }
}

class Person{
    private String Name;
    private int Age;

    public void setName (String userName) {
        if (userName.isEmpty()) {
            System.out.println("Пустое значение");
        }
        else
            Name = userName;
    }

    public String getName () {
        return Name;
    }

    public void setAge (int userAge) {
        if (userAge < 0) {
            System.out.println("Возраст должен быть положительный");
        }
        else
            Age = userAge;
    }

    public int getAge () {
        return Age;
    }

    void speak(){
        System.out.println("Меня зовут " + Name + ", возраст: " + Age);
    }

    int calculateYersToRetirement() {
        int years = 65 - Age;       //Количество лет, оставшихся до пенсии
        return years;
    }

    void setNameAndAge(String namePerson, int agePerson) {
        Name = namePerson;
        Age = agePerson;
    }
}