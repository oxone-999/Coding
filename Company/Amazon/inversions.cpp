long long merge(long long arr[],long long temp[],long long l,long long mid,long long r)
    {
        int i = l;
        int j = mid;
        int k = l;
        
        long long inv = 0;
        
        while(i <= mid-1 && j <= r)
        {
            if(arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else 
            {
                temp[k++] = arr[j++];
                inv += mid-i;
            }
        }
        
        while(i<=mid-1)
        {
            temp[k++] = arr[i++];
        }
        
        while(j<=r)
        {
            temp[k++] = arr[j++];
        }
        
        for (i = l; i <= r; i++)
        arr[i] = temp[i];
        
        return inv;
    }

    long long mergeSort(long long arr[],long long temp[],long long l,long long r)
    {
        long long inv = 0;
        int mid;
        if(l<r){
            mid = l + (r-l)/2;
            inv += mergeSort(arr,temp,l,mid);
            inv += mergeSort(arr,temp,mid+1,r);
            inv += merge(arr,temp,l,mid+1,r);
        }
        return inv;
    }
    
    long long inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        
        memset(temp,0,sizeof(temp));
        
        return mergeSort(arr,temp,0,N-1);
    }