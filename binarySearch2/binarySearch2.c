#include<stdio.h>
int main(){

    int a[5]={10,20,30,40,50};
    int lower = 0;
    int upper = sizeof(a)-1;
    int found,mid, item;

    printf("Enter the searching item: ");
    scanf("%d",&item);
    while(lower <= upper)
    {
            mid = (lower + upper)/2;
            if(a[mid] == item){
                found=1;
                break;
            }
            if(a[mid] < item)
            {
                lower = mid +1;
            }
            else
            {
                upper = mid - 1;
            }
    }

    if(found == 1)
    {
        printf("Item found with location = %d",mid);
    }
    else
    {
        printf("Item not found.");
    }


return 0;
}
