#ifndef BINARY_HEAP_H_
#define BINARY_HEAP_H_

using namespace std;

const int MAX_SIZE = 100000; //the maximum amount of elements our heap should have.

template <typename Object>
class Heap
{
public:
   Heap(){
      elements = 0;
   };
   void insert(Object* item){// Add the object pointer item to the heap
	if (elements >= MAX_SIZE){
		cout << "Heap is full; can't insert "<< endl;
            	return;
            // FILL IN THE REST
        } else if (elements == 0) {
            elements++;
            array[0] = item;
        } else {
            elements++;
            int i = elements - 1;
            array[i] = item;
            array[i]->position = i;
            upHeap(i);
        }
	return;
   };  	
   Object* remove_min(){
      if (elements ==0){
		   cout << "empty heap error, can't delete"<<endl;
	   }
        if (elements == 1) {
            elements--;
            return array[0];
        }
        Object* temp = array[0];
        // FILL IN THE REST
        swap(array, 0, elements - 1);
        array[elements - 1]->position = -1;
        elements--;
        downHeap(0);
      return temp;
   };       // Remove the smallest element in the heap & restructure heap
   
   void decreaseKey(int pos, int val)// Decreases Key in pos to val
   {
        if (pos >= elements) {
            cout << "Out of range of heap " << pos << " elements " << elements << endl;
            return;
        }
        array[pos]->key = val;
        upHeap(pos);
        return;   
   }; 
   

   bool IsEmpty() const {  return (elements <= 0);};
   bool IsFull() const {return (elements >=MAX_SIZE );};
   int count() const {return elements;};
   Object* value(int pos) const{ //return a pointer to an object in heap position
	   if (pos >= elements){
		   cout << "Out of range of heap " << pos << "elements " << elements << endl;
	   }
      return (array[pos]);
   };  
protected:
   Object* array[MAX_SIZE];
   int elements;       //  how many elements are in the heap
private:
   void downHeap(int pos){// starting with element in position pos, sift it down the heap 
                       // until it is in final min-heap position
//      Object* item = array[pos];

	int lc = 2 * pos + 1;
        int rc = 2 * pos + 2;
        if (lc >= elements) {
            return;
        }
        int small = lc;
        if (rc >= elements) {
            small = lc;
        } else {
            small = array[lc]->key < array[rc]->key ? lc : rc;
        }
        while (array[pos]->key > array[small]->key) {
            swap(array, pos, small);
            pos = small;
            lc = 2 * pos + 1;
            rc = 2 * pos + 2;
            if (lc >= elements) {
                return;
            } else if (rc >= elements) {
                small = lc;
            } else {
                small = array[lc]->key < array[rc]->key ? lc : rc;
            }
        }
        return;
   }; 
   void swap(Object* array[], int a, int b){
        Object* tmp = array[a];
        array[a] = array[b];
        array[a]-> position = a;
        array[b] = tmp;
        array[b]->position = b;
   }
   void upHeap(int new_pos){// starting with element in position int, sift it up the heap
                       // until it is in final min-heap position
  //    Object* item = array[new_pos];

      int pos = new_pos;
        int p = (new_pos - 1) / 2;
        while (pos != 0 && array[pos]->key < array[p]->key) {
            swap(array, pos, p);
            pos = p;
            p = (p - 1) / 2;
        }
        return;  
   };   
};
#endif
