int hlen;
int hep[128];
int h2p[128];
int pmulp[128];
vector<int> numlist;
void swap(int i,int j)
{
    int t;
    t=hep[j];
    hep[j]=hep[i];
    hep[i]=t;
    t=h2p[j];
    h2p[j]=h2p[i];
    h2p[i]=t;
    return;
}
void down(int i)
{
    int l,r,t;
    while(i<=hlen/2)
    {
        l=i*2;
        t=i;
        if(hep[l]<hep[i])
            t=l;
        if((l+1)<=hlen&&hep[l+1]<hep[t])
            t=l+1;
        if(t==i)
            break;
        else
        {
            swap(i,t);
            i=t;
        }
    }
    return;
}
int extractmin(vector<int>& primes)
{
    int min_num=hep[1];
    int pp,pmuln,nn;
    numlist.push_back(min_num);
    while(hep[1]==min_num)
    {
        pp=h2p[1];
        pmulp[pp]++;
        pmuln=pmulp[pp];
        nn=primes[pp]*numlist[pmuln];
        hep[1]=nn;
        down(1);
    }
    return min_num;
}
void init(int n,vector<int>& primes)
{
    for(int i=0;i<n;i++)
    {
        h2p[i+1]=i;
        hep[i+1]=primes[i];
    }
    return;
}
int nthSuperUglyNumber(int n, vector<int>& primes) {
    int min_num;
    hlen=primes.size();
    init(hlen,primes);
    numlist.push_back(1);
    if(n==1)
        return 1;
    for(int i=1;i<n;i++)
    {
        min_num=extractmin(primes);
    }
    return min_num;
} 