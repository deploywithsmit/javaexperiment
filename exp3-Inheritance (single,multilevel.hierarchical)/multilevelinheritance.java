class Grandparent {
    void displayGrandparent() {
        System.out.println("This is the Grandparent class.");
    }
}

class Parent extends Grandparent {
    void displayParent() {
        System.out.println("This is the Parent class.");
    }
}

class Child extends Parent {
    void displayChild() {
        System.out.println("This is the Child class.");
    }
}

public class Multilevel {
    public static void main(String[] args) {
        Child obj = new Child();
        obj.displayGrandparent();
        obj.displayParent();
        obj.displayChild();

    }
}