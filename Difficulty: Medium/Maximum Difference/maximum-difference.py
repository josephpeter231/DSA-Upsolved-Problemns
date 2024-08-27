class Solution:
    def findMaxDiff(self, arr):
        n = len(arr)
        left_smaller = [0] * n
        right_smaller = [0] * n
        
        # Finding nearest smaller to left for each element
        stack = []
        for i in range(n):
            while stack and stack[-1] >= arr[i]:
                stack.pop()
            if stack:
                left_smaller[i] = stack[-1]
            else:
                left_smaller[i] = 0
            stack.append(arr[i])
        
        # Finding nearest smaller to right for each element
        stack = []
        for i in range(n-1, -1, -1):
            while stack and stack[-1] >= arr[i]:
                stack.pop()
            if stack:
                right_smaller[i] = stack[-1]
            else:
                right_smaller[i] = 0
            stack.append(arr[i])
        
        # Calculate the maximum absolute difference
        maxi = 0
        for i in range(n):
            maxi = max(maxi, abs(left_smaller[i] - right_smaller[i]))
        
        return maxi

        # code here


#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        print(ob.findMaxDiff(arr))

# } Driver Code Ends