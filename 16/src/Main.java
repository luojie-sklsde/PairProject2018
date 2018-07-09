import java.io.*;
import java.util.*;

import org.apache.commons.cli.CommandLineParser;
import org.apache.commons.cli.BasicParser;
import org.apache.commons.cli.Options;
import org.apache.commons.cli.CommandLine;

public class Main {
    public static void main(String args[]) throws Exception{

        String file = "";
        // Create a Parser
        CommandLineParser parser = new BasicParser( );
        Options options = new Options( );
        options.addOption("i", "input", true, "Input file name");
        options.addOption("o", "output", true, "Output file name" );
        options.addOption("m", "phrase", false, "Phrase length");
        // Parse the program arguments
        CommandLine commandLine = parser.parse(options, args);

        if( commandLine.hasOption('h') ) {
                System.out.println( "Help Message");
                System.exit(0);
        }

        if (! commandLine.hasOption('i')) {
            System.out.println( "Need the input file");
            System.exit(0);
        }
        String inputFile = commandLine.getOptionValue('i');
        PrintStream writer;
        if (commandLine.hasOption('o')) {
            String outputFile = commandLine.getOptionValue('o');
            writer = new PrintStream(outputFile, "UTF-8");
        } else {
            writer = System.out;
        }

        Main wc = new Main();
        String content = wc.readToString(inputFile);
        try {
            writer.printf("chracters: %d\n", content.length());
            List<String> wordList = wc.wordSplit(content);
            writer.printf("words: %s\n", wordList.size());
            writer.printf("lines: %s\n", wc.countLine(content));
            List<Map.Entry<String, Integer>> sortedList = wc.countWord(wordList);
            for (int i = 0; i < 10 && i < wordList.size(); i++) {
                writer.printf("<%s>: %d\n", sortedList.get(i).getKey(), sortedList.get(i).getValue());
            }
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return;
    }

    public int countLine(String content) {
        boolean blank = false;
        int p = 0;
        int count = 0;
        while (p < content.length()) {
            if (content.charAt(p) == '\n') {
                if (!blank)
                    count++;
                blank = true;
            } else {
                blank = false;
            }
            p++;
        }
        if (!blank) count++;
        return count;
    }

    public int countChar(String content) {
        int len = content.length();
        Map<Character, Integer> charMap = new HashMap<Character, Integer>();
        for (int i = 0; i < len; i++) {
            Character c = content.charAt(i);
            if (charMap.containsKey(c)) {
                int count = charMap.get(c);
                count++;
                charMap.put(c, count);
            } else {
                charMap.put(c, 1);
            }
        }
        return charMap.size();
    }

    boolean isValid(String word) {
        int i = 0;
        while( i < word.length() && word.charAt(i) >= 'a' && word.charAt(i) <= 'z') i++;
        if (i > 3)
            return true;
        else
            return false;

    }

    public List<String> wordSplit(String content) {
        content = content.toLowerCase();
        List wordList = new ArrayList<String>();
        HashSet<Character> charSet = new HashSet<Character>();
        for (Character c = 'a'; c <= 'z'; c++) {
            charSet.add(c);
        }
        for (Character c = 'A'; c <= 'Z'; c++) {
            charSet.add(c);
        }
        for (Character c = '0'; c <= '9'; c++) {
            charSet.add(c);
        }
        int start, end;
        start = 0;
        end = 0;
        while (start < content.length()) {
            end = start;
            while (end < content.length() && charSet.contains(content.charAt(end))) end++;
            String word = content.substring(start, end);
            if (isValid(word))
                wordList.add(word);
            start = end + 1;
        }
        return wordList;
    }

    public List<Map.Entry<String, Integer>> countWord(List<String> wordList) {
        Map<String, Integer> wordMap = new HashMap<String, Integer>();
        HashSet<Character> charSet = new HashSet<Character>();
        for (Character c = 'a'; c <= 'z'; c++) {
            charSet.add(c);
        }
        for (Character c = 'A'; c <= 'Z'; c++) {
            charSet.add(c);
        }
        for (Character c = '0'; c <= '9'; c++) {
            charSet.add(c);
        }
        int start, end;
        start = 0;
        end = 0;
        for (int i = 0; i < wordList.size(); i++) {
            String word = wordList.get(i);
            if (isValid(wordList.get(i))) {
                if (wordMap.containsKey(word)) {
                    int count = wordMap.get(word);
                    count++;
                    wordMap.put(word, count);
                } else {
                    wordMap.put(word, 1);
                }
            }
        }

        List<Map.Entry<String, Integer>> sortedList = new ArrayList<Map.Entry<String, Integer>>(wordMap.entrySet());
        Collections.sort(sortedList, new Comparator<Map.Entry<String, Integer>>() {
            public int compare(Map.Entry<String, Integer> o1,
                               Map.Entry<String, Integer> o2) {
//              System.out.println(o1.getKey()+"   ===  "+o2.getKey());
                if (o2.getValue().toString().equals(o1.getValue().toString()))
                    return o1.getKey().toString().compareTo(o2.getKey().toString());
                else
                return Integer.parseInt(o2.getValue().toString()) - Integer.parseInt(o1.getValue().toString());
            }
        });

        return sortedList;
    }

    public String readToString(String fileName) {
        String encoding = "ISO-8859-1";
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
}
