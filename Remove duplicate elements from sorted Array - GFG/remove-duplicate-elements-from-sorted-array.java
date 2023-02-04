//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

public class GFG {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T>0)
        {
            int N = sc.nextInt();
            int a[] = new int[N];
            for(int i=0; i<N; i++)
                a[i] = sc.nextInt();
            
            Solution g = new Solution();
            int n = g.remove_duplicate(a,N);
            
            for(int i=0; i<n; i++)
                System.out.print(a[i]+" ");
            System.out.println();
            T--;
        }
    }
}
// } Driver Code Ends

//User function Template for Java

class Solution {
    int remove_duplicate(int A[],int N){
        int[] a1 = new int[A.length];
        int distinct=1;
        int prev=A[0];
        a1[0]=prev;
        for(int i=1,j=1;i<A.length;i++)
        {
            if(A[i]!=prev)
            {
                distinct++;
                a1[j++]=A[i];
                prev=A[i];
            }
        }
        for(int i=0,j=0;i<A.length;i++,j++)
        {
            A[i]=a1[j];
            if(j>a1.length)
            break;
        }
        return distinct;
    }
}