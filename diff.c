#include <stdlib.h>

/*Return 0 if ds1 and ds2 are clones,
 * else return -1*/
int
diff (void *root1,    /*pointer to Data structure 1*/
      void *root2,    /*pointer to data structure 2*/
      void *(*iterator(void *)), /*Iterator function callback*/
      int comparator(void *, void *),
      void *(*get_app_data(void *))){  /*Comparison function callback*/

    //as long as there is data in both DS
    void* data2 = NULL, *data1 = NULL;
    while(root1 && root2){
        data1 = get_app_data(root1);
        data2 = get_app_data(root2);
        //compare data1 and data2.
        if(data1 && data2){
            if(comparator(data1,data2))
                return -1; 
        } 
        else{
          return 0;
        }
        //keep iterate
        root1 = iterator(root1);
        root2 = iterator(root2);
    }
    //DS arent clones
      return 0;
}
