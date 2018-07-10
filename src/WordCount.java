import java.io.*;
import java.util.ArrayList;


public class WordCount {

    private int lines;
    private int words;
    private int characters;
    private ArrayList<String> wordArr = new ArrayList<>();
    private String  word = "";

    public int[] getCount() {
        return count;
    }

    private int[] count;
    private  int maxi;

    public int getLines() {
        return lines;
    }

    public int getWords() {
        return words;
    }

    public int getCharacters() {
        return characters;
    }

    public int getMaxi() {        return maxi;    }

    public String getWord() {
        return word;
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

            count = new int[wordArr.size()];
            for(int i=0; i < wordArr.size(); i++) {
                String aEach = (String) wordArr.get(i);
                count[i]=1;
                for (int j = i + 1; j < wordArr.size(); j++){
                    String aEach1 = (String) wordArr.get(j);
                    if(aEach.equals(aEach1)){
                        count[i]++;

                        System.out.println("cout["+i+"]"+count[i]);
                    }
                }
            }
            int max=0;
            for(int i=0; i < wordArr.size(); i++){

                if(count[i] > max){
                    max = count[i];
                    maxi=i;}
            }
            word = wordArr.get(maxi);

            //System.out.println("The words with the highest frequency is "+(String) wordArr.get(maxi)+" appears " +count[maxi]+" times");

        } catch (FileNotFoundException e) {
            System.err.println(ifile + " is not found");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
