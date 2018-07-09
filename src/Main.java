import java.io.*;

import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Main {
    private static String REGEX_CHINESE = "[\u4e00-\u9fa5]";// 中文正则

    public String neglectChinese(String str) {
        // 去除中文
        Pattern pat = Pattern.compile(REGEX_CHINESE);
        Matcher mat = pat.matcher(str);
        return mat.replaceAll("");
    }


    public int countLines(String filename) throws FileNotFoundException {
        //获取文件行数
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
        String str = neglectChinese(file_string);
        return str.length();
    }

    public Map getWordsMap(String text){
        //找出所有的单词
        String[] array = {".", " ", "?", "!", "\r\n"};
        for (int i = 0; i < array.length; i++) {
            text = text.replace(array[i],",");
        }

        String[] textArray = text.split(",");
        //遍历 记录
        Map<String, Integer> map = new HashMap<String, Integer>();
        int upper_limit;

        for (int i = 0; i < textArray.length; i++) {
            String key = textArray[i];

            //转为小写
            String key_l = key.toLowerCase();
            boolean is_a_word = true;
            if(key_l.length() > 4){
                upper_limit = 4;
            }else{
                upper_limit = key_l.length();
            }

            for(int j=0; j <upper_limit; j++){
                char c = key_l.charAt(j);
                if (!Character.isLetter(c)){
                    is_a_word = false;
                    break;
                }
            }
            if(is_a_word && !"".equals(key_l)){
                Integer num = map.get(key_l);
                if(num == null || num == 0){
                    map.put(key_l, 1);
                }else if(num > 0){
                    map.put(key_l, num+1);
                }
            }
        }
        return map;
    }

    public void writeToFile(Map map, Integer chars_amount, Integer words_amount, Integer lines_amount){
        File f = new File("result.txt");
        FileWriter fw;
        try {
            fw = new FileWriter(f);
            fw.write("characters:"+chars_amount.toString()+"\r\n");
            fw.write("words:"+words_amount.toString()+"\r\n");
            fw.write("lines:"+lines_amount.toString()+"\r\n");

            List<Map.Entry<String,Integer>> list = new ArrayList<Map.Entry<String,Integer>>(map.entrySet());
            //然后通过比较器来实现排序
            //降序排序
            Collections.sort(list, (o1, o2) -> o2.getValue().compareTo(o1.getValue()));

            Set<Integer> set = new HashSet<Integer>();

            for(Map.Entry<String,Integer> element:list){
                int value = element.getValue();
                if(!set.contains(value)){
                    if(set.size() < 10){
                        set.add(value);
                    }else{
                        break;
                    }
                }
                fw.write(element.getKey()+":"+element.getValue().toString()+"\r\n");
            }
            fw.close();
        } catch (IOException e) { e.printStackTrace(); }
    }

    public static void main(String args[]){
        Main m = new Main();

        String file_string = m.readToString(args[0]);
        //统计字符数量，还需完善忽略中文功能
        int char_amount = m.countChar(file_string);
        System.out.print("characters:");
        System.out.println(char_amount);

        //获取词频字典
        Map words_map = m.getWordsMap(file_string);

        //获取单词数量
        int words_amount = words_map.size();
        System.out.print("words:");
        System.out.println(words_amount);

        int lines_amount = 0;
        try {
            lines_amount = m.countLines(args[0]);
        }
        catch (Exception e){
            System.out.println("can't find file");
        }

        //输出结果到文件
        m.writeToFile(words_map, char_amount, words_amount, lines_amount);

    }

}
