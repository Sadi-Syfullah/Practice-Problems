#include<iostream>
using namespace std;
int main()
{
   // dynamic arrays.(dfa,nfa,and alphabets).
   char **dfa_trans = 0;
    dfa_trans = new char *[3] ;
    for( int i = 0 ; i < 3 ; i++ )
    {
        dfa_trans[i] = new char[2];
    }
   // dfa transition function.
    char **nfa_trans = 0;
    nfa_trans = new char *[3] ;
    for( int i = 0 ; i < 3 ; i++ )
    {
        nfa_trans[i] = new char[2];
    }
    //nfa tansition function
    char *dfa_state = 0;
    dfa_state = new char [3] ;
   //dfa states
    char *nfa_state = 0;
    nfa_state = new char [3] ;
   // nfa states
   char *dfa_start = 0;
    dfa_start = new char [3] ;
    //dfa start states
     char *Alphabet = 0;
    Alphabet = new char [3] ;
    //aplahbets integers,chars;
    int i,j,k,n_alphabet,n_nfastate,e=0,c=0,temp=0;
    char nfa_start;
    //program start
    cout<<"Please enter the number of alphabes you wish to use:"<<endl;
    cin>>n_alphabet;
    cout<<"Please enter alphabets.Note: e stands for ebsilon!!"<<endl;
    for (i=0; i<n_alphabet; i++)
        cin>>Alphabet[i];
    cout<<"Please enter the number of states you need to use:"<<endl;
    cin>>n_nfastate;
    cout<<"Enter name of states:"<<endl;
    for (i=0; i<n_nfastate; i++)
        cin>>nfa_state[i];
    cout<<"Please enter your start state:"<<endl;
    cin>>nfa_start;
    cout<<"Enter * if you don't wish to use an alphabet!!"<<endl;
    for(j=0; j<n_nfastate; j++)
    {
        cout<<"At state "<<nfa_state[j];
        for(i=0; i<n_alphabet; i++)
        {
            cout<<" if alphabet "<<"'"<<Alphabet[i]<<"'"<<" go to: ";
            cin>>nfa_trans[i][j];
            if(Alphabet[i]=='e' && nfa_trans[i][j]!='*')
            {
                e++;
                dfa_start[e-1]=nfa_state[j];
            }
        }
    }
    cout<<"****************e= "<<e<<endl;
    for(k=0; k<e; k++)
    {
        if(dfa_start[k]!=nfa_start)
        {
            c++;
        }
    }
    if(c==e)
    {
        dfa_start[e]=nfa_start;
        e++;
    }
    for(k=0; k<e; k++) if(dfa_start[e-1]<dfa_start[k])
        {
            temp=dfa_start[k];
            dfa_start[k]=dfa_start[e-1];
            dfa_start[e-1]=temp;
        }
    cout<<"e= "<<e<<endl;
    cout<<"Dfa states:"<<endl;
    for(k=0; k<e; k++)
    {
        cout<<dfa_start[k]<<endl;
    }
    cout<<"Your nfa transition function is the following:"<<endl;
    for(j=0; j<n_nfastate; j++)
    {
        cout<<endl;
        for(i=0; i<n_alphabet; i++)
        {
            cout<<nfa_trans[i][j]<<"	";
        }
        cout<<endl;
    }
    cout<<"Dfa transition function:"<<endl;
    for(k=0; k<e; k++)
    {
        for(i=0; i<n_alphabet-1; i++)
        {
            if(Alphabet[i]!='e' && nfa_trans[i][k]=='*')
            {
                nfa_trans[i][k]=dfa_start[k];
            }
            cout<<"At state "<<" "<<dfa_start[k]<<" at alphabet "<<"'"<<Alphabet[i]<<"'"<<" go to: "<<nfa_trans[i][k]<<endl;
        }
    }
    cout<<endl;
    return 0;
}
