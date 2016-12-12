

class intSet
{
    public:
        intSet();                               //--构造函数
        intSet(const intSet& A);                //--复制构造函数
        ~intSet()                               //--析构函数
        {
            delete []element;
        }
        void Empty();                           //--清空整数集合
        void IsEmpty();                         //--判断是否为空
        void IsMemberOf(int e);                 //--判断是否在该集合内
        int Add(int e);                         //--增加一个整数
        int Sub(int e);                         //--删除一个整数
        bool IsEqual(intSet& A,intSet& B);      //--判断两个集合是否相等
        void Intersection(intSet& A,intSet& B); //--求两个集合交集
        void Merge(intSet& A,intSet& B);        //--求两个集合并集
        void Print()
        {
            int i=0;
            while(element[i]!=0)
            {
                if(i!=0&&i%10==0)
                {
                    std::cout<<'\n';
                }
                std::cout<<element[i]<<'\t';
                i++;
            }
        }
    private:
        int element[100];
        int EndPosition;
};
intSet::intSet():EndPosition(-1)
{
    element = new int[100]();
    //memset(element,0,sizeof(int)*100);
}
intSet::intSet(const intSet& A)
{
    element=new int[100];
    int i=0;
    while(A.element[i]!=0)
    {
        element[i]=A.element[i];
        i++;
    }
    EndPosition=i-1;
}
void intSet::Empty()
{
    memset(element,0,sizeof(int)*100);
}
void intSet::IsEmpty()
{
    if(element[0]==0) std::cout<<"Is Empty!"<<std::endl;
    else std::cout<<"Is not Empty!"<<std::endl;
}
void intSet::IsMemberOf(int e)
{
    int i=0;
    while(element[i]!=0)
    {
        if(element[i]!=e) continue;
        else
        {
            std::cout<<"In your intset, the No."<<i+1<<" is the element "<<e<<'.'<<std::endl;
            break;
        }
        i++;
    }
}
int intSet::Add(int e)
{
    int i=0;
    while(element[i]!=0)
    {
        if(element[i]==e)
        {
            EndPosition++;
            element[EndPosition]=e;
        }
        i++;
    }
    if(EndPosition<99)
    {
        EndPosition++;
        element[EndPosition]=e;
    }
    else std::cout<<"the number of your intset now is  "<<EndPosition+1
        <<". you cannot add element."<<std::endl;
}
int intSet::Sub(int e)
{
    int i=0;
    while(element[i]!=0)
    {
        if(element[i]!=e) continue;
        else
        {
            for(int j=i;i<EndPosition;j++) element[j]=element[j+1];
        }
        i++;
    }
}


