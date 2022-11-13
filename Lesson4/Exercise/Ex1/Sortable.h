namespace SortableSpace{
    template <typename T>
    class Sortable{
        private:
            /*swap between two T elements */
            void swap(T* a, T* b);
            T* array;
            int size;
        
        public:
            /*Construct a new Sortable<T>:: Sortable object. It set the size and the array*/
            Sortable(T arr[], int s);
            /*Using bubble sort, this method sort the array saved*/
            void bubbleSort();
            /*return the array saved*/
            T* getArray();
            /*return the array's size*/
            int getSize();
            /**return the max number into the array */
            T getMax();
            /*return a bollean value that check if the Sortable obj is sorted*/
            bool isSorted();
            /*print the array of the obj a*/
            void printSortable();     
    };
}
