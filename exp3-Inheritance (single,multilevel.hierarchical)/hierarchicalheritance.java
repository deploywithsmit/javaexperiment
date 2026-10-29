class Parent {
    void displayParent() {
        System.out.println("This is the Parent class.");
    }
}

class Child1 extends Parent {
    void displayChild1() {
        System.out.println("This is Child1 class.");
    }

}

class Child2 extends Parent {
    void displayChild2() {
        System.out.println("This is Child2 class.");
    }
}

public class Hierarchical {
    public static void main(String[] args) {
        Child1 obj1 = new Child1();

        System.out.println();
        System.out.println("Calling methods from Child1 object:");
        obj1.displayParent();
        obj1.displayChild1();
        System.out.println();
        
        Child2 obj2 = new Child2();
        
        System.out.println("Calling methods from Child2 object:");
        obj2.displayParent();
        obj2.displayChild2();
        System.out.println();
    }   
}