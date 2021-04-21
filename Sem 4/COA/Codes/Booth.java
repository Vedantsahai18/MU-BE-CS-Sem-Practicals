import java.util.*;

public class Booth{
	public static void main(String[]args){
		int q, m;
		int qc = 0, mc = 0, e = 0;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter two numbers to be multiplied");
		m = in.nextInt();
		q = in.nextInt();
		int temp = Math.abs(m);
		ArrayList<Integer> A = new ArrayList();
        ArrayList<Integer> MCOMP = new ArrayList();
        ArrayList<Integer> QCOMP = new ArrayList();
        ArrayList<Integer> ACOMP = new ArrayList();
		
		ArrayList<Integer> M = new ArrayList();
		while(temp != 0){
			M.add(0, temp%2);
			temp = temp/2;
			mc = mc + 1;
		}
        M.add(0, 0);
        mc = mc + 1;
		
		
		ArrayList<Integer> Q = new ArrayList();
		temp = Math.abs(q);
		while(temp != 0){
			Q.add(0, temp%2);
			temp = temp/2;
			qc = qc + 1;
		}
        Q.add(0, 0);
        qc = qc + 1;
		
		if(mc > qc){
			while(mc != qc){
				Q.add(0, 0);
				qc = qc + 1;
			}
		}
		if (mc < qc){
			while(mc != qc){
				M.add(0, 0);
				mc = mc + 1;
			}
		}
        
        int i = 0;
        while(i != mc){
            A.add(0);
            i = i + 1;
        }
        
        if(m < 0){
            MCOMP = M;
            M = complement(M);
        }
        
        if(q < 0){
            QCOMP = Q;
            Q = complement(Q);
        }
        
        System.out.println("Multiplicand");
        display(M);
        
        System.out.println("\nMultiplier");
        display(Q);
        
        System.out.println("\nComplement of M");
        display(MCOMP);
		
        System.out.println("\nComplement of Q");
        display(QCOMP);
        
        int n = 1;
        while(n <= qc){
            
            System.out.println("-----------");
            
            if( (Q.get(Q.size() - 1) == 0 && e == 0) || (Q.get(Q.size() - 1) == 1 && e == 1)){
                System.out.println("1->1/0->0 RS Step:"+n);
                e = Q.get(Q.size() - 1);
                rightshift(A, Q);
            }
            else if((Q.get(Q.size() - 1) == 1 && e == 0)){
                System.out.println("0->1 SUB Step:"+n);
                e = Q.get(Q.size() - 1);
                MCOMP = complement(M);
                add(A, MCOMP);
                rightshift(A, Q);
            }
            else if((Q.get(Q.size() - 1) == 0 && e == 1)){
                System.out.println("1->0 ADD Step:"+n);
                e = Q.get(Q.size() - 1);
                add(A, M);
                rightshift(A, Q);
            }
            System.out.println("Accumuator, Step:"+n);
            display(A);
            
            System.out.println("\n-----------");
            n++;
        }
        
        int num;
        if(m < 0 && q < 0){
            A.addAll(Q);
            System.out.println("Final answer");
            display(A);
            num = b2d(A);
            System.out.println("Decimal-> "+num);
        }
        else if(m < 0 || q < 0){
            System.out.println("Final answer");
            A.addAll(Q);
            display(A);
            ACOMP = complement(A);
            num = b2d(ACOMP);
            System.out.println("Decimal-> -"+num);
        }
        else{
            System.out.println("Final answer");
            A.addAll(Q);
            display(A);
            num = b2d(A);
            System.out.println("Decimal-> "+num);
        }
		
	}
	
	static void display(ArrayList<Integer> list){
		for(int ele: list){
			System.out.print(ele+" ");
		}
	}
    
    static int b2d(ArrayList<Integer> list){
        int i = 0;
        int sum = 0;
        Collections.reverse(list);
        while(i != list.size() - 1){
            if(list.get(i) == 1){
                sum = (int)Math.pow(2, i) + sum;
            }
            i++;
        }
        Collections.reverse(list);
        return sum;
    }
	
	static ArrayList<Integer> complement(ArrayList<Integer> list){
            ArrayList<Integer> COMP = new ArrayList();
            boolean check = false;
            Collections.reverse(list);
            for(int ele: list){
                
                if(!check && ele == 1){
                    check = true;
                    COMP.add(0, 1);
                }
                else if(!check && ele == 0){
                    COMP.add(0, 0);
                }
                else if(check && ele == 1){
                    COMP.add(0, 0);
                }
                else if(check && ele == 0){
                    COMP.add(0, 1);
                }
            }
            Collections.reverse(list);
            return COMP;
        }
    
