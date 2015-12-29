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
int main()
{
    uint16_t val1,val2;
    char znak;
    uint16_t result;
    cout<<"Enter expression: "<< endl;
    cin>>val1>>znak>>val2;
    switch(znak)
    {
    case '&':
        result=val1&val2;
        break;
    case '^':
        result=val1^val2;
        break;
    case '|':
        result=val1|val2;
        break;
    }
    cout <<"Result in hex (two byte)"<<endl;
    print_in_hex(&val1,sizeof(val1));
    cout <<" " << znak <<" ";
    print_in_hex(&val2,sizeof(val2));
    cout <<" = ";
    print_in_hex(&result,sizeof(result));
    cout<<"\n";
    cout <<"Result in binary (two byte)"<<endl;
    print_in_binary(&val1,sizeof(val1));
    cout <<" " << znak <<" ";
    print_in_binary(&val2,sizeof(val2));
    cout <<" = ";
     print_in_binary(&result,sizeof(result));
    return 0;
}
