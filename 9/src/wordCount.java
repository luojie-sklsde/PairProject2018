import jdk.nashorn.internal.runtime.regexp.joni.Regex;
import java.io.*;
import java.util.*;

public class wordCount {
    public static void main(String[] args) throws IOException {
        //读入TXT文件
//        Scanner input=new Scanner(System.in);
        File file = new File(args[0]);
        Scanner input = new Scanner(file);
        String path = input.next();
        List<String> wordArray = new ArrayList<String>();
        int countChar=0;
        int countWord=0;
        int counLine=0;
        InputStreamReader reader = new InputStreamReader(new FileInputStream(args[0])); // 建立一个输入流对象reader
        BufferedReader br = new BufferedReader(reader); // 建立一个对象，它把文件内容转成计算机能读懂的语言
        List<String> lists = new ArrayList<String>();  //存储过滤后单词的列表
        String readLine = null;
        while((readLine = br.readLine()) != null){
            countChar += readLine.length();//字符个数就是字符长度
            counLine++;//一行一行读，每读一行行数加1
            String[] wordsArr1 = readLine.split("\\s*[^0-9a-zA-Z]+");//以空格和非字母数字符号分割，至少4个英文字母开头，跟上字母数字符号
            for (String word : wordsArr1) {
                if(word.matches("[a-zA-Z]{4,}[a-zA-Z0-9]*")){
                    lists.add(word);
                }
            }
        }
        reader.close();//关闭文件

         Map<String, Integer> wordsCount = new TreeMap<String,Integer>();  //存储单词计数信息，key值为单词，value为单词数
         //单词的词频统计
        for (String li : lists) {
        if(wordsCount.get(li) != null){
            wordsCount.put(li,wordsCount.get(li) + 1);
        }else{
            wordsCount.put(li,1);
        }
            countWord++;
        }


        //写入Txt文件
        File f = new File("output.txt");
        f.createNewFile();
        FileOutputStream fileOutputStream = new FileOutputStream(f);
        PrintStream printStream = new PrintStream(fileOutputStream);
        System.setOut(printStream);
        System.out.println("characters:"+countChar);
        System.out.println("lines:"+counLine);
        System.out.println("words:"+countWord);
        SortMap(wordsCount);    //按值进行排序
    }

        //按value的大小进行排序
        public static void SortMap(Map<String,Integer> oldmap){
        ArrayList<Map.Entry<String,Integer>> list = new ArrayList<Map.Entry<String,Integer>>(oldmap.entrySet());
        Collections.sort(list,new Comparator<Map.Entry<String,Integer>>(){
            @Override
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                return o2.getValue() - o1.getValue();  //降序
            }
        });
        if(list.size()>=10){
            for(int i = 0; i<10; i++){//list.size() 只输出频率最高的10个
                System.out.println(list.get(i).getKey()+ ": " +list.get(i).getValue());
            }
        }else {
            for(int i = 0; i<list.size(); i++){//list.size() 只输出频率最高的10个
                System.out.println(list.get(i).getKey()+ ": " +list.get(i).getValue());
            }
        }

    }


}

