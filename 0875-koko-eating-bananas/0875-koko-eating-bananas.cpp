class Solution {
public:
    long long countTimes(vector<int>&a, int n, int speed){
        long long h=0;
        for(int i=0;i<n;i++){
            h +=a[i]/speed;
            if(a[i]%speed!=0){
                h++;
            }
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int high = *max_element(piles.begin(),piles.end());
        int res = -1;
        while(l<=high){
            int mid =l+(high-l)/2;
            long long hr = countTimes(piles,n,mid);
            if(hr>h){
                l = mid+1;
            }
            else{
                res = mid;
                high = mid-1;

            }

        }
        return res;
    }
};