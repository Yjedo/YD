package Work.work1;

interface Water{
    void water();
}

interface  Land{
    void land();
}

abstract class animal {
    //����
    String name;
    //����״̬
    boolean status;
    //����
    String kind;
    //�Ƿ�ʳ��
    boolean isEatingMeat;
    //�����
    String livingEnvironment;
    //����
    abstract void cry();
}

class Dog extends animal implements Land{

    String name;

    @Override
    public void land() {
        System.out.println("�����ڵ����ܣ�");
    }

    @Override
    void cry() {
        //������ʱ
        if (super.status){
            System.out.println("������");
        }
        else{
            System.out.println("������");
        }
    }

    //������
    public void isTouch(){
        System.out.println("��ֻ���������ú����");
        super.status = true;
    }

    //������
    public void isFrighten(){
        System.out.println("���ŵ���ֻ����");
        super.status = false;
    }

    //���˴��к�
    public void greetSb(){
        System.out.println("ҡҡβ��");
    }

    public void setName(String name){
        this.name = name;
        System.out.println(this.name + super.name);
    }

    public Dog(){
        super.name = "dog";
        //Ĭ��״̬����
        super.status = true;
        //��ʳ��
        super.isEatingMeat = true;
        //������
        super.kind = "mammal";
        //½��
        super.livingEnvironment = "land";
    }
}

class Cat extends animal implements Land{

    @Override
    public void land() {
        System.out.println("�����ڵ����ܣ�");
    }

    @Override
    void cry() {
        //������ʱ
        if (super.status){
            System.out.println("���๾��");
        }
        else{
            System.out.println("˻˻˻");
        }
    }

    //������
    public void isTouch(){
        System.out.println("��ֻè�������ú����");
        super.status = true;
    }

    //������
    public void isFrighten(){
        System.out.println("���ŵ���ֻè��");
        super.status = false;
    }

    //���˴��к�
    public void greetSb(){
        System.out.println("��~");
    }

    public void setName(String name){
        this.name = name;
    }

    public Cat(){
        super.name = "cat";
        //Ĭ��״̬����
        super.status = true;
        //��ʳ��
        super.isEatingMeat = true;
        //������
        super.kind = "mammal";
        //½��
        super.livingEnvironment = "land";
    }
}

class Frog extends animal implements Land, Water{

    @Override
    public void water() {
        System.out.println("������ˮ����");
    }

    @Override
    public void land() {
        System.out.println("�����ڵ�����");
    }

    @Override
    void cry() {
        if (super.status){
            System.out.println("������");
        }
        else{
            System.out.println("��ͨһ������ˮ��");
        }
    }

    //������
    public void isFrighten(){
        super.status = false;
    }

    public Frog(){
        super.name = "frog";
        //Ĭ��״̬����
        super.status = true;
        //����ʳ��
        super.isEatingMeat = false;
        //������
        super.kind = "amphibian";
        //½��
        super.livingEnvironment = "land";
    }
}

public class third {
    public static void main(String[] args){
        Dog dog = new Dog();
        Cat cat = new Cat();
        dog.greetSb();
        dog.cry();
        dog.isFrighten();
        cat.cry();
        cat.greetSb();
        cat.cry();
        cat.isFrighten();
        cat.cry();
    }
}

