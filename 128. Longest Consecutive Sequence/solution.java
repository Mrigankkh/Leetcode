class Solution {

    private int helper(HashMap<Integer,Integer> umap,int i)
    {

        if(umap.get(i)!=0)
        return umap.get(i);
        if(umap.get(i-1)== null)
        {
            umap.put(i,1);
            return 1;
        }


        else 
        {
        
        umap.put(i,1 + helper(umap, i-1) );
        return umap.get(i); 

        }
    }


    public int longestConsecutive(int[] nums) {
        
        if(nums.length== 0)
        return 0;
        HashMap<Integer, Integer> umap = new HashMap<>();

        for(int num: nums)
        {

            if(umap.get(num)==null)
            {
                umap.put(num, 0);
            }
        }

        for(int i : umap.keySet())
        {
            if(umap.get(i-1)== null)
            {
                umap.put(i,1);
            }
            else
            {
                helper(umap,i);
            }
        }
        int ans = Integer.MIN_VALUE;
         for(int i : umap.keySet())
         {

            ans = Math.max(ans, umap.get(i));
         }

         return ans;


    }
}