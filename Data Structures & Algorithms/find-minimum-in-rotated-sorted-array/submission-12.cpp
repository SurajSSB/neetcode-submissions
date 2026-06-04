class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int l = nums.size() - 1;
        int f = 0;
        int m = nums.size()/2;
        int min = 0;
        if(!nums.empty())
           min = nums[0]; 
        if(nums.size() == 2)
           if(min > nums[1])
              min= nums[1]; 

        //cout<< f <<", "<<m <<", "<<l <<"\n";
        int counter = 0;
        while(f < m && m < l && f != m && m != l)
        {     
            counter++;
            cout<< f <<", "<<m <<", "<<l <<"\n";
            //1*2*3
            if((nums[f] < nums[m]) && (nums[m] < nums[l]))
            {
                min = nums[f];
                l = m;             
            }
            else if ((nums[f] < nums[m]) && (nums[l] < nums[f]))
            {
                min = nums[l];  
                f = m;              
            }  
            else if ((nums[f] > nums[m]) && (nums[m] < nums[f]))
            {
                min = nums[m];

                if((f+1) != m) f = f + 1;

                else if((l-1) != m) l = l -1;

                else break;
            }
            else
            {
                min = nums[f];
                l = m;
            }
            
            
             m = (f+l +1)/2;

            if(counter > 1000)
                break;

           
        }
        return min;
    }
};
