//{ Driver Code Starts
// Initial Template for Java

// Initial Template for Java

import java.io.*;
import java.util.*;

public class validip {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            String s = sc.next();
            Solution obj = new Solution();

            if (obj.isValid(s))
                System.out.println("true");
            else
                System.out.println("false");
        }
    }
}
// } Driver Code Ends

class Solution {
    public boolean isValid(String str) {
         boolean is = true;
        int index = str.indexOf(".");
        int a = 0;
        while (index!=-1){
            int sum=0;
            String temp=str.substring(a,index);
                sum=Integer.parseInt(temp);
                if(sum<0 || sum>255)
                {
                    is=false;
                    break;
                }

            a = index+1;
            index = str.indexOf(".", index+1);
        }
        if(is==true)
        {
            int ans = Integer.parseInt(str.substring(a,str.length()));
            if(ans<0 || ans>255)
            {
                is=false;
            }
        }
        return is;
    }
}