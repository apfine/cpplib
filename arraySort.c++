#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Array{
    private:
        int r , t , size  ;
        vector <int> array ,a   ;
        
    public:
        Array(const int& s = 1):size(s) , array(size) , a(size) , t(0){
            cout<<"\nPlease enter the size of the array : ";
            cin>>size;
            array.resize(size);
            cout<<"\nPlease enter the values of the array : ";
            for(int i = 0 ; i< size ; i++){
                cin>>array[i];
            }
            a.resize(size);
            a = array;
            r = size;
            t = 0 ;
        }; //The constructor of the class


        void copy(vector <int> ab){
            for(auto i : ab){
                array.push_back(i);
            }
        }
       
        void print(){
            cout<<endl<<"The array is : ";
            for(int i = 0 ; i < size ; i++){
                cout<<" "<<array[i];
            }
            cout<<endl;
        }

        void BubbleSort(){
            //In this method what we are doing is that we are trying to take the i+1 th largest element to correct place in the i th round
            
            if(r==1 || r==0){
                cout<<"\nBubble Sort: ";
                print();
                refresh();
                r = size;
                return;
            }
            for(int j = 0 ; j<r-1 ; j++){
                if(array[j]>array[j+1]){
                    swap(array[j] , array[j+1]);
                }
            }
            r--;
            BubbleSort();
        }

        void SelectionSort(){  
            if(t==size){
                cout<<"\nSelection Sort : ";
                print();
                refresh();
                r = size;
                return;
            }
            int min = array[t];
            for(int i = t; i< size ; i++){
                if(array[i]<min){
                    min = array[i];
                    if(min!=array[t]){
                        swap(array[t] , array[i]);
                    }
                    
                }
            }
            t++;
            SelectionSort();

        }

        void refresh(){
            array = a;
        }


    private:
        int partitionQuick(int s , int e){                             //One of the highest learning curve
            int pivot = array[s] ;
            int i = s+1;
            int j = e;
            while(i<=j){
                while(i<=j && array[i]<pivot) i++;
                while(i<=j &&array[j]>pivot)j--;

            if(i<j){
                swap(array[i] , array[j]);
            } 
            }
            swap(array[s] ,array[j]);
            return j ;                                    //Here it after partitioning returns a pivot point on which whole of the array is evaluated.
        }
        
        void quick(int s, int e) {
            if (s >= e) {
                return; // Base case: single-element or empty partition
            }

            int pivot = partitionQuick(s, e); // Partition the array

            quick(s, pivot - 1); // Sort left partition
            quick(pivot + 1, e); // Sort right partition
        }
        
        vector<int> merge(int s1, int e1, int s2, int e2) {
           vector<int> merged;
           int i = s1, j = s2;

           // Merge elements from both halves
           while (i <= e1 && j <= e2) {
               if (array[i] <= array[j]) {
                   merged.push_back(array[i++]);
               } else {
                   merged.push_back(array[j++]);
               }
           }

           // Add remaining elements from the left half
           while (i <= e1) {
               merged.push_back(array[i++]);
           }

           // Add remaining elements from the right half
           while (j <= e2) {
               merged.push_back(array[j++]);
           }

           // Copy merged elements back to the original array
           for (int k = 0; k < merged.size(); ++k) {
               array[s1 + k] = merged[k];                            //This is the step which is mistaken by many people as intermediate arrays are to be merged
           }

           return merged;
        }       
        
        void split(int s, int e) {
            // Base case: if the segment has one or zero elements, return
            if (s >= e) {
                return;
            }

            int mid = s + (e - s) / 2;  // Avoid overflow
            split(s, mid);             // Sort the left half
            split(mid + 1, e);         // Sort the right half
            merge(s, mid, mid + 1, e); // Merge the two halves
        }       

    


    public:
        void QuickSort(){ //One of the highest learning curve
            int s = 0 ;
            int e = size-1 ;
            quick(s , e );
  
            cout<<"\nQuick Sort : ";
            print();
            refresh();
        }

        void MergeSort() {  //One of the highest learning curve
            int s = 0;       //It is the algo which can be efficiently written only with recursion
            int e = size - 1;
            split(s, e);
            cout << "\nMerge Sort: ";
            print();
            refresh();
        }

           
};

int main(){
    Array a;
    //Taking the string input off the user
    unordered_map<string , void(Array::*)()>functions;
    functions["print"] = &Array::print;
    functions["BubbleSort"] = &Array::BubbleSort;
    functions["SelectionSort"] = &Array::SelectionSort;
    functions["MergeSort"] = &Array::MergeSort;
    functions["QuickSort"] = &Array::QuickSort;

    string input;
    while (true){
        cout<<"\nPlease enter the sorting algorithm : ";
        cin>>input;

        if(input =="exit"){
            break;
        }
        auto it = functions.find(input);
        if(it!=functions.end()){
            //Call the function using the member pointer
            (a.*(it->second))();
        }
        else{
            cout<<"\nThe function name is invalid .";
        }
    }
    
}