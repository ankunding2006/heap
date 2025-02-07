        #include "binheap.h"
        #include "fatal.h"
        #include <stdlib.h>

        
/* START: fig6_0.txt */
        PriorityQueue
        Initialize( int MaxElements )
        {
            PriorityQueue H;

/* 1*/      if( MaxElements < MinPQSize )
/* 2*/          Error( "Priority queue size is too small" );

/* 3*/      H = malloc( sizeof( struct HeapStruct ) );
/* 4*/      if( H ==NULL )
/* 5*/          FatalError( "Out of space!!!" );

            /* Allocate the array plus one extra for sentinel */
/* 6*/      H->Elements = malloc( (size_t)( MaxElements + 1 )
                                    * sizeof( ElementType ) );
/* 7*/      if( H->Elements == NULL )
/* 8*/          FatalError( "Out of space!!!" );

/* 9*/      H->Capacity = MaxElements;
/*10*/      H->Size = 0;
/*11*/      H->Elements[ 0 ] = MinData;

/*12*/      return H;
        }
/* END */

        void
        MakeEmpty( PriorityQueue H )
        {
            H->Size = 0;
        }


        ElementType
        FindMin( PriorityQueue H )
        {
            if( !IsEmpty( H ) )
                return H->Elements[ 1 ];
            Error( "Priority Queue is Empty" );
            return H->Elements[ 0 ];
        }

        int
        IsEmpty( PriorityQueue H )
        {
            return H->Size == 0;
        }

        int
        IsFull( PriorityQueue H )
        {
            return H->Size == H->Capacity;
        }

        void
        Destroy( PriorityQueue H )
        {
            free( H->Elements );
            free( H );
        }

        #if 0
/* START: fig6_14.txt */
        for( i = N / 2; i > 0; i-- )
            PercolateDown( i );
/* END */
        #endif


        void Insert( ElementType X, PriorityQueue H )
        {
            int i;
            if (IsFull(H))
            {
                /* code */
                printf("the heap is full,sorry");
            }

            else
            {
                H->Size++;
                for(i=H->Size;H->Elements[i/2]>X;i/=2)
                {
                    H->Elements[i]=H->Elements[i/2];
                }
                H->Elements[i]=X;
            }
            
        }

    void PrintHeap(PriorityQueue H) {
        if (IsEmpty(H)) {
            printf("Heap is empty\n");
            return;
        }

        // 计算最大值，确保输出宽度
        int maxVal = H->Elements[1];
        for (int i = 2; i <= H->Size; i++) {
            if (H->Elements[i] > maxVal) {
                maxVal = H->Elements[i];
            }
        }
        int fieldWidth = 0;
        int temp = (maxVal < 0) ? -maxVal : maxVal;
        while (temp > 0) {
            fieldWidth++;
            temp /= 10;
        }
        if (fieldWidth == 0) {
            fieldWidth = 1;
        }
        
        // 计算堆高
        int height = 0;
        int nodes = H->Size;
        while (nodes > 0) {
            height++;
            nodes >>= 1; 
        }
        
        // 准备打印
        int lastLevelNodes = 1 << (height - 1);
        int totalWidth = lastLevelNodes * (fieldWidth + 2);
        int index = 1;
        
        for (int level = 0; level < height; level++) {
            int count = 1 << level;
            char line[totalWidth + 1];
            for (int i = 0; i < totalWidth; i++) {
                line[i] = ' ';
            }
            line[totalWidth] = '\0';
            
            int gap = totalWidth / (count + 1);
            for (int i = 0; i < count && index <= H->Size; i++) {
                int pos = gap * (i + 1) - fieldWidth / 2;
                if (pos < 0) pos = 0;
                char valStr[32];
                snprintf(valStr, sizeof(valStr), "%*d", fieldWidth, H->Elements[index++]);
                for (int j = 0; j < fieldWidth && (pos + j) < totalWidth; j++) {
                    line[pos + j] = valStr[j];
                }
            }
            printf("%s\n", line);
        }
    }





ElementType
DeleteMin( PriorityQueue H )
{
    int i;
    int LastElement=H->Elements[H->Size];
    int MinElement=H->Elements[1];
    H->Size--;
    for(i=1;i*2<=H->Size;i*=2)
    {
        int child=2*i;
        if (child != H->Size && H->Elements[child]>H->Elements[child+1])
        {
            /* code */
            child++;
        }
        
        if (LastElement>=H->Elements[child])
        {
            /* code */
            H->Elements[i]=H->Elements[child];
        }

        else
        {
            break;
        }
    }

    H->Elements[i]=LastElement;
    return MinElement;
}        



















int main(void)
{
    PriorityQueue H=Initialize(200);
    for (int i = 0; i < 30; i++)
    {
        /* code */
        Insert(i,H);
    }
    PrintHeap(H);

    DeleteMin(H);

    PrintHeap(H);
}