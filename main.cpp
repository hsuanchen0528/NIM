#include <bits/stdc++.h>
using namespace std;

int s[1000000];
int s_binary[100][100]={};
int n,row,how_many,sum=0,pss,ppss,f,yon=1;

void print_all();
void ten_to_two(int id,int number,int nim_sum[]);
void print_ten_to_two();
void pick(int nim_sum[]);
int choose(int nim_sum[]);
void operation(int i,int nim_sum[]);
void final_print(int row_c,int amount);

void ten_to_two(int id,int number,int nim_sum[]){ // �Q�i����G�i��
    int k=0,the_most=9;
    for(int i=0;i<10;i++)
       s_binary[id][i]=0;
    while(number>0){
        s_binary[id][k]=number%2;
        number=number/2;
        k++;
    }
    k--;
    for(;k>=0;k--)
        nim_sum[k]+=s_binary[id][k];
}
void print_all(){ //�L�X�{�p
    for(int i=1;i<=n;i++)
    {
        cout<<i;
        for(int j=1;j<=s[i];j++)
            cout<<" *";
        cout<<"\n";
    }
}
void print_ten_to_two(){//���R�G�i��G
    int nim_sum[10]={};
    for(int i=1;i<=n;i++)
       ten_to_two(i,s[i],nim_sum);
    for(int i=9;i>=0;i--)
        nim_sum[i]=nim_sum[i]%2 ;
    pick(nim_sum);
}
void pick(int nim_sum[]){ //�Ӯ����h��
    if(choose(nim_sum))
        for(int i=1;i<=n;i++)
            if(s[i]!=0){
                final_print(i,1);
                break;
            }
}
int choose(int nim_sum[]){//�����@�C
    for(int i=1;i<=n;i++)
    {
        for(int j=10;j>=0;j--)
        {
            if(s_binary[i][j]==0 and nim_sum[j]==1){
                break;
            }else if(s_binary[i][j]==1 and nim_sum[j]==1){
                operation(i,nim_sum);
                return 0;
            }
        }
    }
    return 1;
}
void operation(int i,int nim_sum[]){
    int plus_=0,minus_=0;
    for(int j=9;j>=0;j--)
    {
        if(nim_sum[j]!=0)
        {
            if(s_binary[i][j])
                minus_+=pow(2,j);
            else
                plus_+=pow(2,j);
        }
    }
    final_print(i,minus_-plus_);
}
void final_print(int row_,int amount){//���� (pc)
    cout<<"���� ��"<<row_<<"�C �� "<<amount<<"��\n";
    s[row_]-=amount;
    sum-=amount;
}

int main(){
    cout<<"--- �� �i �C �� --- \n";
    cout<<"�e�m�@�~: ���ƦC/��A�C�C/��ƶq�i���@�P\n";
    cout<<"ex:\n1 * * * *\n2 * *\n3 * * *\n4 *\n5 * * * *\n\n";
    cout<<"�C���W�h: �i�H���P�@�諸�ƭ�(�u�ள�P�@��A�ä��������ƥ�)�A�����̫�@�Ӫ��H���\n";
    cout<<"ex:\n�i������3�C���@�ӡB��ӡB�Υ����A������P�ɮ�����3�C���@�өM��2�C�@��\n\n"  ;
    cout<<" ----------------- \n";
    while(yon==1){
        yon=0;
        cout<<"�e�m�@�~:\n";
        cout<<"��J�C/��� ( 1<n<10 ):  ";
        cin>>n;
        cout<<"\n";
        while(n<=1 or n>9)
        {
            cout<<"��J���ȶW�X�d��,�ЦA���@��\n";
            cout<<"��J�C/��� ( 1<n<10 ):  ";
            cin>>n;
        }
        for(int i=1;i<=n;i++)
        {
            cout<<"��"<<i<<"�C/�� �� ? �� ( 0<n<10 ):  ";
            cin>>s[i];
            cout<<"\n";
            while(s[i]>9 or s[i]<=0)
            {
                cout<<"��J���ȶW�X�d��,�ЦA���@��\n";
                cout<<"��"<<i<<"�C/�� �� ? �� ( 0<n<10 ):  ";
                cin>>s[i];
                cout<<"\n";
            }
            sum+=s[i];
        }
        cout<<" ----------------- \n";
        cout<<"�}�l�C��:\n";

        srand( time(NULL) );
        pss=rand()%3 + 1;
        cout<<"��J�Ʀr(1�ŤM 2���Y 3��): ";
        cin>>ppss;
        cout<<"\n";
        while(1>ppss or ppss>3){
                cout<<"��J���ȶW�X�d��,�ЦA���@��\n"<<"\n��J�Ʀr(1�ŤM 2���Y 3��): ";
                cin>>ppss;
                cout<<"\n";
        }
        if(ppss==1 and pss==3){
            f=1;
        }else if(ppss==2 and pss==1){
            f=1;
        }else if(ppss==3 and pss==2){
            f=1;
        }else{
            f=0;
        }
        if(f==1){
           cout<<"�A������!\n";
        }else{
           cout<<"�A�����!\n";
        }
        if(f==1){
            while(sum!=0)
            {   cout<<"\nYOU: \n";
                print_all();

                cout<<"\n ���ĴX�C? ";
                cin>>row;
                cout<<" ���X��? ";
                cin>>how_many;
                cout<<"\n";
                while(row>n or s[row]<how_many){
                    cout<<"��J���ȶW�X�d��,�ЦA���@��\n"<<"\n ���ĴX�C? ";
                    cin>>row;
                    cout<<" ���X��? ";
                    cin>>how_many;
                    cout<<"\n";
                }
                s[row]-=how_many;
                sum-=how_many;
                print_all();
                cout<<"\n";
                if(sum==0){
                    cout<<"\nYOU WIN !\n"<<" ----------------- \n";
                    break;
                }
                cout<<"\n�q��: \n";
                print_ten_to_two();
                if(sum==0)
                    cout<<"\nYOU LOSE\n";
                cout<<" ----------------- \n";
            }
        }else{
             while(sum!=0)
            {
                cout<<"\n�q��: \n";
                print_ten_to_two();
                if(sum==0){
                    cout<<"\nYOU LOSE\n"<<" ----------------- \n";
                    break;
                }
                cout<<"\nYOU: \n";
                print_all();

                cout<<"\n ���ĴX�C? ";
                cin>>row;
                cout<<" ���X��? ";
                cin>>how_many;
                cout<<"\n";
                while(row>n or s[row]<how_many){
                    cout<<"��J���ȶW�X�d��,�ЦA���@��\n"<<"\n ���ĴX�C? ";
                    cin>>row;
                    cout<<" ���X��? ";
                    cin>>how_many;
                    cout<<"\n";
                }
                s[row]-=how_many;
                sum-=how_many;
                print_all();
                cout<<"\n";
                if(sum==0){
                    cout<<"\nYOU WIN !\n";
                }
                cout<<" ----------------- \n";
            }


        }
        cout<<" FINISH \n\n";
        cout<<"�n�A���@����? (1 yes /2 no): ";
        cin>>yon;
        cout<<"\n";
        while(yon!=2 and yon!=1)
        {
            cout<<"��J���ȶW�X�d��,�ЦA���@��\n";
            cout<<"�n�A���@����? (1 yes /2 no): ";
            cin>>yon;
            cout<<"\n";
        }


    }
    return 0;
}
