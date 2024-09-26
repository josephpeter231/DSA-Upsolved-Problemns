#User function Template for python3

class Solution:
    #Function to find maximum number of consecutive steps 
    #to gain an increase in altitude with each step.
    def maxStep(self, arr):
        #Your code here
        max_consecutive_step=0
        count_inc_steps=0
        
        for index in range(1, len(arr)):
            if arr[index-1]<arr[index]:
                count_inc_steps+=1
            else:
                count_inc_steps=0
            max_consecutive_step=max(max_consecutive_step, count_inc_steps)
        
        
        return max_consecutive_step

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


def main():
    T = int(input())
    while (T > 0):

        arr = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.maxStep(arr))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends