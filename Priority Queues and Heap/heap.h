#include<bits/stdc++.h>

class heap{
  private:
    //INFO ABOUT HEAP
    int *heap_arr;
    int count;
    int capacity;
    //int heap_type;

  public:
    heap(int cap) {
      cout << "Creating Object" <<endl;
      count = 0;
      capacity = cap;
      //heap_type = type;
      heap_arr = (int *)calloc(sizeof(int), capacity); 
    }

    ~heap() {
      cout << "Destroying Object" << endl;
      free(heap_arr);
    }

    int leftChild(int index) {
      if((2*index)+1 < count)
        return 2*index+1;
      else
        return -1;
    }

    int rightChild(int index) {
      if((2*index)+2 < count)
        return 2*index+2;
      else
        return -1;
    }

    int getMax() {
      if(count == 0)
        return -1;
      else
        return heap_arr[0];
    }

    void heapify(int index) {
      //max as index value
      int max = index; 
      // if left exists and left is greater
      int l = leftChild(index);
      if(l != -1 && heap_arr[l] > heap_arr[max])
      //max is left
        max = l;
      //if right exists and right is greater
      int r = rightChild(index);
      if(l != -1 && heap_arr[l] > heap_arr[max])
      //max is right
        max = r;
      //max
      if(max != index) {
        swap(heap_arr[index], heap_arr[max]);
      }
      heapify(max);
    }

    void resize() {
      cout << "OPS : Resizing the Heap" << endl;
      int *arr_old = heap_arr;
      heap_arr = (int *)calloc(sizeof(int), capacity*2);

      for(int i=0; i<capacity; i++)
        heap_arr[i] = arr_old[i];

      capacity *= 2;
      free(arr_old);
    }

    void insert(int value){
      cout << "OPS : Inserting " << value << endl;
      if(count == capacity) {
        cout << "ERROR : Heap Full :( " << endl;
        resize();
      }
      count++;
      int i = count -1;
      //Percolate up process
      //    compare data at i-new and (i-1)/2-parent
      //     if data at parent > data inserted set child as data of parent 
      //      keep comparing with (i-1)/2 further parents

      while( i>0 && value>heap_arr[(i-1)/2] ) {
        // uncomment below to see changes as they happen
        //cout << "value " << heap_arr[i] << " is changed to value " << heap_arr[(i-1)/2] << endl;
        heap_arr[i] = heap_arr[(i-1)/2];
        i = (i-1)/2;
      }
      heap_arr[i] = value;
    }

    void showheap() {
      for(int i=0; i<count; i++)
        cout << heap_arr[i] << " ";
    }

};