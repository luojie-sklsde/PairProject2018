import java.io.*;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class Main {
    public String stringToAscii(String value) {
        //将字符串转换为Ascii码字符串
        StringBuffer sbu = new StringBuffer();
        char[] chars = value.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if(i != chars.length - 1)
            {
                sbu.append((int)chars[i]).append(",");
            }
            else {
                sbu.append((int)chars[i]);
            }
        }
        return sbu.toString();

    }


    public int countLines(String filename) throws FileNotFoundException {
        int count=0;
        File file = new File(filename);
        FileInputStream fis = new FileInputStream(file);
        Scanner scanner = new Scanner(fis);
        while(scanner.hasNextLine()){
            scanner.nextLine();
            count++;
        }
        return count;

    }
    public String readToString(String fileName) {
        String encoding = "UTF-8";
        File file = new File(fileName);
        Long filelength = file.length();
        byte[] filecontent = new byte[filelength.intValue()];
        try {
            FileInputStream in = new FileInputStream(file);
            in.read(filecontent);
            in.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            return new String(filecontent, encoding);
        } catch (UnsupportedEncodingException e) {
            System.err.println("The OS does not support " + encoding);
            e.printStackTrace();
            return null;
        }
    }

    public int countChar(String file_string){
        return file_string.length();
    }

    public Map getWordsMap(String text){
        //找出所有的单词
        String[] array = {".", " ", "?", "!"};
        for (int i = 0; i < array.length; i++) {
            text = text.replace(array[i],",");
        }
        String[] textArray = text.split(",");
        //遍历 记录
        Map<String, Integer> map = new HashMap<String, Integer>();
        for (int i = 0; i < textArray.length; i++) {
            String key = textArray[i];
            //转为小写
            String key_l = key.toLowerCase();
            if(!"".equals(key_l)){
                Integer num = map.get(key_l);
                if(num == null || num == 0){
                    map.put(key_l, 1);
                }else if(num > 0){
                    map.put(key_l, num+1);
                }
            }
        }
        //输出到控制台
/*
        System.out.println("各个单词出现的频率为：");
        Iterator<String> iter = map.keySet().iterator();
        while(iter.hasNext()){
            String key = iter.next();
            Integer num = map.get(key);
            System.out.println(key + "\n\t\t" + num + "次\n-------------------");
        }
*/
        return map;
    }

    public static void main(String args[]){
        Main m = new Main();

        String file_string = m.readToString(args[0]);
        //统计字符数量，还需完善忽略中文功能
        int char_amount = m.countChar(file_string);

        //获取词频字典，还需完善识别单词功能
        Map words_map = m.getWordsMap(file_string);

        //获取单词数量
        int words_amount = words_map.size();
        System.out.println(words_amount);

        System.out.println(m.stringToAscii(file_string));
        try {
            System.out.println(m.countLines(args[0]));
        }
        catch (Exception e){
            System.out.println("can't find file");
        }
    }

}
