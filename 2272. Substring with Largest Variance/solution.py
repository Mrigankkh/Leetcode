class Solution:
    def largestVariance(self, s: str) -> int:

        def helper(s,c1,c2):

            curr_sum = 0


            for i in range(2):
                count_c1 = 0
                count_c2 = 0
                for c in s:
                    if c!=c1 and c!=c2:
                        continue
                    elif c==c1:
                        count_c1+=1
                    elif c==c2:
                        count_c2+=1
                    
                    if count_c1-count_c2<0:
                        count_c1=count_c2=0
                    elif count_c1>0 and count_c2>0:
                        curr_sum = max(curr_sum,count_c1-count_c2)

                s = s[::-1]
            
            return curr_sum
            
                


        # Find all char pairs
        all_chars = set(s)

        # Iterate over all char pairs
        max_variance = 0
        for c1 in all_chars:
            for c2 in all_chars:
                if c1==c2:
                    continue
                
                max_variance = max(max_variance,helper(s,c1,c2))
        return max_variance



        