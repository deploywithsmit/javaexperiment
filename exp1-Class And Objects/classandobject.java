class Employee {
    int empId;
    String empName;
    double salary;

    void display() {
        System.out.println("Employee ID: " + empId);
        System.out.println("Employee Name: " + empName);
        System.out.println("Salary: " + salary);
    }

    public static void main(String[] args) {
        Employee e1 = new Employee();
        e1.empId = 69;
        e1.empName = "Suyog";
        e1.salary = 100000;
        e1.display();
    }
}