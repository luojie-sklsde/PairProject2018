import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

public class wordCount {
    public static void main(String[] args) throws FileNotFoundException {
        File file = new File(args[0]);
        File file1 = new File("Out.txt");
        PrintStream printStream = new PrintStream(file1);
        countChar(file,printStream);
        countWord(file,printStream);
    }
    public static void countChar(File file,PrintStream printStream)throws FileNotFoundException{
        Scanner input = new Scanner(file);
        int count=0;
        while (input.hasNextLine()){
            String charline = input.nextLine();
            for (int i =0;i<charline.length();i++){
                char ch = charline.charAt(i);
                if (ch>=0 && ch<=127){
                    count++;
                }
            }
        }
        System.out.print("count:"+count);
        printStream.println("characters:"+count);
    }
    public static void countWord(File file, PrintStream printStream)throws FileNotFoundException{
        Scanner input = new Scanner(file);
        HashMap map = new HashMap();

        int line=0;
        while (input.hasNextLine()){
            String charline = input.nextLine();
            String argex = "\\s*[^0-9a-zA-Z]+";
            String argex1="[a-zA-Z]{4,}[a-zA-Z0-9]*";
            String[] a = charline.split(argex);
            //System.out.print(a);

            for (int i =0;i<a.length;i++){
                boolean id_word =  a[i].matches(argex1);
                int n=1;
                if (id_word){
                    String key = a[i].toLowerCase();
                    if (map.containsKey(key)){
                        n=Integer.parseInt(map.get(key).toString())+1;
                        map.put(key,n);
                    }else {
                        map.put(key,1);
                    }
                }
            }
            if (!charline.trim().isEmpty()){
                line++;
            }
        }
        printStream.println("line:"+line);
        // 升序比较器
        Comparator<Map.Entry<String, Integer>> valueComparator = new Comparator<Map.Entry<String,Integer>>() {
            @Override
            public int compare(Map.Entry<String, Integer> o1,
                               Map.Entry<String, Integer> o2) {
                // TODO Auto-generated method stub
                if (o2.getValue()==o1.getValue()){
                    int ab =  o2.getKey().compareTo(o1.getKey());

                    return ab;
                }else {
                    return o2.getValue()-o1.getValue();
                }

            }
        };

        // map转换成list进行排序
        List<Map.Entry<String, Integer>> list = new ArrayList<Map.Entry<String,Integer>>(map.entrySet());

        // 排序
        Collections.sort(list,valueComparator);

        // 默认情况下，TreeMap对key进行升序排序
        System.out.println("------------map按照value升序排序--------------------");
        Integer is_out =0;
        Integer count1 =0;
        for (Map.Entry<String, Integer> entry : list) {
            if (is_out!=entry.getValue()){
                System.out.println("<"+entry.getKey()+">:"  + entry.getValue());
                printStream.println("<"+entry.getKey()+">:"  + entry.getValue());
                is_out=entry.getValue();
                count1++;
                if (count1==10){
                    break;
                }
            }
        }
    }

}