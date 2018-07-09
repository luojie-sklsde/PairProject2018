import java.io.*;
import java.util.ArrayList;


public class WordCount {

    private int lines;
    private int words;
    private int characters;
    private ArrayList<String> wordArr = new ArrayList<>();
    private String  word = "";
    private int[] count;

    public int getLines() {
        return lines;
    }

    public int getWords() {
        return words;
    }

    public int getCharacters() {
        return characters;
    }


    public  void setter(File ifile, int m, File ofile) {
        int c = 0;
        try {
            FileInputStream in = new FileInputStream(ifile);

            while ((c = in.read()) > -1) {
                if( c != ' ' && c != '\n' && c != 0xd)
                word += c;

                characters++; //统计字符数
                if ((char) c == ' ' || c == '\n') {
                    words++; //统计单词数
                    wordArr.add(word);
                    word = "";
                }
                if ((char) c == '\n') lines++; //统计行数

                System.out.print((char) c);
            }
            in.close();
            System.out.flush();

            /*
            System.out.println(characters);
            System.out.println(words);
            System.out.println(lines);

            for(int i=0; i < wordArr.size(); i++)
                System.out.println((String)wordArr.get(i));
            */
            count = new int[wordArr.size()];
            for(int i=0; i < wordArr.size(); i++) {
                String aEach = (String) wordArr.get(i);
                count[i]=1;
                for (int j = i + 1; j < wordArr.size(); j++){
                    String aEach1 = (String) wordArr.get(j);
                    if(aEach.equals(aEach1)){
                        count[i]++;
                    //System.out.println("cout["+i+"]"+count[i]);
                    }
                }
            }
            for(int i=0; i < wordArr.size(); i++){
                
            }

        } catch (FileNotFoundException e) {
            System.err.println(ifile + " is not found");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
