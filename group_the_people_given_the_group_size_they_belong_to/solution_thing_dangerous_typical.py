class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        res_list = []
        interm_group = []
        for i in range(len(groupSizes)):
            interm_group.append((i, groupSizes[i]))
        
        interm_group.sort(key=lambda x: x[1])

        temp_list = [interm_group[0][0]]
        group_curr = interm_group[0][1]

        for i in range(1, len(groupSizes)):
            if (interm_group[i][1] == group_curr) and len(temp_list) < group_curr:
                temp_list.append(interm_group[i][0])

            else:
                res_list.append(temp_list)
                group_curr = interm_group[i][1]
                temp_list = [interm_group[i][0]]

        res_list.append(temp_list)
        return res_list