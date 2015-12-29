#include "sdt.h"
bool err=true;
void NameChecking(char* name)
{
    for(int i=0; i<strlen(name); ++i)
    {
        if (name[i]=='*' || name[i]=='"' || name[i]=='<' || name[i]=='>' || name[i]=='?' || name[i]=='|')
        {
            cout <<"Error: symbol " <<name[i] <<endl;
            err=true;
        }
    }
    if (strchr(name,':')==&name[0])
    {
        cout<<"Error: the symbol \":\" on the first position"<<endl;
        err=true;
    }
    else
        for (int i=1; i<strlen(name)-1; ++i)
        {
            if(name[i]==':')
            {
                if(!isalpha(name[i-1]))
                {
                    cout <<"before : not a letter"<<endl;
                    err=true;
                }
                if(name[i+1]!='\\')
                {
                    cout <<"after : not \\"<<endl;
                    err=true;
                }
            }
        }
    char name1[4];
    for(int i=0; i<4; ++i)
        name1[i]=name[strlen(name)-4+i];

    if ( strncmp( name1, ".txt", 4 ) != 0 && strncmp( name1, ".TXT", 4 ) != 0)
    {
        cout<<"The extension does not .txt' (.TXT)"<<endl;
        err=true;
    }
}
int main()
{
    char NameFile[22];
    while (err)
    {
        err=false;
        cout <<"Enter the name of the file (.txt)\n";
        cin >>NameFile;
        NameChecking(NameFile);
        cout <<endl;
    }
    FILE * ptrFile = fopen(NameFile, "a+");
    fseek(ptrFile,0,SEEK_END);
    int size = ftell(ptrFile);
    cout <<"Size file: "<<size<<endl;
    fseek(ptrFile,0,SEEK_SET);
    char *mass = new char[ size +1 ];
    size_t result = fread(mass, sizeof(char), size, ptrFile);
    cout <<endl<<"The contents of the file:"<<endl;
    puts(mass);
    cout <<endl <<"Enter a search string:  ";
    char stroca[10];
    cin >>stroca;
    char *cp = (char *) mass;
    char *s1, *s2;
    while(*cp)
    {
        s1 = cp;
        s2 = (char *) stroca;
        while ( *s1 && *s2 && !(*s1-*s2) )
            s1++, s2++;
        if (!*s2)
            cout<<"Position of the string: "<<(cp-mass+1)<<"\n";
        cp++;
    }
    int * pos=new int [20];
    int number=0;
    pos[0]=-1;
    for(int i=0; i<size; ++i)
        if(mass[i] == '.' || mass[i] == '?' || mass[i] == '!')
        {
            ++number;
            pos[number]=i;
        }
    cout <<endl<<"The number of proposals: "<<number<<endl;
    char ** proparray=new char*[number];
    for(int i=0; i<number; ++i)
    {
        fseek(ptrFile, pos[i]+1,SEEK_SET);
        char * mass1 = new char[pos[i+1]];
        fread(mass1,sizeof(char),pos[i+1],ptrFile);
        char * mass2 = new char[pos[i+1]];
        proparray[i]= strncpy(mass2, mass1, (pos[i+1]-pos[i])*sizeof(char));
        delete [] mass1;
    }
    fclose (ptrFile);
    cout<<endl;
    for(int i=0; i<number; ++i)
        cout<<i+1<<" proposal ("<<strlen(proparray[i])<<") : "<<proparray[i]<<"\n";
    char * c;
    for (int i = 0; i < number - 1; i++)
    {
        for (int j = 0; j < number - i - 1; j++)
        {
            if (strlen(proparray[j]) > strlen(proparray[j+1]))
            {
                c=proparray[j];
                proparray[j]=proparray[j+1];
                proparray[j+1]=c;
            }
        }
    }
    cout<<endl<<endl<<"After sorting:\n";
    for(int i=0; i<number; ++i)
        cout<<i+1<<" proposal ("<<strlen(proparray[i])<<") : "<<proparray[i]<<"\n";
    char NameFile2[20];
    err=true;
    while (err)
    {
        err=false;
        cout <<"Enter the name of the file (.txt)\n";
        cin >>NameFile2;
        NameChecking(NameFile2);
        cout <<endl;
    }
    FILE * ptrFile2 = fopen(NameFile2, "a+");
    fseek(ptrFile2,0,SEEK_SET);
    for(int i=0; i<number; ++i)
        fputs(proparray[i], ptrFile2);
    fclose (ptrFile2);
    for(int i=0; i<number; ++i)
    {
        delete[] proparray[i];
    }
    delete [] mass, pos, cp, proparray;
    delete s1, s2, c;
}
