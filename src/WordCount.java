import java.io.*;


public class WordCount {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Usage: java FileType <input_file>");
            System.exit(-1);
        }
        File file = new File(args[0]);
        try {
            FileInputStream in = new FileInputStream(file);
            int c;
            int i = 1;
            int w=0;
            int cc=0;
            while ((c = in.read()) > -1) {
                if ( c != ' ' && c!='\n')
                    cc++; //统计字符数
                if ((char) c == ' '||c =='\n') w++; //统计单词数
                if ((char) c == '\n') i++; //统计行数

                System.out.print((char) c);
            }
            in.close();
            System.out.flush();
            System.out.println("----------------");
            System.out.println("File " + args[0] + " chars: " +cc);
            System.out.println("File " + args[0] + " words: " +w);
            System.out.println("File " + args[0] + " Lines: " + i);


        } catch (FileNotFoundException e) {
            System.err.println(file + " is not found");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
