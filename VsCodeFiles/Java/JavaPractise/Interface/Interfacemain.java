//�ӿڵ���ϰ
package JavaPractise.Interface;

public class Interfacemain {
    public static void main(String[] args){
        China zhang;
        Japan sanbeng;
        zhang = new China();
        sanbeng = new Japan();
        zhang.number = 32 + Computable.MAX;
        sanbeng.number = 14 + Computable.MAX;
        System.out.println("zhang ��ѧ��" + zhang.number + "zhang����ͽ��" + zhang.f(100));
        System.out.println("sanbeng��ѧ��" + sanbeng.number + "sanbeng����ͽ��" + sanbeng.f(100));
    }
}
