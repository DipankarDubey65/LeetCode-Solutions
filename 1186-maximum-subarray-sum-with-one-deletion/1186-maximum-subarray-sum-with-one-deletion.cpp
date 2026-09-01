class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete = arr[0];
        int res = arr[0];
        int onedelete = INT_MIN;
        for(int i=1;i<arr.size();i++){
            int prevnodelete = nodelete;
            int prevondelete = onedelete;
            nodelete = max(nodelete+arr[i],arr[i]);
            int v2;
            if(prevondelete == INT_MIN){
                v2 =arr[i];
            }
            else{
                v2 = prevondelete+arr[i];
            }
            onedelete = max(v2,prevnodelete);
            res = max(res, max(onedelete, nodelete));

        }
        return res;
    }
};