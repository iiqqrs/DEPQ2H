#include <iostream>
#include <cstdlib>
using namespace std;

struct int_arr{
    int value;
    int index;
    int_arr(int v, int i){
        value = v;
        index = i;
    }
};

class max_heap{
    private:
        //int *myarray;
        int_arr* myarray;
        int size;
        int LeftChild(int i){
            return 2*i + 1;
        }
        int RightChild(int i){
            return 2*i + 2;
        }
        int Parent(int i){
            return (i-1)/2;
        }
        void BubbleUp(int i){
            int temp = i;
            while (temp > 0 && myarray[Parent(temp)].value < myarray[temp].value){
                swap(myarray[temp], myarray[Parent(temp)]);
                temp = Parent(temp);
            }
        }
        void BubbleDown(int i){
            int left_i = LeftChild(i);
            int right_i = RightChild(i);
            
            //Find Largest of the three
            int largest = i;
            if (left_i < num_items && myarray[left_i].value > myarray[i].value){
                largest = left_i;
            }
            if (right_i < num_items && myarray[right_i].value > myarray[largest].value){
                largest = right_i;
            }
            
            //If not the start index then swap and recurse
            if (largest != i){
                swap(myarray[i], myarray[largest]);
                BubbleDown(largest);
            }
        }
    public:
        int num_items;
        max_heap(){
            size = 100;
            num_items = 0;
            myarray = (int_arr*)malloc(size*sizeof(int_arr));
            //myarray = new int[size];
        }
        ~max_heap(){
            for(int i = 0; i < num_items; ++i){
                //cout << myarray[i].value << endl;
            }//one last display
            delete[] myarray;
        }
        void Insert(int x){
            int_arr* i_arr = new int_arr(x, num_items);
            myarray[num_items] = *i_arr;
            BubbleUp(num_items);
            num_items++;
        }
        int Max(){
            return myarray[0].value;
        }
        int Pop(){
            num_items--;
            int response = myarray[0].value;
            swap(myarray[0], myarray[num_items]);
            BubbleDown(0);
            return response;
        }
        bool empty(){
            if(num_items == 0){
                return true;
            }
            return false;
        }        
};

class min_heap{
    private:
        int_arr *myarray;
        int size;
        int LeftChild(int i){
            return 2*i + 1;
        }
        int RightChild(int i){
            return 2*i + 2;
        }
        int Parent(int i){
            return (i-1)/2;
        }
        void BubbleUp(int i){
            int temp = i;
            while (temp > 0 && myarray[Parent(temp)].value > myarray[temp].value){
                swap(myarray[temp], myarray[Parent(temp)]);
                temp = Parent(temp);
            }
        }
        void BubbleDown(int i){
            int left_i = LeftChild(i);
            int right_i = RightChild(i);
            
            //Find Largest of the three
            int largest = i;
            if (left_i < num_items && myarray[left_i].value < myarray[i].value){
                largest = left_i;
            }
            if (right_i < num_items && myarray[right_i].value < myarray[largest].value){
                largest = right_i;
            }
            
            //If not the start index then swap and recurse
            if (largest != i){
                swap(myarray[i], myarray[largest]);
                BubbleDown(largest);
            }
        }
    public:
        int num_items;
        min_heap(){
            size = 100;
            num_items = 0;
            myarray = (int_arr*)malloc(size*sizeof(int_arr));
            //myarray = new int[size];
        }
        ~min_heap(){
            for(int i = 0; i < num_items; ++i){
                //cout << myarray[i].value << endl;
            }//one last display
            delete[] myarray;
        }
        void Insert(int x){
            int_arr* i_arr = new int_arr(x, num_items);
            myarray[num_items] = *i_arr;
            BubbleUp(num_items);
            num_items++;
        }
        int Max(){
            return myarray[0].value;
        }
        int Pop(){
            num_items--;
            int response = myarray[0].value;
            swap(myarray[0], myarray[num_items]);
            BubbleDown(0);
            return response;
        }
        bool empty(){
            if(num_items == 0){
                return true;
            }
            return false;
        }
};

class DEPQ{
    private:
        min_heap minh;
        max_heap maxh;
        int min_count;
        int max_count;
    public:
        DEPQ(){
        }
        void insert(int x){
            maxh.Insert(x);
            minh.Insert(x);
            max_count++;
            min_count++;
        }
        int pop_max(){
            if(maxh.empty() && minh.empty()){
                return 0;
            }else{
                int max = maxh.Pop();
                max_count--;
                return max;
            }
        }
        int pop_min(){
            if(maxh.empty() && minh.empty()){
                return 0;
            }else{
                int min = minh.Pop();
                min_count--;
                return min;
            }
        }
};