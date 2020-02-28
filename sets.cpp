#include<iostream>
#include<cmath>
using namespace std;
template <typename S>
class Myset
{
    S *a;
    int size;
    public:
    Myset(int size = 0)
    {
        a=new S[size];
        this->size=size;
    }
    void input()
    {
        for(int i=0;i<size;i++)
        {
            cin>>a[i];
        }
        remove_dup();
    }
    void remove_dup()
    {
        for(int i=0;i<size;i++)
            for(int j=i+1;j<size;j++)
                if(a[i]==a[j])
                {
                    for(int k=j;k<size;k++)
                    {
                        a[k]=a[k+1];
                    }
                    j--;
                    size--;
                }
    }
    Myset operator+(const Myset obj)
    {
        Myset union_1(size+obj.size);
        int index=0;
        for(int i=0;i<size;i++)
        {
            union_1.a[index++]=a[i];
        }
        for(int i=0;i<obj.size;i++)
        {
            union_1.a[index++]=obj.a[i];
        }
        union_1.remove_dup();
        return union_1;   
    } 
     Myset operator*(const Myset obj)
    {
        int temp,index=0;
        if(size<obj.size)
        temp=size;
        else
        temp=obj.size;
        Myset intersection(temp);
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<obj.size;j++)
            {
              if(a[i]==obj.a[j])
              {
                intersection.a[index++]=a[i];
              }
            }
        }
        intersection.size=index;
        return intersection;
    }
     Myset operator-(const Myset obj)
    {
        int count = 0;
            for(int index = 0; index < size; ++index)
            {
                int flag = 0;
                for(int check = 0; check < obj.size; ++check)
                    if(a[index] == obj.a[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    count++;
            }
            Myset temp(count);
            int temp_index = 0;
            for(int index = 0; index < size; ++index)
            {
                int flag = 0;
                for(int check = 0; check < obj.size; ++check)
                    if(a[index] == obj.a[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    temp.a[temp_index++] = a[index];
            }
            return temp;
    }
     Myset operator^(const Myset obj)
    {
        int count = 0;
            for(int index = 0; index < size; ++index)
            {
                int flag = 0;
                for(int check = 0; check < obj.size; ++check)
                    if(a[index] == obj.a[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    count++;
            }
            for(int index = 0; index < obj.size; ++index)
            {
                int flag = 0;
                for(int check = 0; check < size; ++check)
                    if(obj.a[index] == a[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    count++;
            }
            Myset temp(count);
            count = 0;
            for(int index = 0; index < size; ++index)
            {
                int flag = 0;
                for(int check = 0; check < obj.size; ++check)
                    if(a[index] == obj.a[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    temp.a[count++] = a[index];
            }
            for(int index = 0; index < obj.size; ++index)
            {
                int flag = 0;
                for(int check = 0; check < size; ++check)
                    if(obj.a[index] == a[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    temp.a[count++] = obj.a[index];
            }
            return temp;
    }
    void display()
    {
        cout<<"ELEMENTS OF SET : {";
        for(int i=0;i<size;i++)
        {
            cout<<a[i]<<" , ";
        }cout<<" "<<"\b"<<"}";
    }
    void cardinality()
    {
        cout<<"CARDINALITY : "<<size;
    }
    Myset operator=(const Myset obj)
    {
        Myset temp(obj.size);
        for(int i=0;i<obj.size;i++)
        {
            temp.a[i]=obj.a[i];
        }
        return temp;
    }
    bool operator==(const Myset obj)
    {
        if(size != obj.size)
                return false;
            else
            {
                int flag = 0;
                for(int index = 0; index < size; ++index)
                    for(int check = 0; check < obj.size; ++check)
                        if(a[index] == obj.a[check])
                            flag++;
                if(flag == size)
                    return true;
                else
                    return false;
            }

    }
    void powerSet()
        {
            cout<<"PowerSet: ";
            int sizee = pow(2, size);
            for(int counter = 0; counter < sizee; ++counter)
            {
                int count_elements = 0;
                cout << "{ ";
                for(int set = 0; set < size; ++set)
                    if(counter & (1 << set))
                    {
                        if(count_elements != 0)
                            cout << ", ";
                        cout << a[set];
                        count_elements++;
                    }
                cout << " }";
                if(counter != sizee - 1)
                    cout << ", ";
            }
        }
}; 


int main()
{
    int choice= 0;
    char var= 'N';
    do
    {
        cout << "***** \t MENU \t*****\n";
        cout << "Choose the type of data in the set...\n";
        cout << "1. Integer\n";
        cout << "2. String\n";
        cout << "3. Float\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: {
                        int size1= 0, size2= 0;
                        cout << "Enter the number of elements in the 1st Set: ";
                        cin >> size1;
                        cout << "Enter the number of elements in the 2nd Set: ";
                        cin >> size2;
                        Myset <int> Set1 (size1);
                        cout << "Enter the elements of 1st Set...\n";
                        Set1.input();
                        Myset <int> Set2(size2);
                        cout << "Enter the elements of 2nd Set...\n";
                        Set2.input();
                        cout<<endl;
                        Myset <int> Set3 = Set1 + Set2;        //To store the union_1 of the two sets
                        Set3.display();
                        cout<<endl;
                        Myset <int> Set4 = Set1 * Set2;       //To store the intersection of the two sets
                        Set4.display();
                        cout<<endl;
                        Myset <int> Set5 = Set1 - Set2;        //To store the difference of the two sets
                        Set5.display();
                        cout<<endl;
                        Myset <int> Set6 = Set1 ^ Set2;        //To store the symmetric difference of two sets
                        Set6.display();
                        cout<<endl;
                        Set1.powerSet();
                        cout<<endl;
                        Set2.powerSet();
                        cout<<endl;
                        bool answer =Set1 == Set2;
                        if(answer)
                        cout<<"sets are equal";
                        else
                        cout<<"sets are not equal";
                        break;
                    }
            case 2: {
                        int size1= 0, size2= 0;
                        cout << "Enter the number of elements in the 1st Set: ";
                        cin >> size1;
                        cout << "Enter the number of elements in the 2nd Set: ";
                        cin >> size2;
                        Myset <char> Set1 (size1);
                        cout << "Enter the elements of 1st Set...\n";
                        Set1.input();
                        Myset <char> Set2(size2);
                        cout << "Enter the elements of 2nd Set...\n";
                        Set2.input();
                        cout<<endl;
                        Myset <char> Set3 = Set1 + Set2;        //To store the union_1 of the two sets
                        Set3.display();
                        cout<<endl;
                        Myset <char> Set4 = Set1 * Set2;       //To store the intersection of the two sets
                        Set4.display();
                        cout<<endl;
                        Myset <char> Set5 = Set1 - Set2;        //To store the difference of the two sets
                        Set5.display();
                        cout<<endl;
                        Myset <char> Set6 = Set1 ^ Set2;        //To store the symmetric difference of two sets
                        Set6.display();
                        cout<<endl;
                        Set1.powerSet();
                        cout<<endl;
                        Set2.powerSet();
                        cout<<endl;
                        bool answer =Set1 == Set2;
                        if(answer)
                        cout<<"sets are equal";
                        else
                        cout<<"sets are not equal";
                        break;
                    }
            case 3: {
                        int size1= 0, size2= 0;
                        cout << "Enter the number of elements in the 1st Set: ";
                        cin >> size1;
                        cout << "Enter the number of elements in the 2nd Set: ";
                        cin >> size2;
                        Myset <float> Set1 (size1);
                        cout << "Enter the elements of 1st Set...\n";
                        Set1.input();
                        Myset <float> Set2(size2);
                        cout << "Enter the elements of 2nd Set...\n";
                        Set2.input();
                       cout<<endl;
                        Myset <float> Set3 = Set1 + Set2;        //To store the union_1 of the two sets
                        Set3.display();
                        cout<<endl;
                        Myset <float> Set4 = Set1 * Set2;       //To store the intersection of the two sets
                        Set4.display();
                        cout<<endl;
                        Myset <float> Set5 = Set1 - Set2;        //To store the difference of the two sets
                        Set5.display();
                        cout<<endl;
                        Myset <float> Set6 = Set1 ^ Set2;        //To store the symmetric difference of two sets
                        Set6.display();
                        cout<<endl;
                        Set1.powerSet();
                        cout<<endl;
                        Set2.powerSet();
                        cout<<endl;
                        bool answer =Set1 == Set2;
                        if(answer)
                        cout<<"sets are equal";
                        else
                        cout<<"sets are not equal";
                        break;
                    }        

            default: cout << "Wrong choice of Options!!!";
        }
        cout << "\nDo you want to operate more (Y/N): ";
        cin >> var;
        system("cls");
    } while (var == 'Y' || var == 'y');
    return 0;
}