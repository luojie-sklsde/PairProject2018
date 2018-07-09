import java.io.BufferedReader;  
import java.io.FileReader;  
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.ArrayList;  
import java.util.Collections;  
import java.util.Comparator;  
import java.util.List;  
import java.util.Map;  
import java.util.Map.Entry;  
import java.util.TreeMap;  
  
/** 
 *  
 * @author dzh/cj 
 * 
 * 
 * ʵ�ִ��ļ��ж���Ӣ�����£�ͳ�Ƶ��ʸ���,�����Ƶ����ߵ�ǰ10������ 
 */  
  
public class Main { 
	
	  
    public static void main(String[] args) throws Exception {  
       /*   
    	if(args[0]==null){
    		
    		System.out.print("");
    		System.exit(0);     	  	
    	}
    	*/
    	BufferedReader br = new BufferedReader(new FileReader("..\\sub\\input.txt"));  
        List<String> lists = new ArrayList<String>();  //�洢���˺󵥴ʵ��б�  
        String readLine = null;
        int rowNumbers=0;
        int characterNumbers=0;
		while((readLine = br.readLine()) != null){ 
			rowNumbers++;
			characterNumbers+=CountCharacters(readLine);
            String[] wordsArr1 = readLine.split("[^a-zA-Z]");  //���˳�ֻ������ĸ��  
            for (String word : wordsArr1) {  
                if(word.length() != 0){  //ȥ������Ϊ0����  
                    lists.add(word);  
                }  
            }  
        }  
          
        br.close();  
          
        Map<String, Integer> wordsCount = new TreeMap<String,Integer>();  //�洢���ʼ�����Ϣ��keyֵΪ���ʣ�valueΪ������       
          
        //���ʵĴ�Ƶͳ��  
        for (String li : lists) {  
            if(wordsCount.get(li) != null){  
                wordsCount.put(li,wordsCount.get(li) + 1);  
            }else{  
                wordsCount.put(li,1);  
            }  
  
        }  
          
        System.out.println("characters:"+characterNumbers);
        System.out.println("words:"+CountWords(wordsCount));
        System.out.println("lines:"+rowNumbers);   
        
        ArrayList<Map.Entry<String,Integer>> list=null;
        list=SortMap(wordsCount);    //��ֵ��������  
        
      	PrintWriter pw=new PrintWriter("..\\sub\\output.txt");
      	pw.println("characters:"+characterNumbers);
        pw.println("words:"+CountWords(wordsCount));
        pw.println("lines:"+rowNumbers);      
       
        outputResult(list,pw);
        pw.close();
        
    }  
     
    
    
    //��value�Ĵ�С��������  
    public static ArrayList<Map.Entry<String,Integer>>  SortMap(Map<String,Integer> oldmap){  
          
        ArrayList<Map.Entry<String,Integer>> list = new ArrayList<Map.Entry<String,Integer>>(oldmap.entrySet());  
          
        Collections.sort(list,new Comparator<Map.Entry<String,Integer>>(){  
            @Override  
            public int compare(Entry<String, Integer> o1, Entry<String, Integer> o2) {  
                return o2.getValue() - o1.getValue();  //����  
            }  
        });  
        return list;
    } 
    
    public static void outputResult(ArrayList<Map.Entry<String,Integer>> list,PrintWriter ps ){
        for(int i = 0; i<10; i++){  
            ps.println(list.get(i).getKey()+ ": " +list.get(i).getValue());  
        }  
    }
    
  //ͳ�Ƶ�������  
    public static int CountWords(Map<String,Integer> oldmap){  
    	ArrayList<Map.Entry<String,Integer>> list = new ArrayList<Map.Entry<String,Integer>>(oldmap.entrySet());  
    	int countTemp=0;
    	          
        for(int i = 0; i<list.size(); i++){  
            countTemp+=list.get(i).getValue();  
        }  
        return countTemp;
    } 
    
    public static int CountCharacters(String line){
    	int countTemp=0;
    	
    	for (int i=0;i<line.length();i++){
    		
    		int valueTemp=Integer.valueOf(line.charAt(i));  		
    		   		
    		if(valueTemp>=0&&valueTemp<=255)  countTemp++;    	     	 
    	 }
    	return countTemp;
    }
    
     
}  
