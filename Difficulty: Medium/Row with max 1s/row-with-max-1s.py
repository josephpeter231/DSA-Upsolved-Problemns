#User function Template for python3
class Solution:

	def rowWithMax1s(self,arr):
	    maxi = 0
	    index = -1
	    for i in range(len(arr)):
	        x = arr[i]
	        if x.count(1)>maxi:
	            maxi = x.count(1)
	            index = i
	    return index
		# code here


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, m = list(map(int, input().strip().split()))

        inputLine = list(map(int, input().strip().split()))
        arr = [[0 for j in range(m)] for i in range(n)]

        for i in range(n):
            for j in range(m):
                arr[i][j] = inputLine[i * m + j]
        ob = Solution()
        ans = ob.rowWithMax1s(arr)
        print(ans)
        tc -= 1

# } Driver Code Ends