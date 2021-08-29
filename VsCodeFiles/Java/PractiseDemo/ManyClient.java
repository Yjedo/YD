package PractiseDemo;

import java.io.*;
import java.net.*;
import java.util.Scanner;
import java.util.Vector;
import java.lang.Thread;

public class ManyClient{
    public static void main(String[] args) throws IOException{
        Server server = new Server();   
    }
}

//����ͻ��˵�Socket��
class MySocket extends Thread{
    Socket socket;
    private Scanner scanner;
    private BufferedReader in;
    private PrintStream out;
    MySocket(Socket socket){
        this.socket = socket;
        scanner = new Scanner(System.in);
        try{
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new PrintStream(socket.getOutputStream());
        } catch (IOException e){
            System.out.println("����˽��������쳣");
        }

        this.start();
    }

    public void run(){
        String getStr, returnStr;
        try{
            while(!(getStr = in.readLine()).equals("END")){
                System.out.println(getStr);
                returnStr = scanner.next();
                out.println(returnStr);
                System.out.println("server: " + returnStr);
                out.flush();
            }
        } catch (IOException e){
            System.out.println("����˶�ȡ�����쳣��");
        }
    }
}

//�����
class Server{
    private ServerSocket server;
    private Vector<Socket> mySockets;
    final int maxNumClient = 10;
    Server() throws IOException{      
        server = new ServerSocket(8080);
        mySockets = new Vector<>();
        System.out.println("��ʼ���ɹ���");
        while(mySockets.size() < maxNumClient){
            try{
                //ÿ��⵽һ���ͻ���
                Socket socket = server.accept();
                System.out.println("���ӳɹ���");
                //�Ͷ����½�һ���������
                MySocket mySocket = new MySocket(socket);
                mySockets.add(socket);
            } catch(IOException e){
                System.out.println("���������ʧ�ܣ�");
            }
        }
    }
}

//�ͻ���
class Client extends Thread{
    private String name;
    private Socket clientSocket;
    private Scanner scanner;
    private BufferedReader in;
    private PrintStream out;

    Client(String name) throws IOException{
        this.name = name;
        clientSocket = new Socket("127.0.0.1", 8080);
        scanner = new Scanner(System.in);
        in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        out = new PrintStream(clientSocket.getOutputStream());
        this.start();
    }

    public void run(){
        String getStr;
        String returnStr;
        try{
            while(!(getStr = in.readLine()).equals("END")){
                //�����յ�����˵���ϢΪENDʱ����
                System.out.println("server: " + getStr);
                returnStr = scanner.next();
                System.out.println(this.name + ":" + returnStr);
                out.println(returnStr);
                out.flush();
            }
            clientSocket.close();
        } catch(IOException e){
            System.out.println("��ȡ����ʧ�ܣ�");
        }
    }
}
