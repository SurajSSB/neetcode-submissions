class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int right = nums.size() -1 ;
        int left =0; int count = 0;
        //for (int i = 0; i < sizeN; i++)
        while(left < right)
        {
            int mid = (left+right)/2;
           
            if(nums[right] < nums[mid])
                left = mid + 1;
            else
                right = mid;            
        }    

        int pivot = left;
         cout<< pivot <<"\n";
        int res = BinarySearch(nums,target, 0, pivot-1);
        if(res != -1)
            return res;

        return BinarySearch(nums,target, pivot, nums.size() - 1);
    }

    int BinarySearch(vector<int>& nums, int target, int left, int right)
    {
        //int right = nums.size() -1 ;
        //int left =0; 
        int count = 0; 
        //for (int i = 0; i < sizeN; i++)
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(target == nums[mid])
                return mid;
            if(target < nums[mid])
                right = mid -1;
            else
                left = mid + 1;

            cout<< mid<<", " << left << "," << right <<"\n";
        }    
        return -1; 
    }
};
