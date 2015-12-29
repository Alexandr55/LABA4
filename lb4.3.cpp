#include "sdt.h"

void In_Binary(uint8_t byte)
{
    for(int i=0; i<4; i++)
    {
        if ((byte) & (128>>i))
            cout << '1';
        else
            cout << '0';
    }
     cout<<" ";
     for(int i=4; i<8; i++)
    {
        if ((byte) & (128>>i))
            cout << '1';
        else
            cout << '0';
    }
    cout<<" ";
}
void To_Hex(int value)
{
    switch(value)
    {
    case 15:
        cout<<"F";
        break;
    case 14:
        cout<<"E";
        break;
    case 13:
        cout<<"D";
        break;
    case 12:
        cout<<"C";
        break;
    case 11:
        cout<<"B";
        break;
    case 10:
        cout<<"A";
        break;
    case 9:
        cout<<"9";
        break;
    case 8:
        cout<<"8";
        break;
    case 7:
        cout<<"7";
        break;
    case 6:
        cout<<"6";
        break;
    case 5:
        cout<<"5";
        break;
    case 4:
        cout<<"4";

        break;
    case 3:
        cout<<"3";
        break;
    case 2:
        cout<<"2";
        break;
    case 1:
        cout<<"1";
        break;
    case 0:
        cout<<"0";
        break;

    }

}

void In_hex(uint8_t byte)
{
    uint8_t del=byte/16;
    uint8_t ost=byte%16;
    To_Hex(del);
    To_Hex(ost);
      cout<<" ";
}

void print_in_binary(const void* data, size_t size)
{
    uint8_t* bytes=(uint8_t*) data;
    for(uint8_t i=(size/2); i<size; i++)
    {
        uint8_t byte=*(bytes+i);
        In_Binary(byte);
    }
    for(uint8_t i=0; i<(size/2); i++)
    {
        uint8_t byte=*(bytes+i);
        In_Binary(byte);
    }
}
void print_in_hex(const void* data, size_t size)
{
    uint8_t* bytes=(uint8_t*) data;
    for(int i=(size/2); i<size; i++)
    {
        uint8_t byte=*(bytes+i);
        In_hex(byte);
    }
    for(int i=0; i<(size/2); i++)
    {
        uint8_t byte=*(bytes+i);
        In_hex(byte);
    }
}
struct student
{
    char name[17];
    short year;
    float mean;
    bool sex;
    short curs;
    student* starost;
};
int main()
{
    student Group[3];

    strcpy(Group[0].name,"Sam");
    Group[0].year=2005;
    Group[0].mean=3.4;
    Group[0].sex=true;//man
    Group[0].curs=6;
    Group[0].starost=NULL;

    strcpy(Group[1].name,"Sara");
    Group[1].year=2010;
    Group[1].mean=4.2;
    Group[1].sex=false;//woman
    Group[1].curs=4;
    Group[1].starost=Group[0].starost;

    strcpy(Group[2].name,"Alex");
    Group[2].year=2008;
    Group[2].mean=1.9;
    Group[2].sex=true;//man
    Group[2].curs=5;
    Group[2].starost=Group[0].starost;

    cout<<"Array adress="<<Group<<"  "<<"size="<<sizeof(Group)<<"\n";
    cout<<"Group[0] adress="<<Group<<"  "<<"size="<<sizeof(Group[0])<<"\n";
    cout<<"Group[1] adress="<<Group+1<<"  "<<"size="<<sizeof(Group[1])<<"\n";
    cout<<"Group[2] adress="<<Group+2<<"  "<<"size="<<sizeof(Group[2])<<"\n";
    cout<<"\n";

    cout<<"Student 1(Group[1]):\n";
    cout<<"field name:adress:"<<&Group[1].name<<"\n";
    cout<<"offset="<<offsetof(student,name)<<"\n";
    cout<<"size="<<sizeof(Group[1].name)<<"\n";
    print_in_hex(Group[1].name,sizeof(Group[1].name));
    cout<<"\n";
    print_in_binary(Group[1].name,sizeof(Group[1].name));
    cout<<"\n";

    cout<<"field year:adress:"<<&Group[1].year<<"\n";
    cout<<"offset="<<offsetof(student,year)<<"\n";
    cout<<"size="<<sizeof(Group[1].year)<<"\n";
    print_in_hex(&Group[1].year,sizeof(Group[1].year));
    cout<<"\n";
    print_in_binary(&Group[1].year,sizeof(Group[1].year));

    cout<<"\n";
    cout<<"field mean:adress:"<<&Group[1].mean<<"\n";
    cout<<"offset="<<offsetof(student,mean)<<"\n";
    cout<<"size="<<sizeof(Group[1].mean)<<"\n";
    print_in_hex(&Group[1].mean,sizeof(Group[1].mean));
    cout<<"\n";
    print_in_binary(&Group[1].mean,sizeof(Group[1].mean));

    cout<<"\n";
    cout<<"field curs:adress:"<<&Group[1].curs<<"\n";
    cout<<"offset="<<offsetof(student,curs)<<"\n";
    cout<<"size="<<sizeof(Group[1].curs)<<"\n";
    print_in_hex(&Group[1].curs,sizeof(Group[1].curs));
    cout<<"\n";
    print_in_binary(&Group[1].curs,sizeof(Group[1].curs));

    cout<<"\n";
    cout<<"field starost:adress:"<<&Group[1].starost<<"\n";
    cout<<"offset="<<offsetof(student,starost)<<"\n";
    cout<<"size="<<sizeof(Group[1].starost)<<"\n";
    print_in_hex(&Group[1].starost,sizeof(Group[1].starost));
    cout<<"\n";
    print_in_binary(&Group[1].starost,sizeof(Group[1].starost));
    cout<<"\n";

    for(int i=0; i<=2; i++)
    {
        cout<<"Group["<<i<<"]\n";
        cout<<"name\n";
        print_in_hex(Group[i].name,sizeof(Group[i].name));
        cout<<"\n";
        cout<<"year\n";
        print_in_hex(&Group[i].year,sizeof(Group[i].year));
        cout<<"\n";
        cout<<"mean\n";
        print_in_hex(&Group[i].mean,sizeof(Group[i].mean));
        cout<<"\n";
        cout<<"sex\n";
        print_in_hex(&Group[i].sex,sizeof(Group[i].sex));
        cout<<"\n";
        cout<<"curs\n";
        print_in_hex(&Group[i].curs,sizeof(Group[i].curs));
        cout<<"\n";
        cout<<"starost\n";
        print_in_hex(&Group[i].starost,sizeof(Group[i].starost));
        cout<<"\n";
    }
}