    static void rightshift(ArrayList<Integer> A, ArrayList<Integer> Q){
        Collections.rotate(Q, 1);
        Q.set(0, A.get(A.size() - 1));
        Collections.rotate(A, 1);
        A.set(0, A.get(1));
    }
    
    static void add(ArrayList<Integer> A, ArrayList<Integer> M){
        int carry = 0;
        int a, m, i = 0;
        Collections.reverse(A);
        Collections.reverse(M);
        while(i < A.size()){
            a = A.get(i);
            m = M.get(i);
            if((a + m > 1) && carry == 0){
                carry = 1;
                A.set(i, 0);
            }
            else if((a + m > 1) && carry == 1){
                carry = 1;
                A.set(i, 1);
            }
            else if((a + m == 1) && carry == 0){
                carry = 0;
                A.set(i, 1);
            }
            else if((a + m == 1) && carry == 1){
                carry = 1;
                A.set(i, 0);
            }
            else if((a + m == 0) && carry == 1){
                carry = 0;
                A.set(i, 1);
            }
            i++;
        }
        Collections.reverse(A);
        Collections.reverse(M);
    }
}


/*
 Enter two numbers to be multiplied
 6
 7
 Multiplicand
 0 1 1 0
 Multiplier
 0 1 1 1
 Complement of M
 
 Complement of Q
 -----------
 0->1 SUB Step:1
 Accumuator, Step:1
 1 1 0 1
 -----------
 -----------
 1->1/0->0 RS Step:2
 Accumuator, Step:2
 1 1 1 0
 -----------
 -----------
 1->1/0->0 RS Step:3
 Accumuator, Step:3
 1 1 1 1
 -----------
 -----------
 1->0 ADD Step:4
 Accumuator, Step:4
 0 0 1 0
 -----------
 Final answer
 0 0 1 0 1 0 1 0 Decimal-> 42

 
 Enter two numbers to be multiplied
 -6
 7
 Multiplicand
 1 0 1 0
 Multiplier
 0 1 1 1
 Complement of M
 0 1 1 0
 Complement of Q
 -----------
 0->1 SUB Step:1
 Accumuator, Step:1
 0 0 1 1
 -----------
 -----------
 1->1/0->0 RS Step:2
 Accumuator, Step:2
 0 0 0 1
 -----------
 -----------
 1->1/0->0 RS Step:3
 Accumuator, Step:3
 0 0 0 0
 -----------
 -----------
 1->0 ADD Step:4
 Accumuator, Step:4
 1 1 0 1
 -----------
 Final answer
 1 1 0 1 0 1 1 0 Decimal-> -42
 
 
 Enter two numbers to be multiplied
 6
 -7
 Multiplicand
 0 1 1 0
 Multiplier
 1 0 0 1
 Complement of M
 
 Complement of Q
 0 1 1 1 -----------
 0->1 SUB Step:1
 Accumuator, Step:1
 1 1 0 1
 -----------
 -----------
 1->0 ADD Step:2
 Accumuator, Step:2
 0 0 0 1
 -----------
 -----------
 1->1/0->0 RS Step:3
 Accumuator, Step:3
 0 0 0 0
 -----------
 -----------
 0->1 SUB Step:4
 Accumuator, Step:4
 1 1 0 1
 -----------
 Final answer
 1 1 0 1 0 1 1 0 Decimal-> -42

 
 Enter two numbers to be multiplied
 -6
 -7
 Multiplicand
 1 0 1 0
 Multiplier
 1 0 0 1
 Complement of M
 0 1 1 0
 Complement of Q
 0 1 1 1 -----------
 0->1 SUB Step:1
 Accumuator, Step:1
 0 0 1 1
 -----------
 -----------
 1->0 ADD Step:2
 Accumuator, Step:2
 1 1 1 0
 -----------
 -----------
 1->1/0->0 RS Step:3
 Accumuator, Step:3
 1 1 1 1
 -----------
 -----------
 0->1 SUB Step:4
 Accumuator, Step:4
 0 0 1 0
 -----------
 Final answer
 0 0 1 0 1 0 1 0 Decimal-> 42
 */
