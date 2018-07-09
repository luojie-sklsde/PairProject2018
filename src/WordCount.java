import java.io.*;


public class WordCount {

    private int lines;
    private int words;
    private int characters;

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
                characters++; //统计字符数
                if ((char) c == ' ' || c == '\n') words++; //统计单词数
                if ((char) c == '\n') lines++; //统计行数

                System.out.print((char) c);
            }
            in.close();
            System.out.flush();

            System.out.println(characters);
            System.out.println(words);
            System.out.println(lines);



        } catch (FileNotFoundException e) {
            System.err.println(ifile + " is not found");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
