#include<bits/stdc++.h>
using namespace std;
char s1[100],s2[100];
int ln1,ln2,mmm[100][100];
void fun()
{
    for(int i=0;i<=ln1;i++)mmm[i][0]=0;
    for(int i=0;i<ln2;i++)mmm[0][i]=0;
    for(int i=0; i<ln1; i++)
    {
        for(int j=0; j<ln2; j++)
        {
            if(s1[i]==s2[j])
                mmm[i][j]=mmm[i-1][j-1]+1;
            else
                mmm[i][j]=max(mmm[i-1][j],mmm[i][j-1]);
                ///jodi table dekhte chas tahole nicher print ta kor
            //cout<<mmm[i][j]<<' ';
        }
       // cout<<'\n';
    }
}
int main()
{
    cin>>s1>>s2;
    ln1=strlen(s1);
    ln2=strlen(s2);
    fun();
    cout<<mmm[ln1-1][ln2-1]<<'\n';
}
