package JavaStudy;

import java.util.regex.*;
 
class TestJavaString{
   public static void main(String[] args){
      String content = "I am noob " +
        "from runoob.com.";
 
      String pattern = ".*cooms.*";
 
      boolean isMatch = Pattern.matches(pattern, content);
      System.out.println("�ַ������Ƿ������ 'runoob' ���ַ���? " + isMatch);
   }
}