package PractiseDemo;

import java.util.concurrent.Callable;
import java.util.concurrent.FutureTask;

public class ThreadDemo {
    public static void main(String[] args){

        MyThread1 myThread = new MyThread1();
        MyRunAble myRunAble = new MyRunAble();
        MyCallAble myCallAble = new MyCallAble();
        FutureTask<Integer> futureTask = new FutureTask<>(myCallAble);

        myThread.start();
        new Thread(futureTask, "ThreadC").start();
        new Thread(myRunAble, "ThreadA").start();;
        new Thread(myRunAble, "ThreadB").start();;

        for(int i = 0; i < 100; i++){
            System.out.println(Thread.currentThread().getName());
        }

        System.out.println("futureTask is: " + futureTask);
    }
    
}

//ͨ���̳�Thread�࣬�����߳�
class MyThread1 extends Thread{
    public void run(){
        for(int i = 0; i < 100; i++){
            System.out.println(this.getName());
        }
    }
}

//ͨ��ʵ��Runable�ӿڴ����߳�, ��Runable��ʵ��������ΪThread��target
class MyRunAble implements Runnable{
    @Override
    public void run(){
        for(int i = 0; i < 100; i++){
            System.out.println(Thread.currentThread().getName());
        }
    }
}

//ͨ��ʵ��Callable�ӿڴ����߳�,��FutureTask���װCallable��ʵ������FutureTask��ʵ��������ΪThread��target
class MyCallAble implements Callable<Integer>{
    @Override
    public Integer call(){
        for(int i = 0; i < 100; i++){
            System.out.println(Thread.currentThread().getName());
        }
        Integer integer = 1;
        return integer;
    }
}

/*
    
 */