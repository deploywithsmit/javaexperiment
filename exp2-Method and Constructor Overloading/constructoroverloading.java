class Employee {
    int id;
    String name;

    Employee() {
        id = 0;
        name = "Unknown";

    }

    Employee(int i, String n) {
        id = i;
        name = n;
    }

    void display() {
        System.out.println("ID = " + id);
        System.out.println("Name = " + name);
    }

    public static void main(String[] args) {
        Employee e1 = new Employee();
        Employee e2 = new Employee(69, "Suyog");
        Employee e3 = new Employee(59, "Durvesh");
        System.out.println();
        e1.display();
        System.out.println();
        e2.display();
        System.out.println();
        e3.display();
        System.out.println();
    }
}