package JavaTest;

import java.util.Date;
public class MyDate {
    public static void main(String[] args){
        // ��ʼ�� Date ����
       Date date = new Date();
        
       // ʹ�� toString() ������ʾ����ʱ��
       System.out.println(date.toString());
        //c��ʹ��  
    System.out.printf("ȫ�����ں�ʱ����Ϣ��%tc%n",date);          
    //f��ʹ��  
    System.out.printf("��-��-�ո�ʽ��%tF%n",date);  
    //d��ʹ��  
    System.out.printf("��/��/���ʽ��%tD%n",date);  
    //r��ʹ��  
    System.out.printf("HH:MM:SS PM��ʽ��12ʱ�ƣ���%tr%n",date);  
    //t��ʹ��  
    System.out.printf("HH:MM:SS��ʽ��24ʱ�ƣ���%tT%n",date);  
    //R��ʹ��  
    System.out.printf("HH:MM��ʽ��24ʱ�ƣ���%tR",date);  
    }  
}
