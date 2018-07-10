import java.io.File;

public class Main {
    public static void main(String[] args) {

        String ifileName="", ofileName="";
        int m = 10;

        if (args.length < 1) {
            System.err.println("Usage: java WordCount -n 2 -i <input_file> -o <output_file>");
            System.exit(-1);
        }

        for(int i = 0; i < args.length; i++) {
            if (args[i].compareTo("-i") == 0)
                ifileName = args[i + 1];
            if (args[i].compareTo("-o") == 0)
                ofileName = args[i + 1];
            if (args[i].compareTo("-m") == 0)
                m = Integer.parseInt(args[i+1]);

        }
        File ifile = new File(ifileName);
        File ofile = new File(ofileName);

        WordCount mwc =  new WordCount();
        mwc.setter(ifile, 5, ifile);
        System.out.println("----------------");
        System.out.println("File " + ifileName + " chars: " +  mwc.getCharacters());
        System.out.println("File " + ifileName + " words: " +  mwc.getWords());
        System.out.println("File " + ifileName + " Lines: " +  mwc.getLines());
        System.out.println("The words with the highest frequency is "+ (String)mwc.getWord() +" appears " + mwc.getCount()[mwc.getMaxi()]+" times");



    }
}
