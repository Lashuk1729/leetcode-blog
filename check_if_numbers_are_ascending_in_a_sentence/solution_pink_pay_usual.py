class Solution(object):
    def areNumbersAscending(self, s):
        """
        :type s: str
        :rtype: bool
        """
        num_asc = list()
        s_list = s.split(' ')
        for ch in s_list:
            if ch.isnumeric():
                num_asc.append(int(ch))
        for i in range(1, len(num_asc)):
            if num_asc[i-1] >= num_asc[i]:
                return False
        return True