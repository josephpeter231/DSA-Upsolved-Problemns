#User function Template for python3

class Solution:
    def findTwoElement(self, arr):
        n = len(arr)
        s = sum(arr)
        s_set = sum(set(arr))
        missing = n * (n + 1) // 2 - s_set
        duplicate = s - s_set
        return [duplicate, missing]



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findTwoElement(arr)
        print(str(ans[0]) + " " + str(ans[1]))
        tc = tc - 1

# } Driver Code Ends