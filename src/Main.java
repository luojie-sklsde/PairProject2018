package buaa.wordcount;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.UnsupportedEncodingException;

public class wordcount {
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
	/**
	 * @param args
	 */
	public static void main(String[] args){
		
		for(int i=0;i<args.length;i++)
			System.out.println("argument:"+i+args[i]+" ;");
		wordcount wc = new wordcount();
		if(args.length!=1){
			System.out.println("programer args error = " + args.length);
			System.out.println("programer args error...");
		}
		else
		{
			String text =  wc.readToString(args[0]);
			String  lines[] = text.split("\n");
			for(int i = 0;i<lines.length;i++)
				System.out.println(lines[i]);
			
		}
	}

}
