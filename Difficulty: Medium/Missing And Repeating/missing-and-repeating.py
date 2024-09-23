#User function Template for python3

class Solution:
    def findTwoElement( self,arr): 
        n=len(arr)
        squared=0
        summation=0
        actual=(n*(n+1))//2
        squaredactual= (n*(n+1)*(2*n + 1))//6
        for i in range(n):
            summation+=arr[i]
            squared+=arr[i]**2

        diff=actual-summation
        missing=((squaredactual-squared)//diff + diff)//2
        repeated=missing-diff
        
        return repeated,missing
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findTwoElement(arr)
        print(str(ans[0]) + " " + str(ans[1]))
        tc = tc - 1

# } Driver Code Ends