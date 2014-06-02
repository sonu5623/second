int bs(int l,int r,int c)
	{
	  if(l>r)
	  return -1; // not found
	  int mid = (l+r)/2;
	   if(prime[mid] == c)
	  return mid;
	  else if(prime[mid] > c)
	    bs(l,mid-1,c);
	  else
	  bs(mid+1,r,c);
	}
	
	// 0 indexing
