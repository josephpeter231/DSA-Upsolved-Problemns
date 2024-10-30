//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            int k = Integer.parseInt(br.readLine());
            // Create Solution object and find closest sum
            Solution ob = new Solution();
            int ans = ob.countPairsWithDiffK(arr, k);
            System.out.println(ans);
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    int countPairsWithDiffK(int[] arr, int k) {
            HashMap<Integer, Integer> map = new HashMap<>();
            for (Integer n : arr) {
              map.put(n, map.getOrDefault(n, 0) + 1);
            }
            int count = 0;
            for (Integer n : arr) {
              
                if (n + k == n) {
                  
                    count+= map.get(n)*(map.get(n)-1)/2;
                    map.put(n, 0);
                   
                  
                } else if (map.containsKey(n+k)) {
                  count += map.get(n+k);
                }
                
              
        
            }
        
            return count;
          }
}