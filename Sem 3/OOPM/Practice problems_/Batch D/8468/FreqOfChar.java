public class FreqOfChar{


public static void main(String args[]){

	String check = "A paragraph from the Ancient Greek is to write beside or written beside is a self-contained unit of a discourse in writing dealing with a particular point or idea";

	char to_check = 'a';
    int freq = 0;

    for(int i = 0; i < check.length(); i++) {
        if(to_check == check.charAt(i)) {
                ++freq;
            }
        }
    
	System.out.println("Frequency of " + to_check + " = " + freq);

	}
}

/*----------OUTPUT------------
Frequency of a = 11