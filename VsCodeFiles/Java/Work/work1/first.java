package Work.work1;

public class first {
    public static void main(String[] args){
        Circle c1 = new Circle(3);
        System.out.println("�����"+ c1.getArea() + "  �ܳ���" + c1.getPerimeter());
    }
}

class Circle{
    final double PI = 3.14156926;
    double r;
    public Circle(double r){
        this.r = r;
    }

    public double getPerimeter(){
        return 2.0*PI*r;
    }

    public double getArea(){
        return r*r*PI;
    }

}