class SnapshotArray:
    
    def __init__(self, length):
        """
        :type length: int
        """
        self.snap_id = 0
        self.list = [[[-1, 0]] for _ in range(length)]

    def set(self, index, val):
        """
        :type index: int
        :type val: int
        :rtype: None
        """
        
        self.list[index].append([self.snap_id, val])
        
    def snap(self):
        """
        :rtype: int
        """
        ans = self.snap_id
        self.snap_id += 1
        return ans
    
    def get(self, index, snap_id):
        """
        :type index: int
        :type snap_id: int
        :rtype: int
        """
        #print(self.list)
        li = self.list[index]
        left, right = 0, len(li) - 1
        while left + 1 < right:
            mid = (left + right) // 2
            if li[mid][0] <= snap_id:
                left = mid
            else:
                right = mid
        if li[right][0] <= snap_id:
            return li[right][1]
        return li[left][1]


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)