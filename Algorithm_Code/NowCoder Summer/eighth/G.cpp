#include<bits/stdc++.h>
using namespace std;
int T;
const int N=1e5+10;
const int M=2e5+10;
const int MOD=1e9+7;
struct lxe{
    int x,y,z;
}edge[M],mst[N];
bool cmp(lxe a,lxe b){
    return a.z<b.z;
}
struct lx{
    int nex,to,val;
}e[N*2];
int head[N],cnt=0;
void add(int x,int y,int z){
    cnt++;e[cnt].nex=head[x];e[cnt].to=y;e[cnt].val=z;head[x]=cnt;
}
int fa[N],maxx[N][20],father[N][20];
int dep[N];
void dfs(int x,int f){
    for(int i=head[x];i;i=e[i].nex){
        int v=e[i].to;
        if(v==f) continue;
        dep[v]=dep[x]+1;father[v][0]=x;maxx[v][0]=e[i].val;
        dfs(v,x);
    }
}
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
int get(int u,int v){//路径上边权最大值
    if(dep[u]<dep[v]) swap(u,v);
    int d=dep[u]-dep[v],ans=0;
    for(int i=0;i<=20;i++){
        if(d&(1<<i)){
            ans=max(ans,maxx[u][i]);u=father[u][i];
        }
    }
    if(u==v) return ans;
    for(int i=19;i>=0;i--){
        if(father[u][i]!=father[v][i]){
            ans=max(ans,max(maxx[u][i],maxx[v][i]));
            u=father[u][i];v=father[v][i];
        }
    }
    ans=max(ans,max(maxx[u][0],maxx[v][0]));
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        //输入
        int n,m,k;cin>>n>>m>>k;memset(dep,0,sizeof(dep));
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        for(int i=1;i<=m;i++){
            int u,v,w;cin>>u>>v>>w;edge[i].x=u;edge[i].y=v;edge[i].z=w;
            int fu=find(u),fv=find(v);
            fa[fv]=fu;
        }


        int v=0;//分量的数量
        int vis[N];memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            int f=find(i);
            if(vis[f]==0) v++;
            vis[f]++;
        }
        if(v>2){
            cout<<0<<endl;continue;
        }
        else if(v==2){
            long long ans=0;
            ans=(n%MOD)*((n-vis[find(1)])%MOD)*(k%MOD)%MOD;
            cout<<ans<<endl;continue;
        }
        else{
            sort(edge+1,edge+m+1,cmp);
            for(int i=1;i<=n;i++) fa[i]=i;
            int cnt1=0,cnt=0;memset(head,0,sizeof(head));
            for(int i=1;i<=m;i++){
                if(cnt1==n-1) break;
                int u=edge[i].x,v=edge[i].y,w=edge[i].z;
                int fu=find(u),fv=find(v);
                if(fu==fv) continue;
                mst[i].x=u;mst[i].y=v;mst[i].z=w;
                cnt1++;fa[fv]=fu;
                add(i,v,w);add(v,u,w);
            }
            dfs(1,0);
            for(int i=0;i<20;i++){
                for(int j=1;j<=n;j++){
                    int p=father[j][i-1];
                    father[j][i]=father[p][i-1];
                    maxx[j][i]=max(maxx[j][i-1],maxx[p][i-1]);
                }
            }
            long long ans=0,sum=0,diff=0;memset(vis,0,sizeof(vis));
            for(int i=1;i<=n;i++) fa[i]=i;
            for(int i=1;i<=n-1;i++){
                int u=mst[i].x,v=mst[i].y,w=mst[i].z;
                int fu=find(u),fv=find(v);
                if(fu==fv) continue;
                long long su=vis[fu],sv=vis[fv];
                long long con=min((long long)k,(long long)(w-1));
                sum+=(su%MOD)*(sv%MOD)*(con%MOD)%MOD;
                if(vis[fu]<vis[fv]) swap(fu,fv);
                vis[fu]+=vis[fv];fa[fv]=fu;
            }
            for(int i=1;i<=m;i++){
                int u=edge[i].x,v=edge[i].y;
                int maxw=get(u,v);
                long long con=min((long long)k,(long long)(maxw-1));
                diff=(diff+con)%MOD;
            }
            ans=(sum-diff)%MOD;
            if(ans<0) ans+=MOD;
            cout<<ans<<endl;
        }
    }
    return 0;
}