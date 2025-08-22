#include<iostream>
using namespace std;
#define ARRAY_OVERFLOW 1
#define INVALID_INDEX 2
class DynArray
{
    private:
        int capacity;
        int last_index;
        int *arr;
    protected:
    void doubleArray(){
            capacity=2*(capacity+1);
            
            int *temp=new int[capacity];
        
            for(auto i=0;i<last_index;i++)
            {
                temp[i]=arr[i];
            }
            arr=temp;
            delete []temp;
            capacity--;

            

            
        }
        void halfArray(){
            capacity=(capacity+1)/2;
            arr=(int*)realloc(arr,capacity);
            capacity--;
        }
    public:
        DynArray(int size){
            if(size<=0)
                size=10;
            arr=new int[size];
            last_index=-1;
            capacity=size-1;
        }
        DynArray(DynArray &a){
            capacity=a.capacity;
            last_index=a.last_index;
            arr=new int[capacity];
            for(int i=0;i<last_index;i++)
            {
                arr[i]=a.arr[i];
            }
        }
        DynArray& operator=(DynArray &a){
            delete []arr;
            capacity=a.capacity;
            last_index=a.last_index;
            
            arr=new int[capacity];
            for(int i=0;i<last_index;i++)
            {
                arr[i]=a.arr[i];
            }
            return *this;
        }
        bool isEmpty(){
            return last_index==-1;
        }
        void append_element(int element)
        {
            if(isFull())
                doubleArray();
            arr[last_index+1]=element;
            last_index++;
            
            
        }
        int check_capacity(){
            return capacity+1;
        }
        void insert_element(int index,int element)
        {
            
                if(index<0 || index>last_index+1)
                    throw INVALID_INDEX;
                if(isFull())
                    doubleArray();
                for(int i=last_index+1;i>index;i--)
                    {
                        arr[i]=arr[i-1];
                    }
                    arr[index]=element;
                    last_index++; 
            }
           
        
        void edit_element(int element,int index)
        {
            if(index<0 || index>last_index+1)
                    throw INVALID_INDEX;
            arr[index]=element;
            
        }
        void delete_element(int index){
            if(index<0 || index>last_index+1)
                    throw INVALID_INDEX;
            for(int i=index;i<last_index;i++){
                    arr[i]=arr[i+1];
                }
            last_index=last_index-1;
            if(capacity<=2*last_index)
            halfArray();
        }
        bool isFull(){
            return last_index==capacity;
        }
        int get_element(int index){
            if(index<0 || index>last_index+1)
                    throw INVALID_INDEX;
            return arr[index];
            

        }
        void count_element(){
            cout<<"number of element is "<<(last_index+1)<<endl;
        }
        ~DynArray(){
            delete []arr;
            
        }
        int find_element(int element){
            for(int i=0;i<=last_index;i++){
                if(arr[i]==element)
                return 1;
            }
            return -1;
        }


};
int main(){
    DynArray a1(4);
    a1.append_element(1);
    a1.append_element(2);
    a1.append_element(3);
    a1.append_element(4);
    a1.append_element(5);
    cout<<a1.check_capacity();
    DynArray a2(2);
    a2=a1;
    a2.count_element();
    a1.~DynArray();
    a2.find_element(2);
    


}