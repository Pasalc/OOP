#ifndef TALLOCATIONITEM_H
#define TALLOCATIONITEM_H


class TAllocationItem
{
    public:
        TAllocationItem():mem(nullptr){};
        void operator=(char* usedMem){*mem=usedMem;};
        void operator=(size_t count) {mem=(void**)malloc(sizeof(void*)*count);};
        void* GetMem(){return *mem;};
        virtual ~TAllocationItem(){free(mem);};
    private:
        void** mem;
};

#endif // TALLOCATIONITEM_H
