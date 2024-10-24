#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

class Solution:
    def modifyAndRearrangeArr (self, arr) : 
        arr1=[]
        arr2=[]
        n=len(arr)
        i=0
        while(i<n-1):
            if arr[i]==arr[i+1]:
                arr[i]=arr[i]*2
                arr[i+1]=0
                i=i+2
            else:
                i=i+1
        for i in arr:
            if i==0:
                arr1.append(0)
            else:
                arr2.append(i)
        return arr2+arr1

#{ 
 # Driver Code Starts.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.modifyAndRearrangeArr(arr)
        print(*ans)
        t -= 1


# } Driver Code Ends